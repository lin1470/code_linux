package project;
import java.awt.*;
public class MyCanvas extends Canvas{
    int number=4;
    int[] xPoints={100,300,100,300};
    int[] yPoints={50,50,300,300};
    public void paint(Graphics g) {
        g.drawPolygon(xPoints, yPoints, number);
    }
}
