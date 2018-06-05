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
public class BorderLayoutTest
{
	public static void main(String[] args) 
	{
		Frame f = new Frame("borderLayout");
		//设置frame容器使用该布局
		//如果没有指定添加的位置,会默认是中间,同一个位置多次添加,
		// 那么后一个添加的会覆盖前一个
		f.setLayout(new BorderLayout(30, 5));
		f.add(new Button("south") , SOUTH);
		f.add(new Button("north") , NORTH);
		// Ĭ����ӵ��м�
		f.add(new Button("middle"));
		f.add(new Button("east"), EAST);
		f.add(new Button("west") , WEST);
		// ���ô���Ϊ��Ѵ�С
		f.pack();
		// ��������ʾ������Frame����Ĭ�ϴ�������״̬��
		f.setVisible(true);
	}
}

