package awt.awt11_4;

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
public class CommonComponent
{
	Frame f = new Frame("component test");
	// a button
	Button ok = new Button("ok");
	CheckboxGroup cbg = new CheckboxGroup();
	// 定义一个单选框,初始处于没有选中状态
	Checkbox male = new Checkbox("male" , cbg , true);
	// ����һ����ѡ�򣨴���cbgһ�飩����ʼ����û��ѡ��״̬
	Checkbox female = new Checkbox("female", cbg , false);
	// 复选框,初始处于没有选中状态
	Checkbox married = new Checkbox("�Ƿ��ѻ飿" , false);
	// 下拉选择框
	Choice colorChooser = new Choice();
	// 下拉列表
	List colorList = new List(6, true);
	// 文本域
	TextArea ta = new TextArea(5, 20);
	// 50列的单行文本域
	TextField name = new TextField(50);
	public void init()
	{
		colorChooser.add("green");
		colorChooser.add("red");
		colorChooser.add("blue");
		colorList.add("red");
		colorList.add("blue");
		colorList.add("green");
		//
		Panel bottom = new Panel();
		bottom.add(name);
		bottom.add(ok);
		f.add(bottom , BorderLayout.SOUTH);
		// ����һ��װ��������ѡ�������Checkbox��Panel
		Panel checkPanel = new Panel();
		checkPanel.add(colorChooser);
		checkPanel.add(male);
		checkPanel.add(female);
		checkPanel.add(married);
		// ����һ����ֱ���������Box��ʢװ�����ı���Panel
		Box topLeft = Box.createVerticalBox();
		topLeft.add(ta);
		topLeft.add(checkPanel);
		// ����һ����ֱ���������Box��ʢװtopLeft��colorList
		Box top = Box.createHorizontalBox();
		top.add(topLeft);
		top.add(colorList);
		// ��top Box������ӵ����ڵ��м�
		f.add(top);	
		f.pack();
		f.setVisible(true);
	}
	public static void main(String[] args) 
	{
		new CommonComponent().init();
	}
}
