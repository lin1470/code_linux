import javax.swing.JFrame;
public class firstFrame extends JFrame{
    public static void main(String args[])
    {
        firstFrame frame = new firstFrame();
        frame.setVisible(true);
    }

    public firstFrame(){
        super();
        setTitle("利用鸡肋来创建窗体");
        setBounds(100,100,500,375);
        getContentPane().setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
