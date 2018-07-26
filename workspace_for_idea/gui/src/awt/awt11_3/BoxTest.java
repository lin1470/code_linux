package awt.awt11_3;

import java.awt.*;
import javax.swing.*;

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
public class BoxTest
{
	private Frame f = new Frame("boxLayoutTest");
	//水平
	private Box horizontal = Box.createHorizontalBox();
	//垂直
	private Box vertical = Box.createVerticalBox();
	public void init()
	{
		horizontal.add(new Button("ˮƽ��ťһ"));
		horizontal.add(new Button("ˮƽ��ť��"));
		vertical.add(new Button("��ֱ��ťһ"));
		vertical.add(new Button("��ֱ��ť��"));
		f.add(horizontal , BorderLayout.NORTH);
		f.add(vertical);
		f.pack();
		f.setVisible(true);
	}
	public static void main(String[] args) 
	{
		new BoxTest().init();
	}
}

