/**
 * @Title: MyFrame.java
 * @Package cyzhang.stu.go
 * @Description: TODO(用一句话描述该文件做什么)
 * @author yang
 * @date 2018年6月3日 上午10:53:53
 * @version V1.0
 */
package project;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;
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
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import project.data.GenPoints;
import project.polygon.PolygonSolver;

class MyLine {
    int a, b, c, d;// shape后直线的两个端点
    boolean isSelected = false;
    public static float lineWidth = 0.5f; // 线宽
    static float len = 2.0f; //线宽的改变主要靠该参数
    double distance;
    int weightP0;//第一个点的权重
    int weightP1;//第二个点的权重
    char operation;//边的运算符
    int x0, y0, x1, y1;
    int id;
    GeneralPath shape;

    double[] px = new double[4];
    double[] py = new double[4];
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

        shape = new GeneralPath(Path2D.WIND_NON_ZERO);;
        shape.moveTo(px[0], py[0]);
        shape.lineTo(px[1], py[1]);
        shape.lineTo(px[2], py[2]);
        shape.lineTo(px[3], py[3]);
        shape.closePath();
    }

    //可以用来判断鼠标的位置是否在某个封闭图形内
    public boolean contains(int x, int y) {
        return Path2D.contains(shape.getPathIterator(null), new Point2D.Float(x, y));
    }
}


/**
 * <p>问题: </p>
 * <p>Description: </p>
 * <p>思路: </p>
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


    MyLine inLine;//当前要画的线
    ArrayList<MyLine> lineLists = new ArrayList<>();
    private JTextField textField_2;
    private JTextField textField_3;
    private List<Double> xs;
    private List<Double> ys;
    private int edge;
    private JTabbedPane tabbedPane;
    private JTextField textField;
    private JTextArea textArea;

    private int weights[] ={1,2,3,4,5};
    private String op[] = null;


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
     * @throws IOException
     */
    public MyFrame() throws IOException {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(200, 200, 600, 400);
//		getContentPane().setLayout(null);

        tabbedPane = new JTabbedPane(JTabbedPane.LEFT);
        tabbedPane.setSelectedIndex(-1);
//		tabbedPane.setBounds(0, 0, 185, 228);
        getContentPane().add(tabbedPane);

        JPanel panel = new JPanel();
        tabbedPane.addTab("初始化", null, panel, null);


        panel.setLayout(null);


        //覆盖默认的InitPanel
        LinePanel linePanel = new LinePanel();
        //为JPanel绑定鼠标左键监听器
        linePanel.addMouseListener(new MyMouseListener());

        tabbedPane.addTab("开始", null, linePanel, null);

//		linePanel.add(button_1);

        //规则Panel
        JPanel rulesPanel = new JPanel();
        tabbedPane.addTab("规则", null, rulesPanel, null);
        rulesPanel.setLayout(null);

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setBounds(50, 50, 434, 281);
        rulesPanel.add(scrollPane);

        textArea = new JTextArea();
        scrollPane.setViewportView(textArea);
        textArea.setEditable(false);
        showRules();


        //边数：
        JLabel label = new JLabel("\u8FB9\u6570\uFF1A");
        label.setBounds(55, 40, 54, 15);
        panel.add(label);

        textField_2 = new JTextField();
        textField_2.setToolTipText("\u6574\u6570");
        textField_2.setBounds(114, 40, 66, 21);
        panel.add(textField_2);
        textField_2.setColumns(10);

        //权值：
        JLabel label_1 = new JLabel("\u70B9\u7684\u6743\u503C\uFF1A");
        label_1.setToolTipText("+\uFF0C*\uFF0C\u4EE5,\u5206\u9694");
        label_1.setBounds(36, 76, 73, 15);
        panel.add(label_1);

        //权值text
        textField_3 = new JTextField();
        textField_3.setToolTipText("\u4EE5,\u5206\u9694");
        textField_3.setBounds(114, 71, 287, 21);
        panel.add(textField_3);
        textField_3.setColumns(30);

        //初始化界面的“随机生成”按钮
        JButton button = new JButton("\u968F\u673A\u751F\u6210\u8FB9\u548C\u7B26\u53F7");

        button.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO Auto-generated method stub
                String edgeNum = textField_2.getText().toString();
                if (edgeNum.equals("")) {
                    JOptionPane.showMessageDialog(null, "边数不能为空！", "警告", JOptionPane.INFORMATION_MESSAGE);

                }else{
                    int bianShu = Integer.parseInt(edgeNum);
                    int a[] = new int[bianShu];
                    Random r = new Random();
                    for (int i = 0; i < a.length; i++) {
                        a[i] = r.nextInt(21)-10;
                    }
                    String s = Arrays.toString(a);
                    String tS = s.substring(1, s.length()-1);
                    textField_3.setText(tS.replace(" ", ""));

                    //随机生成运算符
                    char b[]=new char[bianShu];
                    for (int i = 0; i < b.length; i++) {
                        if (r.nextInt(2) == 0) {
                            b[i] = '+';
                        }
                        else{
                            b[i] = '*';
                        }

                    }
                    s=Arrays.toString(b);
                    tS = s.substring(1, s.length()-1);
                    textField.setText(tS.replace(" ",""));
                }
            }
        });

        button.setBounds(148, 147, 140, 23);
        panel.add(button);

        //初始化界面的“开始按钮”，设置跳转到LinePanel（开始）
        JButton button_1 = new JButton("\u5F00\u59CB");
        button_1.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                String edgeNum = textField_2.getText().toString();
                String weightString = textField_3.getText().toString();
                String opString = textField.getText().toString();
                if(edgeNum.equals("") || weightString.equals("") || opString.equals("")){
                    JOptionPane.showMessageDialog(null, "输入不能为空！", "警告", JOptionPane.INFORMATION_MESSAGE);

                }else{
                    edge = Integer.parseInt(edgeNum);
                    if(edge <3 | weightString.length()<edge | opString.length()<edge){
                        JOptionPane.showMessageDialog(null, "输入不能少于3!\n或者\n运算符和权值个数不对！", "警告", JOptionPane.INFORMATION_MESSAGE);
                    }
                    else {

                        //初始化权值数组
                        weights = toIntArr(weightString);
                        //初始化运算符数组
                        op = toCharArr(opString);

                        initMyList(edge);
                        tabbedPane.setSelectedIndex(1);
                    }
                }
            }
        });
        button_1.setBounds(177, 192, 93, 23);
        panel.add(button_1);

        //运算符
        JLabel label_2 = new JLabel("\u8FB9\u8FD0\u7B97\u7B26\uFF1A");

        label_2.setToolTipText("\u4EE5,\u5206\u9694");
        label_2.setBounds(36, 104, 73, 15);
        panel.add(label_2);


        //运算符text
        textField = new JTextField();
        textField.setBounds(115, 101, 286, 21);
        panel.add(textField);
        textField.setColumns(30);


    }

    /**
     * @throws IOException
     * @Title: showRules
     * @Description: TODO(这里用一句话描述这个方法的作用)
     * @param:
     * @return: void
     * @throws
     */
    private void showRules() throws IOException {
        // TODO Auto-generated method stub
//        String path = "d:\\rules.txt";
//        File file = new File(path);
//        BufferedReader br = new BufferedReader(new FileReader(file));
//        String line = null;
//        while((line = br.readLine())!=null){
//            textArea.append(line+LINE_SEPARATOR);
//        }

    }
    int flag = 1;
    //画线的容器
    class LinePanel extends JPanel {
        /**
         * @Fields serialVersionUID : TODO(用一句话描述这个变量表示什么)
         */
        private static final long serialVersionUID = 1L;
        Graphics2D g2;

        public LinePanel() {

        }

        //覆盖画组件的方法，进行画线
        public void paintComponent(Graphics g) {

            super.paintComponent(g);//保留上一次的图
            g2 = (Graphics2D) g;
            if(flag==1)
            {
                showBest(g2);
            }else{
                painLines(g2);

            }

//			Graphics2D g2 = (Graphics2D) g;

//			System.out.println(inLine.contains(11, 11));

        }
    }

    public void painLines(Graphics2D g2){


        GeneralPath shape;//取出当前直线的shape
        MyLine tempLine;//遍历Linelist的中间变量

        if (edge !=0) {
            //遍历边集，画图形
            for (int i = 0; i <lineLists.size(); i++) {
                tempLine = lineLists.get(i);
                tempLine.constructShape();
                shape = tempLine.shape;
                g2.setStroke(new BasicStroke(MyLine.lineWidth));
                g2.setPaint(Color.RED);
                g2.drawString("    "+tempLine.weightP0, tempLine.x0, tempLine.y0);
                int midx = Math.round((tempLine.x0 + tempLine.x1) / 2.0f);
                int midy = Math.round((tempLine.y0 + tempLine.y1) / 2.0f);
                g2.drawString("   "+String.format("%c", tempLine.operation), midx, midy);

                if (edge <=2) {
                    g2.drawString("    "+tempLine.weightP1, tempLine.x1, tempLine.y1);
                }

//					g2.drawString("              "+tempLine.weightP1, tempLine.x1, tempLine.y1);

                g2.setPaint(Color.BLACK);
                g2.fill(shape);
            }
            System.out.println(".......paint");

        }
    }
    public void showBest(Graphics2D g2){
        int size = lineLists.size();
        for(int i=0;i<size;i++)
        {
            removeAll();
            painLines(g2);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            lineLists.remove(0);
            edge--;
        }
        flag = 0;
    }

    //LinePanel的鼠标监听器
    class MyMouseListener implements MouseListener{

        /* (non-Javadoc)
         * @see java.awt.event.MouseListener#mouseClicked(java.awt.event.MouseEvent)
         */
        @Override
        public void mouseClicked(MouseEvent e) {
            // TODO Auto-generated method stub
            if(e.getButton() == MouseEvent.BUTTON1){ //e.getButton就会返回点鼠标的那个键，左键还是右健，3代表右键
                int x = e.getX();  //得到鼠标x坐标
                int y = e.getY();  //得到鼠标y坐标
                String banner = "鼠标当前点击位置的坐标是" + x + "," + y;
//                label.setText(banner);  //修改标签内容
                System.out.println(banner);
//                System.out.println(inLine.contains(x,y));
                int sum =0;//当点数是2的时候存储权值
                for (MyLine line : lineLists) {
                    if (line.contains(x, y)) {

                        int newWeight = 0;
                        if (line.operation == '+') {
                            newWeight = line.weightP0 + line.weightP1;
                        }else{
                            newWeight = line.weightP0 * line.weightP1;
                        }
                        if(edge==2)
                        {
                            if(lineLists.get(0).operation=='+')
                                sum = lineLists.get(0).weightP0+lineLists.get(0).weightP1;
                            else
                                sum = lineLists.get(0).weightP0*lineLists.get(0).weightP1;
                        }
                        lineLists.remove(line);
                        --edge;
                        updateList(newWeight,line.x0,line.y0,line.x1,line.y1);//更新边集

                        System.out.println(line.contains(x,y));
                        System.out.println(".....sueeccd");
                        System.out.println("listSize::"+lineLists.size());
                        break;
                    }
                }
                if (edge==1) {

                    JOptionPane.showMessageDialog(null, "Your total score is:  "+sum+"  !", "恭喜", JOptionPane.INFORMATION_MESSAGE);
                    tabbedPane.setSelectedIndex(-1);
                }
                repaint();

            }
        }

        /* (non-Javadoc)
         * @see java.awt.event.MouseListener#mousePressed(java.awt.event.MouseEvent)
         */
        @Override
        public void mousePressed(MouseEvent e) {
            // TODO Auto-generated method stub

        }

        /* (non-Javadoc)
         * @see java.awt.event.MouseListener#mouseReleased(java.awt.event.MouseEvent)
         */
        @Override
        public void mouseReleased(MouseEvent e) {
            // TODO Auto-generated method stub

        }

        /* (non-Javadoc)
         * @see java.awt.event.MouseListener#mouseEntered(java.awt.event.MouseEvent)
         */
        @Override
        public void mouseEntered(MouseEvent e) {
            // TODO Auto-generated method stub

        }

        /* (non-Javadoc)
         * @see java.awt.event.MouseListener#mouseExited(java.awt.event.MouseEvent)
         */
        @Override
        public void mouseExited(MouseEvent e) {
            // TODO Auto-generated method stub

        }

    }


    public void initMyList(int edge){
        GenPoints genpoints = new GenPoints(edge,50);
        genpoints.tranformByCenter(200,200);
        xs = genpoints.xs;
        ys = genpoints.ys;

        if (!lineLists.isEmpty()) {
            lineLists.clear();
        }
        System.out.println("initList");
        for (int i = 0; i < xs.size(); i++) {
            if (i==xs.size()-1) {
                inLine = new MyLine();
                inLine.x0 = xs.get(i).intValue();
                inLine.y0 = ys.get(i).intValue();
                inLine.x1 = xs.get(0).intValue();
                inLine.y1 = ys.get(0).intValue();

                inLine.operation=op[i].charAt(0);

                inLine.weightP0=weights[i];
                inLine.weightP1=weights[0];
                lineLists.add(inLine);
            }else{
                inLine = new MyLine();
                inLine.x0 = xs.get(i).intValue();
                inLine.y0 = ys.get(i).intValue();
                inLine.x1 = xs.get(i+1).intValue();
                inLine.y1 = ys.get(i+1).intValue();

                inLine.operation=op[i].charAt(0);

                inLine.weightP0=weights[i];
                inLine.weightP1=weights[i+1];
                lineLists.add(inLine);
            }

        }

    }

    public void updateList(int newWeight, int x0, int y0, int x1, int y1){
        GenPoints genpoints = new GenPoints(edge,50);
        genpoints.tranformByCenter(200,200);
        xs = genpoints.xs;
        ys = genpoints.ys;
        System.out.println(x0+" "+y0+" "+x1+" "+y1);

        for (int i = 0; i < lineLists.size(); i++) {
            // System.out.println("....lists:"+lineLists.get(i).x0+"
            // "+lineLists.get(i).y0+" "+lineLists.get(i).x1+"
            // "+lineLists.get(i).y1);
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
                if (i == lineLists.size() - 1) {
                    lineLists.get(i).x0 = xs.get(i).intValue();
                    lineLists.get(i).y0 = ys.get(i).intValue();
                    lineLists.get(i).x1 = xs.get(0).intValue();
                    lineLists.get(i).y1 = ys.get(0).intValue();
                } else {
                    lineLists.get(i).x0 = xs.get(i).intValue();
                    lineLists.get(i).y0 = ys.get(i).intValue();
                    lineLists.get(i).x1 = xs.get(i + 1).intValue();
                    lineLists.get(i).y1 = ys.get(i + 1).intValue();
                }
            } else {

            }

        }
    }


    //将text输入的序列分割成int数组
    public int[] toIntArr(String s){
        String[] t =s.split(",");
        int[] a = new int[t.length];
        for (int i = 0; i < t.length; i++) {
            a[i]=Integer.parseInt(t[i]);
        }
        return a;
    }

    //将text输入的序列分割成String数组
    public String[] toCharArr(String s){
        String[] t =s.split(",");
        return t;
    }
    int routArr[];
    public void  getRoute(){
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
        operaArr.add(0,operaArr.get(operaArr.size()-1));
        operaArr.remove(operaArr.size()-1);
        PolygonSolver solver = new PolygonSolver(weightArr,operaArr);
        solver.findSolution();
        ArrayList<Integer> route = solver.getMaxRoute();
        routArr = new int[route.size()];
        for(int i=0;i<route.size();i++)
            routArr[i] = route.get(i);

    }


}
