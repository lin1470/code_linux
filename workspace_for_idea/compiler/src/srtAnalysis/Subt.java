package srtAnalysis;

/*
定义了字幕的类，这个这个类中包含了sid,begin,end,content
其中sid是指定的是节点的序号。
 */

public class Subt {
    private int sid;
    private Time begin;
    private Time end;
    private String content;

    public int getSid() {
        return sid;
    }
    public void setSid(int sid) {
        this.sid = sid;
    }
    public Time getBegin() {
        return begin;
    }
    public void setBegin(Time begin) {
        this.begin = begin;
    }
    public Time getEnd() {
        return end;
    }
    public void setEnd(Time end) {
        this.end = end;
    }
    public String getContent() {
        return content;
    }
    public void setContent(String content) {
        this.content = content;
    }
}
