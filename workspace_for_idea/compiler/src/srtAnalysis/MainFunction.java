package srtAnalysis;

import java.util.Vector;

public class MainFunction {

    /**
     * @param args
     * @author Seam
     */

    Algorithm alt;
    String addr,addr2, addrRead, addrWrite;
    Vector<Subt> vt;
    int timeLength;
    boolean check;

    public MainFunction(){
        alt = new Algorithm();
        addr = "src/srtAnalysis/subtitle.srt";
        addr2 = "src/srtAnalysis/subtitle2.srt";
        //读入字幕内容到内存中
        System.out.println("读入字幕文件……(进行词法语法分析）");
        vt = alt.Read(addr);
        System.out.println("完成读入。");
//
//		//整体字幕内容增加2S
        System.out.println("字幕推迟两秒。");
        timeLength = 2;
        alt.CaptionTranslation(vt, timeLength);

        //写回subtitle.srt文件中
        System.out.println("修改完成，保存文件subtitle2.srt");
        addrRead = "src/srtAnalysis/subtitle.srt";
        addrWrite = "src/srtAnalysis/subtitle_backup.srt";
//		alt.BackupsRestore(addrRead, addrWrite);//写回前提前备份好一份
        check = alt.Write(vt, addr2);
        System.out.println("写入文件完成！");
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        new MainFunction();
    }

}