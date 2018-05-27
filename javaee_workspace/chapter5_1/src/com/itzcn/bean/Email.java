package com.itzcn.bean;
import java.io.Serializable;
public class Email implements Serializable {

	private static final long serialVersionUID = 1L;
	private String mail=null; //the address of Email
	private boolean isMail=false;//status that indicates is Email or not
	public Email(){// default constructor with no arguments
		super();
	}
	public Email(String mail){
		this.mail=mail;
	}
	public String getMail(String mail){
		return mail;
	}
	public void setMail(String mail){
		this.mail=mail;
	}
	public boolean isMail(){
		String regex="^([a-z0-9A-Z]+[-|\\.]?)+[a-z0-9A-Z]@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-zA-Z]{2,}$";
		//regular expression
		if(mail.matches(regex)){
			isMail=true;
		}
		return isMail;
	}
	public void setMail(boolean isMail)
	{
		this.isMail=isMail;
	}
}








