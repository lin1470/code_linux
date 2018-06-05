package awt;
import java.awt.*;

public class PanelTest
{
	public static void main(String [] args)
	{
		Frame f = new Frame("test");
//		Panel p= new Panel();
		//向容器中添加frame窗口
        ScrollPane sp = new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);

		sp.add(new TextField(20));
//		sp.add(new Button("丹迪我"));
		f.add(sp);
		//设置窗口大小和位置
		f.setBounds(30,30,250,120);
		//将窗口显示出来
		f.setVisible(true);
	}
}