package project.cyzhang.stu.game;

public class line {

    private int startpointx;
    private int startpointy;

    private int endpointx;
    private int endpointy;

    private int num,ops;
    int numrandom = 10,s;

    public  int sets(){
        s = (int)(Math.random()*(numrandom) - 5);
        return s;
    }

    public int getOps() {
        return ops;
    }

    /**
     * 约定如果ops = 1 ，则为*
     *     如果ops = 0 ，则为+
     */
    public void setOps() {
        if (sets() > 0){
            this.ops = 1;
        }
        else
            this.ops = 0;

    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    /**
     * startpoint 为起点
     * endpoint 为终点
     */

    public int getStartpointx() {

        return startpointx;
    }

    public void setStartpointx(int startpointx) {

        this.startpointx = startpointx;
    }

    public int getStartpointy() {

        return startpointy;
    }

    public void setStartpointy(int startpointy) {

        this.startpointy = startpointy;
    }

    public int getEndpointx() {

        return endpointx;
    }

    public void setEndpointx(int endpointx) {

        this.endpointx = endpointx;
    }

    public int getEndpointy() {

        return endpointy;
    }

    public void setEndpointy(int endpointy) {

        this.endpointy = endpointy;
    }

    @Override
    public String toString() {
        return "line{" +
                "startpointx=" + startpointx +
                ", startpointy=" + startpointy +
                ", endpointx=" + endpointx +
                ", endpointy=" + endpointy +
                ", num=" + num +
                ", ops=" + ops +
                '}';
    }
}
