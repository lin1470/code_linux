package awt.awt11_7;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
/**
 * Description:
 * <br/>��վ: <a href="http://www.crazyit.org">���Java����</a> 
 * <br/>Copyright (C), 2001-2012, Yeeku.H.Lee
 * <br/>This program is protected by copyright laws.
 * <br/>Program Name:
 * <br/>Date:
 * @author Yeeku.H.Lee kongyeeku@163.com
 * @version 1.0
 */
public class SimpleDraw
{
	private final String RECT_SHAPE = "rect";
	private final String OVAL_SHAPE = "oval";
	private Frame f = new Frame("tst");
	private Button rect = new Button("rectangle");
	private Button oval = new Button("circle");
	private MyCanvas drawArea = new MyCanvas();
	//用于保存需要回执什么图形的变量
	private String shape = "";
	public void init()
	{
		Panel p = new Panel();
		rect.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
			    //设置shape变量为rect_shape
				shape = RECT_SHAPE;
				//重画mycanvas对象,即调用它的repait方法
				drawArea.repaint();
			}
		});
		oval.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
			    //设置为圆形
				shape = OVAL_SHAPE;
				//重新绘画
				drawArea.repaint();
			}
		});
		p.add(rect);
		p.add(oval);
		drawArea.setPreferredSize(new Dimension(250 , 180));

		f.add(drawArea);
		f.add(p , BorderLayout.SOUTH);
		f.pack();
		f.setVisible(true);
	}
	public static void main(String[] args) 
	{
		new SimpleDraw().init();
	}
	class MyCanvas extends Canvas
	{
	    //重写canvas的paint()方法,实现绘画
		public void paint(Graphics g)
		{
			Random rand = new Random();
			if (shape.equals(RECT_SHAPE))
			{
			    //设置颜色
				g.setColor(new Color(220, 100, 80));
				// ����ػ���һ�����ο�
				g.fillRect( rand.nextInt(200)
					, rand.nextInt(120) , 40 , 60);
			}
			if (shape.equals(OVAL_SHAPE))
			{
				// ���û�����ɫ
				g.setColor(new Color(80, 100, 200));
				// ��������һ��ʵ��Բ��
				g.fillOval( rand.nextInt(200) 
					, rand.nextInt(120) , 50 , 40);
			}
		}
	}
}
