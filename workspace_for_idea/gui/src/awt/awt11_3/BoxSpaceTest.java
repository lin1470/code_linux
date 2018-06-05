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
public class BoxSpaceTest
{
	private Frame f = new Frame("����");
	// ����ˮƽ�ڷ������Box����
	private Box horizontal = Box.createHorizontalBox();
	// ���崹ֱ�ڷ������Box����
	private Box vertical = Box.createVerticalBox();
	public void init()
	{
		horizontal.add(new Button("ˮƽ��ťһ"));
		horizontal.add(Box.createHorizontalGlue());
		horizontal.add(new Button("ˮƽ��ť��"));
		// ˮƽ���򲻿�����ļ�࣬����Ϊ10px
		horizontal.add(Box.createHorizontalStrut(10));
		horizontal.add(new Button("ˮƽ��ť��"));
		vertical.add(new Button("��ֱ��ťһ"));
		vertical.add(Box.createVerticalGlue());
		vertical.add(new Button("��ֱ��ť��"));
		// ��ֱ���򲻿�����ļ�࣬��߶�Ϊ10px
		vertical.add(Box.createVerticalStrut(10));
		vertical.add(new Button("��ֱ��ť��"));
		f.add(horizontal , BorderLayout.NORTH);
		f.add(vertical);
		f.pack();
		f.setVisible(true);
	}
	public static void main(String[] args) 
	{
		new BoxSpaceTest().init();
	}
}
