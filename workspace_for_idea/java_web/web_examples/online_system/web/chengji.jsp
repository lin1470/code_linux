<%@page import="dao.ChengJiDao"%>
<%@page import="bean.ChengjiBean"%>
<%@page import="bean.UserBean"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<div style='border:1px dashed red; padding:60px 0; margin:30px;text-align: center'>
		<div>
		<h3>您本次考试的成绩为：<span style='color:red'><%=request.getAttribute("score")%></span>&nbsp;分</h3>
		</div>
		<%UserBean user=(UserBean)application.getAttribute("llguser");
		ChengjiBean cj=new ChengjiBean();
		cj.setUsername(user.getUsername());
		cj.setLevel(application.getAttribute("sellevel").toString());
		String ss=request.getAttribute("score").toString();
		float sc=Float.parseFloat(ss);
		cj.setScore(sc);
		ChengJiDao cjdao=new ChengJiDao();
		cjdao.addChengji(cj);
		%>
		<a  href='xinxi.jsp'>返回</a>
		&nbsp;&nbsp;&nbsp;&nbsp;<a  href='login.jsp'>注销</a>
		</div>
</body>
</html>