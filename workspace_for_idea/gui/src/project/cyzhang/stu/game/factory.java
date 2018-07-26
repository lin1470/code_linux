package project.cyzhang.stu.game;
import java.util.*;


public class factory {


    public List<point> creatpointlist(int n) {
        List<point> pointlist = new ArrayList<>();


        for (int i = 0; i < n; i++) {
            point pp = new point();
            pp.sets();
            pp.setX();
            pp.setY();
            pp.setNum(i);
            pp.setPower();
            pointlist.add(pp);
        }
        return pointlist;
    }

    /**
     *
     * @param n
     * 根据点生成线
     * @return 一个list内容为line
     */

    public List<line> creatlinelist(List<point>  pointlist ,int n) {

        List<line> linelist = new ArrayList<>();

        pointlist.size();

        for (int i = 0; i < n-1; i++) {
            line line = new line();

            line.setStartpointx(pointlist.get(i).getX());
            line.setStartpointy(pointlist.get(i).getY());

            line.setNum(pointlist.get(i).getNum());
            line.setOps();

            //设置线的终点x和y

            line.setEndpointx(pointlist.get(i+1).getX());
            line.setEndpointy(pointlist.get(i+1).getY());
            linelist.add(line);
        }
        //最后一个越界，另外处理
        line line = new line();
        //设置线的起点x和y
        line.setStartpointx(pointlist.get(n-1).getX());
        line.setStartpointy(pointlist.get(n-1).getY());
        line.setNum(pointlist.get(n-1).getNum());

        //设置线的终点x和y
        line.setEndpointx(pointlist.get(0).getX());
        line.setEndpointy(pointlist.get(0).getY());

        linelist.add(line);




        return linelist;
    }


}
