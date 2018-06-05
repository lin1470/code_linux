package srtAnalysis;

/*
定义时间的类
 */

public class Time {
    private int hour;
    private int minute;
    private int second;
    private int msecond;


    public int getHour() {
        return hour;
    }
    public void setHour(int hour) {
        this.hour = hour;
    }
    public int getMinute() {
        return minute;
    }
    public void setMinute(int minute) {
        this.minute = minute;
    }
    public int getSecond() {
        return second;
    }
    public void setSecond(int second) {
        this.second = second;
    }
    public int getMsecond() {
        return msecond;
    }
    public void setMsecond(int msecond) {
        this.msecond = msecond;
    }
}
