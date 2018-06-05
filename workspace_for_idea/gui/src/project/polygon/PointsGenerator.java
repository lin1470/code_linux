package project.polygon;

import java.util.ArrayList;

public class PointsGenerator {
    private double center_x;
    private double center_y;
    private double verticalLineLen;  // 多边形中心点与多边形边的距离
    private int numOfPoint;       // 点的数目
    private ArrayList<Double> xs;
    private ArrayList<Double> ys;

    public PointsGenerator(){
        this.xs = new ArrayList<>();
        this.ys = new ArrayList<>();
        this.center_x = 0.0;
        this.center_y = 0.0;
    }

    public PointsGenerator(double center_x, double center_y, double verticalLineLen, int numOfPoint){
        this.xs = new ArrayList<>();
        this.ys = new ArrayList<>();
        this.center_x = center_x;
        this.center_y = center_y;
        this.verticalLineLen = verticalLineLen;
        this.numOfPoint = numOfPoint;
    }

    public void setCenter(double center_x, double center_y){
        this.center_x = center_x;
        this.center_y = center_y;
    }

    public void setVerticalLineLen(double verticalLineLen){
        this.verticalLineLen = verticalLineLen;
    }

    public void setNumOfPoint(int numOfPoint){
        this.numOfPoint = numOfPoint;
    }

    public ArrayList<Double> getXs(){

        return this.xs;
    }

    public ArrayList<Double> getYs(){

        return this.ys;
    }


    public void genPoints(){
        //当numOfPoint=1,唯一的生成点的坐标就是中心点的坐标
        //当numOfPoint=2,两点与中心点水平，两点距离中心点都为verticalLineLen/2
        //当numOfPoint>=3,根据（中心点、verticalLineLen、夹角)求出base_point, 由base_point旋转若干角度陆续生成其他点
        xs.clear();
        ys.clear();
        if(this.numOfPoint==1){
            xs.add(center_x);
            ys.add(center_y);
        }
        else if(this.numOfPoint==2){
            // 左点
            xs.add(center_x-verticalLineLen/2);
            ys.add(center_y);
            // 右点
            xs.add(center_x+verticalLineLen/2);
            ys.add(center_y);
        }
        else{
            //计算多边形上的第一个点作为base_point，利用base_point计算其余点坐标
            double base_x = center_x + verticalLineLen * Math.tan(Math.PI/numOfPoint);
            double base_y = center_y + verticalLineLen;
            xs.add(base_x);
            ys.add(base_y);
            //利用base_point旋转beta*i角度，循环获取下一个点坐标
            double beta = 2 * Math.PI / numOfPoint;
            for(int i=1; i<numOfPoint; i++){
                nextPoint(base_x, base_y, beta*i);
            }
        }
    }

    private void nextPoint(double base_x, double base_y, double beta){
        double next_x = base_x * Math.cos(beta) - base_y * Math.sin(beta);
        double next_y = base_x * Math.sin(beta) - base_y * Math.cos(beta);
        this.xs.add(next_x);
        this.ys.add(next_y);
    }

    public static void main(String args[]){
        // 设计理念：给定充分条件（中心点坐标, 点数目，垂线长度)后，再发送生成指令genPoints，之后取回点坐标。
        // 条件（中心点坐标, 点数目，垂线长度）之一变动后，为避免歧义，需要重新发送genPoints，显式地生成点坐标。
        // usage 1 as followed
        System.out.println("usage 1");
        PointsGenerator pointsGenerator = new PointsGenerator();
        pointsGenerator.setCenter(100, 100);
        pointsGenerator.setVerticalLineLen(50);
        pointsGenerator.setNumOfPoint(5);
        pointsGenerator.genPoints();
        for(int i=0; i<pointsGenerator.getXs().size(); i++){
            System.out.println(pointsGenerator.getXs().get(i) + ", " + pointsGenerator.getYs().get(i));
        }
        // usage 2 as followed
        System.out.println("usage 2");
        PointsGenerator pointsGenerator1 = new PointsGenerator(100, 100, 50, 2);
        pointsGenerator1.genPoints();
        for(int i=0; i<pointsGenerator1.getXs().size(); i++){
            System.out.println(pointsGenerator1.getXs().get(i) + ", " + pointsGenerator1.getYs().get(i));
        }

    }
}

