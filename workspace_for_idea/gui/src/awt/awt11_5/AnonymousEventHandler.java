package awt.awt11_5;

import java.awt.*;
import java.awt.event.*;
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
public class AnonymousEventHandler
{
	private Frame f = new Frame("����");
	private TextArea ta = new TextArea(6 , 40);
	public void init()
	{
		// �������ڲ������ʽ�������¼�����������
		f.addWindowListener(new WindowAdapter()
		{
			// ʵ���¼�������
			public void windowClosing(WindowEvent e) 
			{
				System.out.println("�û���ͼ�رմ��ڣ�\n");
				System.exit(0);
			}
		});
		f.add(ta);
		f.pack();
		f.setVisible(true);
	}
	public static void main(String[] args) 
	{
		new AnonymousEventHandler().init();
	}
}
