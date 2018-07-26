<%@page import="java.util.List"%>
<%@page import="dao.ChengJiDao"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="bean.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title >用户信息</title>
</head>
<body style="background:#63B8FF;">
<div id="mainDiv" style=" width: 100%;height:100%;">
<div><h2 style="margin-left: 100px">用户信息</h2></div>
<div ><div style="margin-left: 200px">
<form action="selectshijuan.jsp">
<%UserBean user=(UserBean)application.getAttribute("llguser");
String flag;
if(user.getLevel().toString().equals("chuji") )
	flag="初级";
else if(user.getLevel().toString().equals("zhongji"))
	flag="中级";
else flag="高级";
%>
		用户名：<%=user.getUsername() %><br><br>
		当前等级：<%=flag%><br><br>
       初级测试最高分:<%float t=0;
		ChengJiDao cjdao=new ChengJiDao();
		List<ChengjiBean> cjlist=cjdao.queryChengjiByUsername(user.getUsername());
		for(ChengjiBean cjb:cjlist){
			if(cjb.getLevel().equals("chuji")&&(cjb.getScore()>t)){
				t=cjb.getScore();
			//out.print(t+" 分");
			}
		} %><%=t %>&nbsp;分<br><br>
       中级测试最高分:<%float tt=0;
		ChengJiDao ccjdao=new ChengJiDao();
		List<ChengjiBean> ccjlist=cjdao.queryChengjiByUsername(user.getUsername());
		for(ChengjiBean ccjb:cjlist){
			if(ccjb.getLevel().equals("zhongji")&&(ccjb.getScore()>tt)){
				tt=ccjb.getScore();
			out.print(tt+" 分");
			}
		}  %><br><br>
       高级测试最高分:<%
       float tttt=0;
		ChengJiDao cccjdao=new ChengJiDao();
		List<ChengjiBean> cccjlist=cjdao.queryChengjiByUsername(user.getUsername());
		for(ChengjiBean cjb:cccjlist){
			if(cjb.getLevel().equals("gaoji")&&(cjb.getScore()>tttt)){
				tttt=cjb.getScore();
			out.print(tttt+" 分");
			}
		} %><br><br>
<br/><input style="margin-left: 150px" type="submit" value="进行考试" ><br/><br></form>
</div>
</div>
</div>
</html>