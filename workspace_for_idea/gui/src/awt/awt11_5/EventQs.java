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
public class EventQs
{
	private Frame f = new Frame("test event");
	private Button ok = new Button("ok");
	private TextField tf = new TextField(30);
	public void init()
	{
		//注册时间坚挺器
		ok.addActionListener(new OkListener());   //��
		f.add(tf);
		f.add(ok , BorderLayout.SOUTH);
		f.pack();
		f.setVisible(true);
	}
	//定义监听器
	class OkListener implements ActionListener   //��
	{
	    //定义处理事件
		public void actionPerformed(ActionEvent e)      //��
		{
			System.out.println("clike ok");
			tf.setText("Hello World");
		}
	}

	public static void main(String[] args) 
	{
		new EventQs().init();
	}

}
