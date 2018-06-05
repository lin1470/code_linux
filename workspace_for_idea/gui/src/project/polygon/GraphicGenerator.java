package project.polygon;
import java.lang.Math;
import java.util.ArrayList;

public class GraphicGenerator {
    private int numOfEdge;
    private int upperBound;
    private int lowerBound;
    private ArrayList<Integer> nums;    // 各点权值
    private ArrayList<Character> opts;  // operators的缩写，原谅我强迫症希望对齐

    public GraphicGenerator(){
        this.numOfEdge = 5;
        this.lowerBound = -25;
        this.upperBound = 25;
        this.nums = new ArrayList<>();
        this.opts = new ArrayList<>();
    }

    public GraphicGenerator(int numOfEdge, int lowerBound, int upperBound){
        this.numOfEdge = numOfEdge;
        this.lowerBound = lowerBound;
        this.upperBound = upperBound;
        this.nums = new ArrayList<>();
        this.opts = new ArrayList<>();
        randomGenNums();
        randomGenOpts();
    }

    private void randomGenNums(){
        int num;
        for(int i=0; i<numOfEdge; i++){
            num = (int) (lowerBound + Math.random() * (upperBound - lowerBound));
            nums.add(num);
        }
    }

    private void randomGenOpts(){
        char opt;
        for(int i=0; i<numOfEdge; i++){
            opt = (Math.random()>=0.5)? '*': '+';
            opts.add(opt);
        }
    }

    public ArrayList<Integer> getNums() {
        return nums;
    }

    public ArrayList<Character> getOpts() {
        return opts;
    }

    public String toString(){
        StringBuilder stringBuilder = new StringBuilder();

        for(int i: this.getNums()){
            stringBuilder.append(String.format("%d ",i));
        }
        stringBuilder.append("\n");

        for(int i=0; i<this.getOpts().size(); i++){
            stringBuilder.append(String.format("第%d边上符号: %c\n", i, this.getOpts().get(i)));
        }

        return stringBuilder.toString();
    }

    public static void main(String args[]){
        GraphicGenerator graphicGenerator = new GraphicGenerator(5, -10, 20);
        System.out.print(graphicGenerator.toString());

    }

}
