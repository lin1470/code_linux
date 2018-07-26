package awt;

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
public class ScrollPaneTest
{
	public static void main(String[] args) 
	{
		Frame f = new Frame("���Դ���");
		// ����һ��ScrollPane������ָ�����Ǿ��й�����
		ScrollPane sp = new ScrollPane(
			ScrollPane.SCROLLBARS_ALWAYS);
		// ��ScrollPane����������������
		sp.add(new TextField(20));
		sp.add(new Button("������"));
		// ��ScrollPane������ӵ�Frame������
		f.add(sp);
		// ���ô��ڵĴ�С��λ��
		f.setBounds(30, 30 , 250, 120);
		// ��������ʾ������Frame����Ĭ�ϴ�������״̬��
		f.setVisible(true);
	}
}

