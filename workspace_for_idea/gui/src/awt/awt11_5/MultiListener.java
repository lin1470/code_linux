package awt.awt11_5;

import java.awt.*;
import java.awt.event.*;
/**
 * Description:
 * <br/>???: <a href="http://www.crazyit.org">???Java????</a> 
 * <br/>Copyright (C), 2001-2012, Yeeku.H.Lee
 * <br/>This program is protected by copyright laws.
 * <br/>Program Name:
 * <br/>Date:
 * @author Yeeku.H.Lee kongyeeku@163.com
 * @version 1.0
 */
public class MultiListener
{
	private Frame f = new Frame("????");
	private TextArea ta = new TextArea(6 , 40);
	private Button b1 = new Button("b1");
	private Button b2 = new Button("b2");
	public void init()
	{
		// ????FirstListener???????????
		FirstListener fl = new FirstListener();
		// ??b1???????????????????
		b1.addActionListener(fl);
		b1.addActionListener(new SecondListener());
		// ??f1?????????????b2???
		b2.addActionListener(fl);
		f.add(ta);
		Panel p = new Panel();
		p.add(b1);
		p.add(b2);
		f.add(p, BorderLayout.SOUTH);
		f.pack();
		f.setVisible(true);
	}
	class FirstListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			ta.append("????????????????????,???????" 
				+ e.getActionCommand() + "\n");
		}
	}
	class SecondListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			ta.append("???????" 
				+ e.getActionCommand() + "?????\n");
		}
	}
	public static void main(String[] args) 
	{
		new MultiListener().init();
	}
}
