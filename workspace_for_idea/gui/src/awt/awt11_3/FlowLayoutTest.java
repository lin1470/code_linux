package awt.awt11_3;

import java.awt.*;
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
public class FlowLayoutTest
{
	public static void main(String[] args) 
	{
		Frame f = new Frame("flowLayouttest");
		//设置frame容器使用flowLayout布局管理器
		f.setLayout(new FlowLayout(FlowLayout.CENTER , 20, 5));
		// 向窗口添加10个按钮
		for (int i = 0; i < 10 ; i++ )
		{
		f.add(new Button("按钮" + i));
		}
		//设置窗口为最佳大小j
		f.pack();//很少直接设置窗口的大小的,一般都是用次方法
		//将窗口显示出来(frame对向默认处于隐藏状态
		f.setVisible(true);
	}
}

