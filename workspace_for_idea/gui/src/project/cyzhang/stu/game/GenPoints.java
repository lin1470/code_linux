package project.cyzhang.stu.game;
import java.util.List;
import java.util.Vector;

public class GenPoints {
    private int nPolygon;
    private double center_x=0.0;
    private double center_y=0.0;
    public Vector<Double> xs;
    public Vector<Double> ys;
    public GenPoints(int nPolygon,int len){
        xs = new Vector<>();
        ys = new Vector<>();
        if(nPolygon==2)
        {
            xs.add((double)len);
            ys.add(0.0);
            xs.add((double)(-len));
            ys.add(0.0);
        }
        else if(nPolygon==1)
        {
            xs.add(0.0);
            ys.add(0.0);
        }
        else{
            double first_x = center_x + len * Math.tan(2*Math.PI/nPolygon/2);
            double first_y = center_y + len;
            xs.add(first_x);
            ys.add(first_y);

            double alpha = Math.PI/2 - Math.PI/nPolygon;
            double beta = 2*Math.PI/nPolygon;
            for(int i=1; i<nPolygon; i++){
                genPoint(first_x, first_y, alpha, beta*i);
            }
        }

    }

    public void genPoint(double x, double y,double alpha, double beta){
        double s = x*Math.cos(beta) - y*Math.sin(beta);
        double t = (x*Math.sin(beta) + y*Math.cos(beta));
        xs.add(s);
        ys.add(t);
    }
    public void tranformByCenter(double cx,double cy){
        for(int i =0;i<xs.size();i++)
        {
            xs.set(i,cx+xs.get(i));
            ys.set(i,cy-ys.get(i));
        }

    }

    public static void main(String args[]){
        GenPoints genpoints = new GenPoints(1, 50);
        genpoints.tranformByCenter(200,200);
        List<Double> xs = genpoints.xs;
        List<Double> ys = genpoints.ys;
        for(int i=0; i<xs.size(); i++){
            System.out.println(xs.get(i)+", "+ys.get(i));
        }

    }
}