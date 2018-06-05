package bean;

import java.io.Serializable;

public class UserBean implements Serializable{
	private static final long serialVersionUID = 1L;
	 private String zcusername;
	 private String zcpassword;
	 private String sex;
	 private String level;
	 
	 public void setUsername(String zcusername){
		 this.zcusername=zcusername;
	 }
	 public void setPassword(String zcpassword){
		 this.zcpassword=zcpassword;
	 }
	 public void setSex(String sex){
		 this.sex=sex;
	 }
	 public void setLevel(String level){
		 this.level=level;
	 }
	 public String getUsername(){
		 return zcusername;
	 }
	 public String getPassword(){
		 return zcpassword;
	 }
	 public String getSex(){
		 return sex;
	 }
	 public String getLevel(){
		 return level;
	 }
	}