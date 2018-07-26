import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
/**
 * 增加窗口 画线、矩形、椭圆、字符串
 * @author Lixiangjian
 *
 */
public class Draw extends Frame{
    //Image sun 代表所得到的图片路径
    Image sun =Toolkit.getDefaultToolkit().getImage("images/3.jpg");//这种方法写法不好，但最简单
    /**
     * paint画窗口时会自动被调用(non-Javadoc)
     * Graphics g 相当于一支笔
     * g.drawImage 画图像 ： 画sun图像，相对于窗口位置x=100,y=100,null始终为null就行了
     */
    public void paint(Graphics g){
        g.drawImage(sun, 100, 100, null);
        //画线
		g.drawLine(100, 100, 200, 200);
        g.setColor(Color.BLUE);
                //画矩形
                g.drawRect(50, 50, 100, 90);
        //画椭圆
        g.drawOval(50, 50, 100, 100);
        g.setColor(Color.yellow);
        //画字符串在窗口上
        g.drawString("Java自学时间开始", 50, 80);
    }

    void launchFrame(){
        //设置窗口大小
        setSize(300,300);
        //setLocation()是JFrame里面的方法，设置控件在窗体里初始化的位置
        setLocation(150, 150);
        //设置窗口背景颜色
//		setBackground(Color.blue);
        //设置窗口标题
        setTitle("李某某");
        //设置是否显示
        setVisible(true);
    }

    public static void main(String[] agrs){
        System.out.println("李某某Java练习");
        //在主函数中创建类并调用启动窗口
        new Draw().launchFrame();
    }
}