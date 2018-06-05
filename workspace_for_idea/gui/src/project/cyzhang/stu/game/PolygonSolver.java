package project.cyzhang.stu.game;

import java.util.ArrayList;

//
// Created by djwang on 2018/6/2.
//

public class PolygonSolver {
    private int maxGoal;  //最小值和最大值
    private ArrayList<Integer>   nums; //多边形节点数值
    private ArrayList<Character> opts; //多边形边上符号
    private ArrayList<Integer> maxRoute;  //使得游戏值最大的边的标号序列
    private ArrayList<String> maxPath;    //使得游戏值最大的等式字符串序列

    // 构造函数
    public PolygonSolver(){
        this.maxRoute = new ArrayList<>();
        this.maxPath = new ArrayList<>();
        this.nums = new ArrayList<>();
        this.opts = new ArrayList<>();
    }

    public PolygonSolver(ArrayList<Integer> nums, ArrayList<Character> opts){
        this.maxRoute = new ArrayList<>();
        this.maxPath = new ArrayList<>();
        this.nums = nums;
        this.opts = opts;
    }

    public PolygonSolver setNums(ArrayList<Integer> nums) {
        this.nums = nums;
        return this;
    }

    public PolygonSolver setOpts(ArrayList<Character> opts) {
        this.opts = opts;
        return this;
    }

    public int getMaxGoal() {
        return maxGoal;
    }

    public ArrayList<Integer> getMaxRoute() {
        return maxRoute;
    }

    public ArrayList<String> getMaxPath() {
        return maxPath;
    }


    public void findSolution(){
        int n = nums.size();
        int sv[][][] = new int[n][n+1][2]; // sv[i][j][0]保存着使得p(i,j)值最小的划分点s，经由s，p(i,j)分割为p(i,i+s)和p((i+s)%n, j-s)。sv即s value之意
        int sm[][][] = new int[n][n+1][2]; // sm[i][j][0]保存着能够使p(i,j)值最小的相关子链信息。sm[i][j][1]保存着能够使p(i,j)值最大的相关子链信息。=0表示下界+下界，=1表示下界+上界，=2表示上界+下界，=3表示上界+上界
        int dp[][][] = new int[n][n+1][2]; // dp[i][j][0]表示p(i,j)的最小值，dp[i][j][1]表示p(i,j)的最大值。 p(i,j)表示从顶点v[i]开始，长度为j(顶点总数为j)的链v[i],v[i+1]...v[i+j-1].
        
        for(int i=0; i<n; i++){
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1]= nums.get(i);                       // 当子链长度为1时，dp值即为当前唯一结点的值
            dp[i][2][0] = dp[i][2][1] = operation(nums.get(i), nums.get((i+1)%n), opts.get((i+1)%n)); // 当子链长度为2时，dp值为两个结点直接运算的结果
        }

        // 注意这个初始化，s=1是后面traceRoute递归调用结束的一个条件，不初始化会导致递归函数栈溢出
        for(int i=0; i<n; i++){
            for(int j=0; j<n+1; j++){
                for(int k=0; k<2; k++){
                    sv[i][j][k] = 1;
                }
            }
        }
        
        for(int j=3; j<=n; j++){
            for(int i=0; i<n; i++){
                for(int s=1; s<=j-1; s++){
                    int min_msg[] = minf(dp[i][s][0], dp[i][s][1], dp[(i+s)%n][j-s][0], dp[(i+s)%n][j-s][1], opts.get((i+s)%n));
                    int max_msg[] = maxf(dp[i][s][0], dp[i][s][1], dp[(i+s)%n][j-s][0], dp[(i+s)%n][j-s][1], opts.get((i+s)%n));
                    if(dp[i][j][0]>min_msg[0]){
                        dp[i][j][0] = min_msg[0];
                        sm[i][j][0] = min_msg[1];
                        sv[i][j][0] = s;
                    }
                    if(dp[i][j][1]<max_msg[0]){
                        dp[i][j][1] = max_msg[0];
                        sm[i][j][1] = max_msg[1];
                        sv[i][j][1] = s;
                    }
                }
            }
        }

        int i = 0;
        int g_max = dp[0][n][1];
        for(int b=1; b<n; b++){
            if (g_max<dp[b][n][1]){
                g_max = dp[b][n][1];
                i = b;
            }
        }

        int j = n;  // dp[i][j][b] b表示选取p(i,j)链的最大值（b=1）或者最小值（b=1）
        int b = 1;  // b=1表示最大值

        traceRoute(dp, sm, sv, i, j, b);  // dp[i][n][1]有n长度下的最大值， s = sm[i][n][1].sv(它的最后一次操作发生点在s，使得最大）

        // 返回当前多边形数据下的最低和最高分。
        this.maxGoal = g_max;
    }

    
    private void traceRoute(int dp[][][], int sm[][][], int sv[][][], int i, int j, int b){
        int n = this.nums.size();  // 居家必备常用变量，用于做模运算以回滚
        
        // sm中保存的是编码后的选择情况encodedSelect，因此将其解码为lselect(ls), rselect(rs)
        int encodedSelect = sm[i][j][b];  // select表示对于p(i,j)链，使得能获取最小值(b=0)或最大值(b=1)的选取策略。=0表示下界+下界，=1表示下界+上界，=2表示上界+下界，=3表示上界+上界
        int decodedSelect[] = translateSelect(encodedSelect);
        int ls = decodedSelect[0];
        int rs = decodedSelect[1];
        int s = sv[i][j][b];

        // 保存及打印路径
        this.maxRoute.add((i+s)%n); // 小小的一行，把路径就给保存下来了。
        saveFoumula(dp[i][j][b], dp[i][s][ls], dp[(i+s)%n][j-s][rs], opts.get((i+s)%n));

        // traceRoute右子链
        if(s==1 && j-s!=1){
            traceRoute(dp, sm, sv,(i+s)%n, j-s, rs);
        }
        // traceRoute左子链
        else if(s!=1 && j-s==1){
            traceRoute(dp, sm, sv, i, s, ls);
        }
        // 对左右子链traceRoute
        else if (s!=1 && j-s!=1){
            traceRoute(dp, sm, sv, i, s, ls);
            traceRoute(dp, sm, sv,(i+s)%n, j-s, rs);
        }
    }

    private int[] translateSelect(int select){
        int lselect = 0;  // 左子链选择
        int rselect = 0;  // 右子链选择
        switch(select){
            case 0:
                lselect = 0;
                rselect = 0;
                break;
            case 1:
                lselect = 0;
                rselect = 1;
                break;
            case 2:
                lselect = 1;
                rselect = 0;
                break;
            case 3:
                lselect = 1;
                rselect = 1;
                break;
        }
        return new int[]{lselect, rselect};
    }
    
    private void saveFoumula(int result, int operand1, int operand2, char operator){
        String str = String.format("%-6d = %6d %s %-6d", result, operand1, operator, operand2);
        this.maxPath.add(str);
    }


    private int[] minf(int a, int b, int c, int d, char op){
        int select = 0;  // 0--00--ac  1--01--ad  2--10--bc  3--11--bd
        int low = 0;
        if(op=='+'){
            low = a+c;
            select = 0;
        }
        if(op=='*'){
            low = a*c;
            if(low>a*d){
                low = a*d;
                select = 1;
            }
            if(low>b*c){
                low = b*c;
                select = 2;
            }
            if(low>b*d){
                low = b*d;
                select = 3;
            }
        }
        return new int[]{low, select};  // return msg;
    }

    private int[] maxf(int a, int b, int c, int d, char op){
        int select = 0;  // 0--00--ac  1--01--ad  2--10--bc  3--11--bd
        int upper = 0;
        if(op=='+'){
            upper = b+d;
            select = 3;
        }
        if(op=='*'){
            upper = a*c;
            if(upper<a*d){
                upper = a*d;
                select = 1;
            }
            if(upper<b*c){
                upper = b*c;
                select = 2;
            }
            if(upper<b*d){
                upper = b*d;
                select = 3;
            }
        }
        return new int[]{upper, select}; // return msg
    }

    private int operation(int operand1, int operand2, char op){
        int result = 0;
        if(op=='*'){
            result = operand1 * operand2;
        }
        if(op=='+'){
            result = operand1 + operand2;
        }
        return result;
    }

    public String toString(){
        StringBuilder stringBuilder = new StringBuilder();

        for(int i: this.nums){
            stringBuilder.append(String.format("%d ",i));
        }
        stringBuilder.append("\n");

        for(int i=0; i<this.opts.size(); i++){
            stringBuilder.append(String.format("第%d边上符号: %c\n", i, this.opts.get(i)));
        }

        stringBuilder.append("---------------------\n");
        stringBuilder.append(String.format("maxGoal:\n%d\n", maxGoal));

        stringBuilder.append("---------------------\n");
        stringBuilder.append("route: \n");
        for(int i=maxRoute.size()-1; i>=0; i--){
            stringBuilder.append(String.format("%d ", maxRoute.get(i)));
        }

        stringBuilder.append("\n---------------------\n");
        stringBuilder.append("path: \n");
        for(int i=maxPath.size()-1; i>=0; i--){
            stringBuilder.append(String.format("%s\n", maxPath.get(i)));
        }

        return stringBuilder.toString();
    }

//
//    public static void main(String args[]){
//        // usage as followed
//        GraphicGenerator graphicGenerator = new GraphicGenerator(5, -25, 25);
//        ArrayList<Integer> nums = graphicGenerator.getNums();
//        ArrayList<Character> opts = graphicGenerator.getOpts();
//
//        PolygonSolver polygonSolver = new PolygonSolver();
//        polygonSolver.setNums(nums).setOpts(opts); //
//        polygonSolver.findSolution();
//        System.out.println(polygonSolver.toString());
//    }
    
}
