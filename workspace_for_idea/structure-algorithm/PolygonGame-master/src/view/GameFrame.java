package view;

import controller.Game;
import controller.PolygonManager;
import controller.StateBackup;

import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.io.File;

class GameFrame extends JFrame {

    private StateBackup backup;
    private PolygonManager polygonManager;
    private PolygonCanvas polygonCanvas;
//    private Game game;



    private long sleepTime = 3500;
    private boolean hasPolygon = false;

    private JTextField fromText = new JTextField("-20");
    private JTextField toText = new JTextField("20");

    private JLabel scoreLabel = new JLabel("max score:0");
    private JButton genPolygonBtn = new JButton("create poly");
    private JButton replayBtn = new JButton("重玩");

    private JTextField numChooseTextFiled = new JTextField("input index");
    private JButton submitBtn = new JButton("calculate");
    private JButton demoBtn = new JButton("max_score show");

    private ButtonGroup buttonGroup = new ButtonGroup();
    private JRadioButton radios[] = new JRadioButton[10];
    private JButton regretBtn = new JButton("back");
    private JButton chooseBtn = new JButton("browse");
    private JButton saveBtn = new JButton("save");

    private JFileChooser fileChooser = new JFileChooser();
    GameFrame(Game game){
        //Game名存实亡.. 没什么用 以后重构再考虑一下
        //业务逻辑都写在了这个里面...醉了 不能这样的
        //后面学到怎么解决再说
        super();
        polygonManager = game.polygonManager;
        backup = game.backup;
        polygonCanvas = polygonManager.canvas;

        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        int width = (int)dim.getWidth()/2;
        int height = (int)dim.getHeight()-200;
        int size = Math.min(height,width);
        setSize(size,size);
        setLocation((int)(dim.getWidth()-width)/2,50);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel northPanel = new JPanel();
        northPanel.add(new JLabel("range:"));
        northPanel.add(fromText);
        northPanel.add(new JLabel("-"));
        northPanel.add(toText);

        northPanel.add(saveBtn);
        northPanel.add(chooseBtn);
        northPanel.add(genPolygonBtn);
        northPanel.add(scoreLabel);
        northPanel.add(replayBtn);
        northPanel.add(regretBtn);
        add(northPanel,"North");

        add(polygonCanvas,"Center");

        JPanel southPanel = new JPanel();
        JPanel radioPanel = new JPanel();
        for(int i=0;i<10;i++){
            radios[i] = new JRadioButton(""+i);
            buttonGroup.add(radios[i]);
            radioPanel.add(radios[i]);
        }
        radioPanel.setBorder(new TitledBorder("quick_select"));
        southPanel.add(radioPanel);
        numChooseTextFiled.setBorder(new TitledBorder("select"));
        southPanel.add(numChooseTextFiled);
        southPanel.add(submitBtn);
        southPanel.add(demoBtn);

        add(southPanel,"South");

        setVisible(true);
        addAction();
        getRootPane().setDefaultButton(submitBtn);
    }

    private void disableSomeButton(){
        for(JRadioButton rbutton:radios){
            rbutton.setEnabled(false);
        }
        replayBtn.setEnabled(false);
        submitBtn.setEnabled(false);
        regretBtn.setEnabled(false);
        demoBtn.setEnabled(false);
    }

    private void enableSomeButton(){
        replayBtn.setEnabled(true);
        submitBtn.setEnabled(true);
        regretBtn.setEnabled(true);
        demoBtn.setEnabled(true);
        disableSomeRadio(polygonManager.polygon.getEdges().size());
    }

    private void waitEnableSomeButton(long sleepTime){
        new Thread(() ->{
            try {
                Thread.sleep(sleepTime);
                enableSomeButton();
                disableSomeRadio(polygonManager.polygon.getEdges().size());
            } catch (InterruptedException e1) {
                e1.printStackTrace();
            }

        }).start();
    }

    private void disableSomeRadio(int num){
        for(JRadioButton radioButton:radios)
            radioButton.setEnabled(true);
        if(num<10){
            for(int i=9;i>=num;i--){
                radios[i].setEnabled(false);
            }
        }
    }
    private void addAction(){
        genPolygonBtn.addActionListener((actionEvent) ->{
            String numS = JOptionPane.showInputDialog(this,
                    "input the number of vertexs");
            if(numS==null)
                return;
            try{
                int from = Integer.parseInt(fromText.getText());
                int to  = Integer.parseInt(toText.getText());
                int num = Integer.parseInt(numS);
                if(num<=0)
                    throw new NumberFormatException();
                disableSomeRadio(num);
                polygonManager.randomGen(num,from,to);
                polygonCanvas.display(polygonManager.getPolygon());
                hasPolygon = true;
                backup.storeInit(polygonManager);
                enableSomeButton();
            }catch (NumberFormatException e){
                JOptionPane.showMessageDialog(this,
                        "input a integer");
            } catch (CloneNotSupportedException e) {
                e.printStackTrace();
            }

        });

        numChooseTextFiled.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                numChooseTextFiled.selectAll();
            }

            @Override
            public void focusLost(FocusEvent e) {

            }
        });

        for(int i=0;i<10;i++){
            radios[i].addActionListener((e) ->{
                if(!hasPolygon){
                    JOptionPane.showMessageDialog(this,
                            "please create the poly");
                    return;
                }
                JRadioButton btn =(JRadioButton) e.getSource();
                if(btn.isSelected()){
                    try {
                        backup.store(polygonManager);
                    } catch (CloneNotSupportedException e1) {
                        e1.printStackTrace();
                    }
                    model.Polygon polygon = polygonManager.getPolygon();
                    new Thread(() -> {
                        polygonManager.choose(
                                polygon.getEdges().get(
                                        Integer.parseInt(btn.getText()))
                        );
                        enableSomeButton();
                    }).start();
                    disableSomeButton();
//                    waitEnableSomeButton();
                }
                buttonGroup.clearSelection();

            });
        }

        submitBtn.addActionListener((e) ->{
            if(!hasPolygon){
                JOptionPane.showMessageDialog(this,
                        "please create the poly");
                return;
            }
            String text = numChooseTextFiled.getText();
            try{
                backup.store(polygonManager);
                int num = Integer.parseInt(text);
                model.Polygon polygon = polygonManager.getPolygon();
                if(num>=polygon.getEdges().size()){
                    JOptionPane.showMessageDialog(this,
                            "check the number");
                    return;
                }
                disableSomeButton();
                new Thread(() ->{
                    polygonManager.choose(polygon.getEdges().get(num));
                    enableSomeButton();
                } ).start();

                buttonGroup.clearSelection();
            }catch (NumberFormatException ex){
                numChooseTextFiled.setText("num");
                JOptionPane.showMessageDialog(this,"integer");

            } catch (CloneNotSupportedException e1) {
                e1.printStackTrace();
            }
            numChooseTextFiled.selectAll();
        });

        demoBtn.addActionListener((ActionEvent event) ->{
            if(!hasPolygon){
                JOptionPane.showMessageDialog(this,
                        "please create the poly first");
                return;
            }
            PolygonManager temp;
            try {
                temp = backup.init.copy();
                polygonCanvas.display(temp.polygon);
                temp.calBest();
                polygonCanvas.max = temp.maxScore;
                scoreLabel.setForeground(Color.red);
                scoreLabel.setText("max score:"+temp.maxScore);
                scoreLabel.setForeground(Color.black);
                temp.showDemo();
                disableSomeButton();
                waitEnableSomeButton(sleepTime*(polygonManager.polygon.getEdges().size()-1));
//                int seq[] = temp.bestSeq;
//                System.out.print("seq:");
//                for (int aSeq : seq) System.out.print(aSeq + "   ");
//                System.out.println();
            } catch (CloneNotSupportedException e) {
                e.printStackTrace();
            }


        });

        replayBtn.addActionListener(e -> {

            if(!hasPolygon)
                return;
            try {
                polygonManager = backup.init.copy();
                polygonCanvas.display(polygonManager.polygon);
                enableSomeButton();
            } catch (CloneNotSupportedException e1) {
                e1.printStackTrace();
            }
        });

        regretBtn.addActionListener(e ->{
            PolygonManager temp = backup.recover();
            if(temp!=null)
            {
                polygonManager = temp;
                polygonCanvas.display(polygonManager.polygon);
                disableSomeRadio(polygonManager.polygon.getEdges().size());
            }else
            {
                JOptionPane.showMessageDialog(this,"restarted");
            }
        });

        chooseBtn.addActionListener((e)->{
            fileChooser.showDialog(this,"ok");
            File file = fileChooser.getSelectedFile();
            if(file == null)
                return;
            if(file.isFile())
                try {
                    polygonManager.loadPolygon(file);
                    backup.storeInit(polygonManager);
                    hasPolygon = true;
                }catch (NumberFormatException exp){
                    JOptionPane.showMessageDialog(this,
                            "error file format");
                }catch (CloneNotSupportedException exp){
                    exp.printStackTrace();
                }

        });

        saveBtn.addActionListener((ActionEvent e) ->{
            System.out.println("try to save");
            if(!hasPolygon)
            {
                JOptionPane.showMessageDialog(this,
                        "please create the poly");
                return;
            }
            try {
                polygonManager.polygon = backup.init.copy().polygon;
            } catch (CloneNotSupportedException e1) {
                e1.printStackTrace();
            }
            fileChooser.showDialog(this,"save");
            File file = fileChooser.getSelectedFile();
            if(file==null)
            {
                System.out.println("not save yet");
                return;
            }
//            if(file.isFile()){
//                polygonManager.savePolygon(file.getParentFile(),file.getName());
//                JOptionPane.showMessageDialog(this,
//                        "保存成功");
//            }
            polygonManager.savePolygon(file.getParentFile(),file.getName());
            JOptionPane.showMessageDialog(this,
                    "save successfully!");
        });
    }
}
