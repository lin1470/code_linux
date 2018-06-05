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
// GUI������̳�WindowAdapter��Ϊ�¼���������
public class SimpleEventHandler extends WindowAdapter
{
	private Frame f = new Frame("����");
	private TextArea ta = new TextArea(6 , 40);
	public void init()
	{
		//�������Ĭ�϶�����Ϊ�¼�����������
		f.addWindowListener(this);
		f.add(ta);
		f.pack();
		f.setVisible(true);
	}
	// GUI������ֱ�Ӱ����¼�����������
	public void windowClosing(WindowEvent e) 
	{
		System.out.println("�û��رմ��ڣ�\n");
		System.exit(0);
	}
	public static void main(String[] args) 
	{
		new SimpleEventHandler().init();
	}
}
