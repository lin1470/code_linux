package com;

public class place 
{
	private String start;
	private String end;
	private String arr[];
	private double code1;
	private double code2;
	public String getStart() {
		return start;
	}
	public void setStart(String start) {
		this.start = start;
	}
	public String getEnd() {
		return end;
	}
	public void setEnd(String end) {
		this.end = end;
	}
	public String[] getArr() {
		//System.out.print(arr[0]);
		return arr;
	}
	public void setArr(String[] arr) {
		this.arr = arr;
	}
	
	public double getX(int i){
		double x=0;
		switch(i){
			case 0:
				x=116.638039;//东门
				break;
				
			case 1:
				x=116.63776;//四饭
				break;
			case 2:
				x=116.635056;//法院
				break;
			case 3:
				x=116.638103;//g座
				break;
			
		}
		return x;
	}
	public double getY(int i){
		double y=0;
		switch(i){
			case 0:
				y=23.41094;//东门
				break;
				
			case 1:
				y=23.411964;//四饭
				break;
			case 2:
				y=23.413027;//法院
				break;
			case 3:
				y=23.412368;//g座
				break;
			
		}
		return y;
	}
	public double getCode1() {
	
		return code1;
	}
	public void setCode1(double code1) {
		
		this.code1 = code1;
	}
	public double getCode2() {
		return code2;
	}
	public void setCode2(double code2) {
		this.code2 = code2;
	}
	

	
}
