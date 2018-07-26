package com.itzcn.bean;

public class MyBean {
	
	private String name = null;//�û���
	private String pass = null;//����
	private int count = 0;//��¼����
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPass() {
		return pass;
	}
	public void setPass(String pass) {
		this.pass = pass;
	}
	public int getCount() {
		count ++;//if you call this function, the count will add 1.
		return count;
	}
	public void setCount(int count) {
		this.count = count;
	}
	
}
