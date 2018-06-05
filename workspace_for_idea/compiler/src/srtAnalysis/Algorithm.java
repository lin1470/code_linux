package srtAnalysis;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;

import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.channels.FileChannel;
import java.util.Vector;

public class Algorithm{

    public Vector<Subt> Read(String addr){//从subtitle.srt中读取数据
        FileInputStream fis = null;
        InputStreamReader isr = null;
        BufferedReader br = null;
        String line = "";//从文件一行一行地读入内存
        int count = 1;//记录每一小节内容
        Subt sb = null;
        Time begin = null;//记录开始时间对象
        Time end = null;//记录结束时间对象
        String[] strA = null;
        String[] strB = null;
        String[] strC = null;
        String content = "";
        Vector<Subt> vt = new Vector<Subt>();
        try {
            fis = new FileInputStream(addr);
            isr = new InputStreamReader(fis, "UTF-8");
            br = new BufferedReader(isr);
            while((line=br.readLine())!=null){
//				System.out.println(line.length()+" : "+line);
                if(count < 3){
                    if(count == 1){
                        sb = new Subt();
                        line = line.replaceAll(" ", "");
                        sb.setSid(Integer.parseInt(line));
                        count++;
                    }else{
                        begin = new Time();
                        strA = line.split(" --> ");
                        strB = strA[0].split(",");
                        strC = strB[0].split(":");
                        begin.setMsecond(Integer.parseInt(strB[1]));
                        begin.setHour(Integer.parseInt(strC[0]));
                        begin.setMinute(Integer.parseInt(strC[1]));
                        begin.setSecond(Integer.parseInt(strC[2]));
                        sb.setBegin(begin);

                        end = new Time();
                        strB = strA[1].split(",");
                        strC = strB[0].split(":");
                        end.setMsecond(Integer.parseInt(strB[1]));
                        end.setHour(Integer.parseInt(strC[0]));
                        end.setMinute(Integer.parseInt(strC[1]));
                        end.setSecond(Integer.parseInt(strC[2]));
                        sb.setEnd(end);

                        count++;
                    }
                }else{
                    content+=line+"\r\n";
                    if(line.length() > 0){
                        count++;
                    }else{
                        sb.setContent(content);
                        vt.add(sb);
                        content = "";
                        count = 1;
                    }

                }//最外层if{}else{}

            }//while循环结束
//			this.print(vt);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }finally{
            try {
                br.close();
                isr.close();
                fis.close();
            } catch (Exception e2) {
                // TODO: handle exception
                e2.printStackTrace();
            }
        }


        return vt;
    }

    public boolean Write(Vector<Subt> vt,String addr){//把内容写回subtitle.srt中
        FileOutputStream fos = null;
        OutputStreamWriter osw = null;
        BufferedWriter bw = null;
        Subt sb = null;
        Time begin = null;
        Time end = null;
        int[] temp = null;
        String[] strA = null;
        try {
            fos = new FileOutputStream(addr);
            osw = new OutputStreamWriter(fos, "UTF-8");
            bw = new BufferedWriter(osw);
            temp = new int[8];
            strA = new String[8];

            for(int i=0; i<vt.size(); i++){
                sb = vt.get(i);
                temp[0]=sb.getBegin().getHour();
                temp[1]=sb.getBegin().getMinute();
                temp[2]=sb.getBegin().getSecond();
                temp[3]=sb.getEnd().getHour();
                temp[4]=sb.getEnd().getMinute();
                temp[5]=sb.getEnd().getSecond();
                temp[6]=sb.getBegin().getMsecond();
                temp[7]=sb.getEnd().getMsecond();

                for(int j=0; j<6; j++){
                    if(temp[j]<10){
                        strA[j] = "0"+temp[j];
                    }else{
                        strA[j] = temp[j]+"";
                    }
                }
                for(int j=6; j<8;j++){
                    if(temp[j]<10){
                        strA[j] = "00"+temp[j];
                    }else if(temp[j]<100){
                        strA[j] = "0"+temp[j];
                    }else{
                        strA[j] = temp[j]+"";
                    }
                }
                bw.write(sb.getSid()+" \r\n");
                bw.write(strA[0]+":"+strA[1]+":"+strA[2]+","+strA[6]+" --> "+strA[3]+":"+strA[4]+":"+strA[5]+","+strA[7]+"\r\n");
                bw.write(sb.getContent());
            }
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            return false;
        }finally{
            try {
                bw.close();
                osw.close();
                fos.close();
            } catch (Exception e2) {
                // TODO: handle exception
                e2.printStackTrace();
            }
        }
        return true;
    }

    public void BackupsRestore(String addrRead,String addrWrite){//内容备份，还原
        FileInputStream fi = null;
        FileOutputStream fo = null;
        FileChannel in = null;
        FileChannel out = null;
        File s,t;
        try {
            s = new File(addrRead);
            t = new File(addrWrite);
            fi= new FileInputStream(s);
            fo = new FileOutputStream(t);
            in = fi.getChannel();//得到对应文件通道
            out = fo.getChannel();//得到对应文件通道
            in.transferTo(0, in.size(), out);
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }finally{
            try {
                fi.close();
                fo.close();
                in.close();
                out.close();

            } catch (Exception e2) {
                // TODO: handle exception
                e2.printStackTrace();
            }
        }//finally 结束
    }

    public Vector<Subt> CaptionTranslation(Vector<Subt> vt,int timeLength){

        Subt sb = null;
        Time begin = null;
        Time end = null;

        for(int i=0; i<vt.size(); i++){
            sb = vt.get(i);
            begin = sb.getBegin();
            end = sb.getEnd();
            this.cal(begin, timeLength);
            this.cal(end, timeLength);
        }
//		this.print(vt);
        return vt;//字母平移（例如，将字幕整体推迟2秒）功能
    }

    public void cal(Time tm,int timeLength){
        if(tm.getSecond()<60-timeLength){
            tm.setSecond(tm.getSecond()+timeLength);
        }else{
            tm.setSecond((tm.getSecond()+timeLength)%60);
            if(tm.getMinute()<59){
                tm.setMinute(tm.getMinute()+1);
            }else{
                tm.setMinute(0);
                tm.setHour(tm.getHour()+1);
            }
        }
    }

    public void print(Vector<Subt> vt){//打印处理结果
        Subt sb = null;
        Time begin = null;
        Time end = null;
        int[] temp = new int[8];
        String[] strA = new String[8];

        for(int i=0; i<vt.size(); i++){
            sb = vt.get(i);
            temp[0]=sb.getBegin().getHour();
            temp[1]=sb.getBegin().getMinute();
            temp[2]=sb.getBegin().getSecond();
            temp[3]=sb.getEnd().getHour();
            temp[4]=sb.getEnd().getMinute();
            temp[5]=sb.getEnd().getSecond();
            temp[6]=sb.getBegin().getMsecond();
            temp[7]=sb.getEnd().getMsecond();

            for(int j=0; j<6; j++){
                if(temp[j]<10){
                    strA[j] = "0"+temp[j];
                }else{
                    strA[j] = temp[j]+"";
                }
            }
            for(int j=6; j<8;j++){
                if(temp[j]<10){
                    strA[j] = "00"+temp[j];
                }else if(temp[j]<100){
                    strA[j] = "0"+temp[j];
                }else{
                    strA[j] = temp[j]+"";
                }
            }
            System.out.print(sb.getSid()+" \r\n");
            System.out.print(strA[0]+":"+strA[1]+":"+strA[2]+","+strA[6]+" --> "+strA[3]+":"+strA[4]+":"+strA[5]+","+strA[7]+"\r\n");
            System.out.print(sb.getContent());
        }
    }

}
