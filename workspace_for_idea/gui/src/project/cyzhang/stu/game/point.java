package project.cyzhang.stu.game;

import java.lang.Math;

/**
 * x,y为地址
 * num为序号
 * power为权重
 * s为随机数 ，num1到num2的范围，根据面积修改num2
 */
public class point {
    private int x;
    private int y;
    private int num ;
    private int num1=0,num2=1000;
    private int s,power;

    public  int sets(){
        s = (int)num1+(int)(Math.random()*(num2-num1));
        return s;
    }

    public int getPower() {
        return power;
    }

    public int setPower() {
        power = (sets() - 500) % 10;
        return power;
    }

    public int getX() {

        return x;
    }

    public void setX() {
        x = sets();
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY() {
        y = sets();
        this.y = y;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {

        this.num = num;
    }

    @Override
    public String toString() {
        return "point{" +
                "x=" + x +
                ", y=" + y +
                ", num=" + num +
                ", power=" + power +
                '}';
    }
}
