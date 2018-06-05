package controller;


import java.util.ArrayList;

class PolyGameDp {

    /**
     * m[i][j] ��ʾ ��iΪ���,jΪ���ȵ���������ֵ k=0 ��ʾmin k=1��ʾmax
     */
    private long m[][][];
    private int n;  // n�������һ��Ԫ��

    //ע�������� op[0] v[0] op[1] v[1]
    // ������ v[0] op[0] v[1] op[1]
    private char op[];
    private long minf = Long.MAX_VALUE;
    private long maxf = Long.MIN_VALUE;

    private int finali = -1;
    private Node maxs[][];
    private Node mins[][];


    private int maxR;

    private class Node{
        int i;
        int j;
        int x;
        int y;
        Node(int i, int j, int x, int y){
            this.i = i;
            this.j = j;
            this.x = x;
            this.y = y;
        }
    }



    PolyGameDp(long value[], char op[]){
        n = op.length-1;
        this.op = op;
        m = new long[n+1][n+2][2];
        maxs = new Node[n+1][n+2];
        mins = new Node[n+1][n+2];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n+1;j++){
                m[i][j][0] = Integer.MAX_VALUE;
                m[i][j][1] = Integer.MIN_VALUE;
                maxs[i][j] = null;
                mins[i][j] = null;
            }
        }

        for(int i=0;i<=n;i++){
            m[i][1][0] = value[i];
            m[i][1][1] = value[i];
        }



    }

    /**
     * ������p(i,j)��ʾ,i�����,j�������ĳ���
     * @param i  ���������
     * @param s  �ָ�����i�ĳ���
     * @param j  �����ĳ���
     */
    private void minMax(int i,int s,int j){
        long e[] = new long[5];
        long a = m[i][s][0],
            b = m[i][s][1];
        int r = (i+s)%(n+1);    // r �������
        long c = m[r][j-s][0],   // �������ȼ�ȥ�ָ��ĳ���Ϊ�µ���������
            d = m[r][j-s][1];
        if(op[r]=='+'){
            minf = a+c;
            maxf = b+d;
        }else{
            e[1] = a*c; //СС
            e[2] = a*d; //С��
            e[3] = b*c; //��С
            e[4] = b*d; //���
            minf = e[1];
            maxf = e[1];
            for(int k=2;k<5;k++){
                if(minf>e[k]){
                    minf = e[k];
                }
                if(maxf<e[k]){
                    maxf = e[k];
                }
            }
        }
        maxR = r;
//        chi[i][j] = r;
//        print();
//        System.out.printf("minf=%d,maxf=%d\n",minf,maxf);
    }

    long getMaxValue(){
        for(int j=2;j<=n+1;j++){ //��������
            for(int i=0;i<=n;i++){ //�������
                for(int s=1;s<j;s++){ //�ָ���������
                    minMax(i,s,j);
                    if(m[i][j][0]>minf){
                        m[i][j][0] = minf;
                        mins[i][j] = new Node(i,s,maxR,j-s);
                    }
                    if(m[i][j][1]<maxf){
                        m[i][j][1] = maxf;
                        maxs[i][j] = new Node(i,s,maxR,j-s);
                    }
//                    System.out.println("----------------");
                }
            }
        }
        long temp = m[0][n+1][1];
        finali = 0;
        for(int i=1;i<=n;i++){
            if(temp<m[i][n+1][1]){
                temp = m[i][n+1][1];
                finali = i;
            }
        }
//        print();
//        System.out.println("max-----");
//        printRoute(maxs);
//        System.out.println("min-----");
//        printRoute(mins);
        return temp;
    }

    int[] getMaxSeq(){
        ArrayList<Integer> seq = new ArrayList<>();
        traceNode(seq,maxs,finali,n+1);

        int index = 0;
        for (int aSeq : seq) {
            if (aSeq != -1)
                index++;
            else
                break;
        }
        int reverse[] = new int[seq.size()];
        int k = index-1;
        for(int i=0;i<=k;i++){
            reverse[i] = seq.get(k-i);
        }
        return reverse;
    }


//    private void printNode(Node node){
//        int x1 = node.i;
//        int y1 = node.j;
//        int x2 = node.x;
//        int y2 = node.y;
//        System.out.println("("+x1+" "+y1+") ("+x2+","+y2+")");
//    }

    private long doOp(long x,char op,long y){
        if(op=='+')
            return x+y;
        else return x*y;
    }

    /**
     *
     * @param seq �������б�ŵ�����
     * @param i ��ʾ��ǰ�ڵ�ĺ�����
     * @param j ��ʾ��ǰ�ڵ��������
     */
    private void traceNode(ArrayList<Integer> seq,Node nodes[][],int i,int j){
        Node node = nodes[i][j];
        if(node==null)
            return;
        int x1 = node.i;
        int y1 = node.j;
        int x2 = node.x;
        int y2 = node.y;
        int conform = 0;
        if(nodes==maxs)
            conform = 1;
//        String msg = (conform==1)?"max":"min";
//        System.out.println("conform "+ msg);
        Node[][] other = (nodes==maxs)?mins:maxs;


//        printNode(node);
        if(y1+y2==2){   //���ǻ����ڵ�
//            System.out.print("���ǻ����ڵ�  ");
            seq.add(x2);  //�ڵ�2�Ĳ�����
//            System.out.println(op[x2]);
        }else if(y1>=2 && y2>=2) // ���Ǹ��Ͻڵ�
        {
//            System.out.print("���Ǹ��Ͻڵ�  ");
//            System.out.println(op[x2]);
            seq.add(x2);

            if(op[x2]=='+'){    //�ӷ�
                if(doOp(m[x1][y1][conform],op[x2],m[x2][y2][conform])==m[i][j][conform])
                    traceNode(seq, nodes,x1,y1);
                else traceNode(seq,other,x1,y1);
                if(doOp(m[x1][y1][conform],op[x2],m[x2][y2][conform])==m[i][j][conform])
                    traceNode(seq, nodes,x2,y2);
                else traceNode(seq,other,x2,y2);

            }else{  //�˷�
                int rank[][] = {{0,0},{0,1},{1,0},{1,1}};
                int index = 0;
                for(int k=0;k<rank.length;k++)
                {
                    if(doOp(m[x1][y1][rank[k][0]],op[x2],m[x2][y2][rank[k][1]])
                            ==m[i][j][conform]){
                        index = k;
                        break;
                    }
                }
                switch(index){
                    case 0:
                        traceNode(seq,mins,x1,y1);
                        traceNode(seq,mins,x2,y2);
                        break;
                    case 1:
                        traceNode(seq,mins,x1,y1);
                        traceNode(seq,maxs,x2,y2);
                        break;
                    case 2:
                        traceNode(seq,maxs,x1,y1);
                        traceNode(seq,mins,x2,y2);
                        break;
                    case 3:
                        traceNode(seq,maxs,x1,y1);
                        traceNode(seq,maxs,x2,y2);
                        break;
                }

            }
        }else{  //ֻ��һ���ڵ��Ǹ��Ͻڵ�
            if(y1==1)//�ڵ�1�ǻ����ڵ�
            {
//                System.out.print("1 �ǻ����ڵ�  ");
//                System.out.println(op[x2]);
                seq.add(x2);
                if(doOp(m[x1][y1][conform],op[x2],m[x2][y2][conform])==m[i][j][conform])
                    traceNode(seq, nodes,x2,y2);
                else traceNode(seq,other,x2,y2);
            }else{  //�ڵ�2�ǻ����ڵ�
//                System.out.print("2 �ǻ����ڵ�  ");
//                System.out.println(op[x2]);
                seq.add(x2);
                if(doOp(m[x1][y1][conform],op[x2],m[x2][y2][conform])==m[i][j][conform])
                    traceNode(seq, nodes,x1,y1);
                else traceNode(seq,other,x1,y1);
            }
        }
    }

//    private void print(){
//        System.out.print("\t");
//        for(int i=0;i<m[0].length;i++)
//            System.out.printf("%4d",i);
//        System.out.println();
//        for(int i = 0; i<m.length; i++) {
//            System.out.print(op[i]+" "+i+"\t");
//            for (int j = 0; j < m[i].length; j++) {
//                System.out.printf("%d/%d  ",m[i][j][0],m[i][j][1]);
//            }
//            System.out.println();
//        }
//    }
//
//    private void printRoute(Node[][] ns){
//        for (Node[] aChoose : ns) {
//            for (Node n : aChoose) {
//                if(n!=null)
//                    System.out.print(n.i+","+n.j+" op "+n.x+","+n.y+"\t");
//                else
//                {
//                    System.out.print(-1+","+-1+" op "+-1+","+-1+"\t");
//                }
//            }
//            System.out.println();
//        }
//    }


}
