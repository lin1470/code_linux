<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
    int x;
    java.util.Random r=new java.util.Random();
    for(int i=0;i<6;i++)
    {
        x=(r.nextInt()>>>1)%10;
        out.print(x);
    }
%>