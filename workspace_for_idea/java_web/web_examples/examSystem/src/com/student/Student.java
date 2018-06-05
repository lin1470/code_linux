package com.student;

/**
 * Created by bruce on 5/23/17.
 */
public class Student {
    private String account=null;
    private String password=null;
    private String name=null;
    private String idNumber=null;
    private String eMail=null;

    public Student(String account, String password, String name, String idNumber, String eMail) {
        this.account = account;
        this.password = password;
        this.name = name;
        this.idNumber = idNumber;
        this.eMail = eMail;
    }

    public Student() {
    }

    public String geteMail() {
        return eMail;
    }

    public void seteMail(String eMail) {
        this.eMail = eMail;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getIdNumber() {
        return idNumber;
    }

    public void setIdNumber(String idNumber) {
        this.idNumber = idNumber;
    }
}
