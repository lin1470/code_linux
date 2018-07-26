package awt.awt11_3;

import java.awt.*;
import static java.awt.BorderLayout.*;
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
public class GridLayoutTest
{
	public static void main(String[] args) 
	{
		Frame f = new Frame("gridLayout");
		Panel p1 = new Panel();
		p1.add(new TextField(30));
		f.add(p1 , NORTH);
		Panel p2 = new Panel();
		//设置Panel使用GridLayout布局管理器
		p2.setLayout(new GridLayout(3, 5 , 4, 4));
		String[] name = {"0" , "1" , "2" , "3" 
			, "4" , "5" , "6" , "7" , "8" , "9"
			, "+" , "-" , "*" , "/" , "."};
		//向panel中一次添加15个按钮
		for (int i = 0 ; i < name.length; i++ )
		{
			p2.add(new Button(name[i]));
		}
		//添加p2Panel然后就没有了
		f.add(p2);
		// ���ô���Ϊ��Ѵ�С
		f.pack();
		// ��������ʾ������Frame����Ĭ�ϴ�������״̬��
		f.setVisible(true);
	}
}

