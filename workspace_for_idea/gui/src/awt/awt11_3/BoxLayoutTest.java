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
public class BoxLayoutTest
{
	private Frame f = new Frame("����");
	public void init()
	{
		f.setLayout(new BoxLayout(f , BoxLayout.Y_AXIS));
		// ���水ť���ᴹֱ����
		f.add(new Button("��һ����ť"));
		f.add(new Button("��ť��"));
		f.pack();
		f.setVisible(true);
	}
	public static void main(String[] args) 
	{
		new BoxLayoutTest().init();
	}
}
