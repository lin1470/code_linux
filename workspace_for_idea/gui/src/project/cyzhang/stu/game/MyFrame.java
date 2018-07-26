/**
 * @Title: MyFrame.java
 * @Package cyzhang.stu.go
 * @Description: TODO(用一句话描述该文件做什么)
 * @author yang
 * @date 2018年6月3日 上午10:53:53
 * @version V1.0
 */
package project.cyzhang.stu.game;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.GeneralPath;
import java.awt.geom.Path2D;
import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Stack;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

/**
 * 
 * <p>
 * 问题: 这是一个边的类
 * </p>
 * <p>
 * Description: 用两个顶点代表一条边，边有一个运算符和两个权值，设置下一条边的第一个顶点的权值是上一条边的第二个权值
 * </p>
 * <p>
 * 思路:用Path2D来画一个小矩形来代表一条线，采用contains方法判断鼠标是否选中某条线
 * </p>
 * 
 * @author yang
 * @date 2018年6月4日 下午3:59:18
 * @版本 V 1.0
 */
class MyLine {
	int a, b, c, d;// shape后直线的两个端点
	boolean isSelected = false;
	public static float lineWidth = 0.5f; // 线宽
	static float len = 2.0f; // 线宽的改变主要靠该参数
	double distance;
	int weightP0;// 第一个点的权重
	int weightP1;// 第二个点的权重
	char operation;// 边的运算符
	int x0, y0, x1, y1;

	GeneralPath shape;

	double[] px = new double[4];
	double[] py = new double[4];
	public int lineId;

	// 构造边的图形
	public void constructShape() {
		int m = Math.round(len / 2);
		a = x0 + m;
		b = y0 + m;
		c = x1 + m;
		d = y1 + m;
		distance = Math.hypot(c - a, d - b);
		if (c == a) {
			px[0] = a + len;
			py[0] = b;
			px[1] = c + len;
			py[1] = d;
			px[2] = c - len;
			py[2] = d;
			px[3] = a - len;
			py[3] = b;
		} else if (d == b) {
			px[0] = a;
			py[0] = b - len;
			px[1] = c;
			py[1] = d - len;
			px[2] = c;
			py[2] = d + len;
			px[3] = a;
			py[3] = b + len;
		} else {
			double sin = (c - a) / distance;
			double cos = (d - b) / distance;
			px[0] = a + len * cos;
			py[0] = b - len * sin;
			px[1] = c + len * cos;
			py[1] = d - len * sin;
			px[2] = c - len * cos;
			py[2] = d + len * sin;
			px[3] = a - len * cos;
			py[3] = b + len * sin;
		}

		shape = new GeneralPath(Path2D.WIND_NON_ZERO);
		;
		shape.moveTo(px[0], py[0]);
		shape.lineTo(px[1], py[1]);
		shape.lineTo(px[2], py[2]);
		shape.lineTo(px[3], py[3]);
		shape.closePath();
	}

	// 可以用来判断鼠标的位置是否在某个封闭图形内
	public boolean contains(int x, int y) {
		return Path2D.contains(shape.getPathIterator(null), new Point2D.Float(x, y));
	}
}

/**
 * <p>
 * 问题:主界面窗口类
 * </p>
 * <p>
 * Description: 用来显示游戏的各个界面
 * </p>
 * <p>
 * 思路:
 * </p>
 * 
 * @author yang
 * @date 2018年6月3日 上午10:53:53
 * @版本 V 1.0
 */
public class MyFrame extends JFrame {

	/**
	 * @Fields serialVersionUID : TODO(用一句话描述这个变量表示什么)
	 */
	private static final long serialVersionUID = 1L;

	private static final String LINE_SEPARATOR = System.getProperty("line.separator");

	MyLine inLine;// 当前要画的线
	ArrayList<MyLine> lineLists = new ArrayList<>();// 当前状态下的线的集合
	private JTextField textField_2;// 边数文本框
	private JTextField textField_3;// 权值文本框
	private List<Double> xs;// 重构后的x坐标集
	private List<Double> ys;// 重构后的y坐标集
	private int edge;// 边数
	private JTabbedPane tabbedPane;// Panel容器
	private JTextField textField;// 运算符文本框
	private JTextArea textArea;// 显示规则文本区
	private ArrayList<MyLine> showList;//演示所用的边集

	// 默认权重数组
	private int weights[] = { 1, 2, 3, 4, 5 };
	// 默认运算符数组
	private String op[] = null;

	private Stack<ArrayList<MyLine>> stack = new Stack<>();// 保留上一步操作的栈

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyFrame frame = new MyFrame();
					frame.setTitle("多边形游戏");
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 * 
	 * @throws IOException
	 */
	public MyFrame() throws IOException {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 600);
		// getContentPane().setLayout(null);

		tabbedPane = new JTabbedPane(JTabbedPane.LEFT);
		tabbedPane.setSelectedIndex(-1);
		// tabbedPane.setBounds(0, 0, 185, 228);
		getContentPane().add(tabbedPane);

		JPanel panel = new JPanel();
		tabbedPane.addTab("初始化", null, panel, null);

		panel.setLayout(null);

		// 覆盖默认的InitPanel
		LinePanel linePanel = new LinePanel();
		// 为JPanel绑定鼠标左键监听器
		linePanel.addMouseListener(new MyMouseListener());

		tabbedPane.addTab("开始", null, linePanel, null);
		
		JButton unDoTyping = new JButton("撤回");// 撤回按钮
		// 撤回操作
		unDoTyping.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if (!stack.isEmpty()) {

					// 弹栈
					// 深复制
					ArrayList<MyLine> LlineLists = new ArrayList<>();
					LlineLists = stack.pop();
					lineLists.clear();
					for (MyLine line : LlineLists) {
						MyLine t = new MyLine();
						t.lineId = line.lineId;
						t.x0 = line.x0;
						t.x1 = line.x1;
						t.y0 = line.y0;
						t.y1 = line.y1;
						t.operation = line.operation;
						t.weightP0 = line.weightP0;
						t.weightP1 = line.weightP1;
						lineLists.add(t);

					}
					edge++;
					repaint();
				} else {
					JOptionPane.showMessageDialog(null, "已经撤回到第一步了！", "警告", JOptionPane.INFORMATION_MESSAGE);
				}
			}
		});
		linePanel.add(unDoTyping);
		
		JButton showButton = new JButton("演示");// 撤回按钮
		showButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
					showBest();
			}
		});
		linePanel.add(showButton);
		
		JButton returnButton = new JButton("重玩");// 撤回按钮
		returnButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				returnLineList();
				repaint();
			}
		});
		linePanel.add(returnButton);
		
		// 规则Panel
		JPanel rulesPanel = new JPanel();
		tabbedPane.addTab("规则", null, rulesPanel, null);
		rulesPanel.setLayout(null);

		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(50, 50, 434, 381);
		rulesPanel.add(scrollPane);

		textArea = new JTextArea();
		scrollPane.setViewportView(textArea);
		textArea.setEditable(false);
		showRules();

		// 边数：
		JLabel label = new JLabel("\u8FB9\u6570\uFF1A");
		label.setBounds(55, 40, 54, 15);
		panel.add(label);

		textField_2 = new JTextField();
		textField_2.setToolTipText("\u6574\u6570");
		textField_2.setBounds(114, 40, 66, 21);

		// 边数更新后，权值和运算符输入置空
		textField_2.getDocument().addDocumentListener(new DocumentListener() {

			@Override
			public void removeUpdate(DocumentEvent e) {

			}

			// 边数更新后，权值和运算符输入置空
			@Override
			public void insertUpdate(DocumentEvent e) {
				textField_3.setText(null);
				textField.setText(null);

			}

			@Override
			public void changedUpdate(DocumentEvent e) {
			}
		});

		panel.add(textField_2);
		textField_2.setColumns(10);

		// 权值：
		JLabel label_1 = new JLabel("\u70B9\u7684\u6743\u503C\uFF1A");
		label_1.setToolTipText("+\uFF0C*\uFF0C\u4EE5,\u5206\u9694");
		label_1.setBounds(36, 76, 73, 15);
		panel.add(label_1);

		// 权值text
		textField_3 = new JTextField();
		textField_3.setToolTipText("\u4EE5,\u5206\u9694");
		textField_3.setBounds(114, 71, 287, 21);
		panel.add(textField_3);
		textField_3.setColumns(30);

		// 初始化界面的“随机生成”按钮
		JButton button = new JButton("\u968F\u673A\u751F\u6210\u8FB9\u548C\u7B26\u53F7");

		button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				String edgeNum = textField_2.getText().toString();
				if (edgeNum.equals("")) {
					JOptionPane.showMessageDialog(null, "边数不能为空！", "警告", JOptionPane.INFORMATION_MESSAGE);

				} else {
					int bianShu = Integer.parseInt(edgeNum);
					int a[] = new int[bianShu];
					Random r = new Random();
					for (int i = 0; i < a.length; i++) {
						a[i] = r.nextInt(21) - 10;
					}
					String s = Arrays.toString(a);
					String tS = s.substring(1, s.length() - 1);
					textField_3.setText(tS.replace(" ", ""));

					// 随机生成运算符
					char b[] = new char[bianShu];
					for (int i = 0; i < b.length; i++) {
						if (r.nextInt(2) == 0) {
							b[i] = '+';
						} else {
							b[i] = '*';
						}

					}
					s = Arrays.toString(b);
					tS = s.substring(1, s.length() - 1);
					textField.setText(tS.replace(" ", ""));
				}
			}
		});

		button.setBounds(148, 147, 140, 23);
		panel.add(button);

		// 初始化界面的“开始按钮”，设置跳转到LinePanel（开始）
		JButton button_1 = new JButton("\u5F00\u59CB");
		button_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				//获取用户输入的边数，权值，和运算符
				String edgeNum = textField_2.getText().toString();
				String weightString = textField_3.getText().toString();
				String opString = textField.getText().toString();
				if (edgeNum.equals("") || weightString.equals("") || opString.equals("")) {
					JOptionPane.showMessageDialog(null, "输入不能为空！", "警告", JOptionPane.INFORMATION_MESSAGE);

				} else {
					edge = Integer.parseInt(edgeNum);
					if (edge < 3 | weightString.length() < edge | opString.length() < edge) {
						JOptionPane.showMessageDialog(null, "输入不能少于3!\n或者\n运算符和权值个数不对！", "警告",
								JOptionPane.INFORMATION_MESSAGE);
					} else {

						// 初始化权值数组
						weights = toIntArr(weightString);
						// 初始化运算符数组
						op = toCharArr(opString);

						initMyList(edge);
						getLineList();//保留一份最初的边集，用来进行重玩操作
						getRoute();//获取最优路径
						tabbedPane.setSelectedIndex(1);
					}
				}
			}
		});
		button_1.setBounds(177, 192, 93, 23);
		panel.add(button_1);

		// 运算符
		JLabel label_2 = new JLabel("\u8FB9\u8FD0\u7B97\u7B26\uFF1A");

		label_2.setToolTipText("\u4EE5,\u5206\u9694");
		label_2.setBounds(36, 104, 73, 15);
		panel.add(label_2);

		// 运算符text
		textField = new JTextField();
		textField.setBounds(115, 101, 286, 21);
		panel.add(textField);
		textField.setColumns(30);

	}

	/**
	 * @throws IOException
	 * @Title: showRules
	 * @Description:用来显示规则的方法
	 * @param: void
	 * @return: void 
	 * @throws
	 */
	private void showRules() throws IOException {

//		//读取src下的规则文件
		String path = "src/project/rules/rules.txt";
//		System.out.println(System.getProperty("user.dir"));
		File file = new File(path);
		BufferedReader br = new BufferedReader(new FileReader(file));
		String line = null;
		while ((line = br.readLine()) != null) {
			textArea.append(line + LINE_SEPARATOR);
		}
		br.close();
	}

	// 画线的容器
	class LinePanel extends JPanel {
		/**
		 * @Fields serialVersionUID : TODO(用一句话描述这个变量表示什么)
		 */
		private static final long serialVersionUID = 1L;
		Graphics2D g2;

		public LinePanel() {

		}

		// 覆盖画组件的方法，进行画线
		public void paintComponent(Graphics g) {
			System.out.println("showpaint...........");
				GeneralPath shape;// 取出当前直线的shape
				MyLine tempLine;// 遍历Linelist的中间变量

				super.paintComponent(g);// 保留上一次的图
				g2 = (Graphics2D) g;
				Paint oldPaint = g2.getPaint();// 保留原画笔

				if (edge != 0) {
					// 遍历边集，画图形
					for (int i = 0; i < lineLists.size(); i++) {
						tempLine = lineLists.get(i);
						tempLine.constructShape();
						shape = tempLine.shape;
						g2.setStroke(new BasicStroke(MyLine.lineWidth));
						g2.setPaint(Color.GREEN);
						g2.fill(shape);
						g2.setPaint(Color.RED);

						g2.setFont(new Font("Tahoma", Font.BOLD, 20));

						g2.drawString(" " + tempLine.weightP0, tempLine.x0-15, tempLine.y0);
						int midx = Math.round((tempLine.x0 + tempLine.x1) / 2.0f);
						int midy = Math.round((tempLine.y0 + tempLine.y1) / 2.0f);
						g2.drawString("  " + String.format("%c", tempLine.operation), midx-20, midy+7);

						if (edge <= 2) {
							g2.drawString(" " + tempLine.weightP1, tempLine.x1-15, tempLine.y1);
						}


					}
				}		
		}
	}

	// LinePanel的鼠标监听器
	class MyMouseListener implements MouseListener {
		@Override
		public void mouseClicked(MouseEvent e) {
			if (e.getButton() == MouseEvent.BUTTON1) { // e.getButton就会返回点鼠标的那个键，左键还是右健，3代表右键
				int x = e.getX(); // 得到鼠标x坐标
				int y = e.getY(); // 得到鼠标y坐标
				int sum = 0;// 当点数是2的时候存储权值
				for (MyLine line : lineLists) {
					if (line.contains(x, y)) {

						int newWeight = 0;
						if (line.operation == '+') {
							newWeight = line.weightP0 + line.weightP1;
						} else {
							newWeight = line.weightP0 * line.weightP1;
						}
						if (edge == 2) {
							if (line.operation == '+')
								sum = line.weightP0 + line.weightP1;
							else
								sum = line.weightP0 * line.weightP1;
						}

						// 压栈，保存上一步操作
						// 深复制
						ArrayList<MyLine> LlineLists = new ArrayList<>();
						for (MyLine Tline : lineLists) {
							MyLine t = new MyLine();
							t.lineId = line.lineId;
							t.x0 = Tline.x0;
							t.x1 = Tline.x1;
							t.y0 = Tline.y0;
							t.y1 = Tline.y1;
							t.operation = Tline.operation;
							t.weightP0 = Tline.weightP0;
							t.weightP1 = Tline.weightP1;

							LlineLists.add(t);
						}
						stack.push(LlineLists);

						lineLists.remove(line);
						--edge;
						updateList(newWeight, line.x0, line.y0, line.x1, line.y1);// 更新边集
						break;
					}
				}
				if (edge == 1) {
					JOptionPane.showMessageDialog(null, "Your total score is:  " + sum + "  !", "恭喜",
							JOptionPane.INFORMATION_MESSAGE);
					tabbedPane.setSelectedIndex(-1);
				}
				repaint();
			}
		}
		@Override
		public void mousePressed(MouseEvent e) {
		}
		@Override
		public void mouseReleased(MouseEvent e) {
		}
		@Override
		public void mouseEntered(MouseEvent e) {
		}
		@Override
		public void mouseExited(MouseEvent e) {
		}

	}

	/**
	 * 
	 * @Title: initMyList
	 * @Description: 画图之前初始化边集
	 * @param: @param edge   
	 * @return: void   
	 * @throws
	 */
	public void initMyList(int edge) {

		index=0;
		int id=0;
		// 弹出栈中所有内容
		while (!stack.isEmpty()) {
			stack.pop();
		}

		//通过边数生成规则的正多边形坐标
		GenPoints genpoints = new GenPoints(edge, 100);
		genpoints.tranformByCenter(200, 200);
		xs = genpoints.xs;
		ys = genpoints.ys;

		if (!lineLists.isEmpty()) {
			lineLists.clear();
		}
		for (int i = 0; i < xs.size(); i++) {
			if (i == 0) {
				inLine = new MyLine();
				inLine.lineId = id++;
				inLine.x0 = xs.get(xs.size() - 1).intValue();
				inLine.y0 = ys.get(xs.size() - 1).intValue();
				inLine.x1 = xs.get(0).intValue();
				inLine.y1 = ys.get(0).intValue();

				inLine.operation = op[0].charAt(0);

				inLine.weightP0 = weights[xs.size() - 1];
				inLine.weightP1 = weights[0];
				lineLists.add(inLine);
			} else {
				inLine = new MyLine();
				inLine.lineId = id++;
				inLine.x0 = xs.get(i-1).intValue();
				inLine.y0 = ys.get(i-1).intValue();
				inLine.x1 = xs.get(i).intValue();
				inLine.y1 = ys.get(i).intValue();

				inLine.operation = op[i].charAt(0);

				inLine.weightP0 = weights[i-1];
				inLine.weightP1 = weights[i];
				lineLists.add(inLine);
			}

		}

	}

	/**
	 * 
	 * @Title: updateList
	 * @Description: 每次删除后更新画图的边集
	 * @param: @param newWeight 删除的边的计算权值结果
	 * @param: @param x0  删除的边的第一个坐标的x坐标
	 * @param: @param y0 删除的边的第一个坐标的y坐标
	 * @param: @param x1 删除的边的第二个坐标的x坐标
	 * @param: @param y1 删除的边的第二个坐标的y坐标 
	 * @return: void   
	 * @throws
	 */
	public void updateList(int newWeight, int x0, int y0, int x1, int y1) {
		//更新前获取重构后的坐标
		GenPoints genpoints = new GenPoints(edge, 100);
		genpoints.tranformByCenter(200, 200);
		xs = genpoints.xs;
		ys = genpoints.ys;
		//通过下面的循环更新某条边删除后把权值赋给跟这条边相关联的两条边的权值
		for (int i = 0; i < lineLists.size(); i++) {
			if ((lineLists.get(i).x0 == x0) && (lineLists.get(i).y0 == y0)) {
				lineLists.get(i).weightP0 = newWeight;
				System.out.println("....new" + lineLists.get(i).weightP0);
			} else if (lineLists.get(i).x1 == x1 && lineLists.get(i).y1 == y1) {
				lineLists.get(i).weightP1 = newWeight;
				System.out.println("....new" + lineLists.get(i).weightP1);

			} else if ((lineLists.get(i).x0 == x1) && (lineLists.get(i).y0 == y1)) {
				lineLists.get(i).weightP0 = newWeight;
			} else if ((lineLists.get(i).x1 == x0) && (lineLists.get(i).y1 == y0)) {
				lineLists.get(i).weightP1 = newWeight;
			}
			if (edge > 2) {
				if (i == 0) {
					lineLists.get(i).x0 = xs.get(lineLists.size() - 1).intValue();
					lineLists.get(i).y0 = ys.get(lineLists.size() - 1).intValue();
					lineLists.get(i).x1 = xs.get(0).intValue();
					lineLists.get(i).y1 = ys.get(0).intValue();
				} else {
					lineLists.get(i).x0 = xs.get(i-1).intValue();
					lineLists.get(i).y0 = ys.get(i-1).intValue();
					lineLists.get(i).x1 = xs.get(i).intValue();
					lineLists.get(i).y1 = ys.get(i).intValue();
				}
			} else {
				
			}

		}
	}

	// 将text输入的序列分割成int数组
	public int[] toIntArr(String s) {
		String[] t = s.split(",");
		int[] a = new int[t.length];
		for (int i = 0; i < t.length; i++) {
			a[i] = Integer.parseInt(t[i]);
		}
		return a;
	}

	// 将text输入的序列分割成String数组
	public String[] toCharArr(String s) {
		String[] t = s.split(",");
		return t;
	}
	
	//获取最优解的路径
	int routArr[];
	int index =0;
    public void  getRoute(){
    	
//    	index = 0;
    	
//        String edgeNum = textField_2.getText().toString();
        String weightString = textField_3.getText().toString();
        String opString = textField.getText().toString();
        
        int weiArr[] = toIntArr(weightString);
        String opArr[] = toCharArr(opString);
        
        ArrayList<Integer> weightArr = new ArrayList<>();
        ArrayList<Character> operaArr = new ArrayList<>();
        
        for(int i=0;i<weiArr.length;i++){
            weightArr.add(weiArr[i]);
            operaArr.add(opArr[i].charAt(0));
        }
        //映射关系
        
        System.out.println(weightArr);
        System.out.println(operaArr);

        PolygonSolver solver = new PolygonSolver(weightArr,operaArr);
        solver.findSolution();
        ArrayList<Integer> route = solver.getMaxRoute();
        routArr = new int[route.size()];
        int size= route.size();

        for(int i=0;i<size;i++){
        	routArr[i] = route.get(i);
        }
        //逆序改回来顺序
        int t;
        for (int i = 0; i < routArr.length/2; i++) {
			t=routArr[i];
			routArr[i] = routArr[routArr.length-i-1];
			routArr[routArr.length-i-1] = t;
		} 
        System.out.println(solver.getMaxRoute());
        System.out.println(solver.toString());
        for (int i = 0; i < routArr.length; i++) {
        	 System.out.print(routArr[i]+" ");
		}
       

    }
	
	//最优演示方法
	int sum=0;

	public void showBest(){
		
			MyLine sline = new MyLine();
			//获取被选择的边，然后下面计算他的权值
			for (MyLine line :lineLists) {
				if (line.lineId == routArr[index]) {
					sline=line;
					lineLists.remove(line);
					System.out.println(line.lineId);
					index++;
					break;
				}
			}

			int newWeight;
			if (sline.operation == '+') {
				newWeight=sline.weightP0+sline.weightP1;
			}else{
				newWeight=sline.weightP0*sline.weightP1;
			}

			edge--;
			updateList(newWeight, sline.x0, sline.y0, sline.x1, sline.y1);
			repaint();
//		if (edge == 2) {
//			System.out.println("edge=2,sline.p0,p1...."+sline.weightP0 +" "+ sline.weightP1);
//			if (sline.operation == '+')
//				sum = sline.weightP0 + sline.weightP1;
//			else
//				sum = sline.weightP0 * sline.weightP1;
//		}
		if(edge == 1){
			if (sline.operation == '+')
				sum = sline.weightP0 + sline.weightP1;
			else
				sum = sline.weightP0 * sline.weightP1;
			JOptionPane.showMessageDialog(null, "Your total score is:  " + sum + "  !", "恭喜",
					JOptionPane.INFORMATION_MESSAGE);
		}
		
	}

	/**
	 * @Title: getLineList
	 * @Description: TODO(这里用一句话描述这个方法的作用)
	 * @param:    
	 * @return: void   
	 * @throws
	 */
	int tEdge;
	private void getLineList() {
		tEdge = edge;
		showList = new ArrayList<>();
		for (MyLine line : lineLists) {
			MyLine t = new MyLine();
			t.lineId = line.lineId;
			t.x0 = line.x0;
			t.x1 = line.x1;
			t.y0 = line.y0;
			t.y1 = line.y1;
			t.operation = line.operation;
			t.weightP0 = line.weightP0;
			t.weightP1 = line.weightP1;	
			showList.add(t);
		}
	}
	private void returnLineList(){
		index = 0;
		lineLists.clear();
		edge = tEdge;
		for (MyLine line : showList) {
			MyLine t = new MyLine();
			t.lineId = line.lineId;
			t.x0 = line.x0;
			t.x1 = line.x1;
			t.y0 = line.y0;
			t.y1 = line.y1;
			t.operation = line.operation;
			t.weightP0 = line.weightP0;
			t.weightP1 = line.weightP1;	
			lineLists.add(t);
		}
	}

}
