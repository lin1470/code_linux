<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<script>alert("hello world");</script>

<script>alert("hello world2");</script>
<%
	System.out.println("dgjs");
	int i=0;
	while(i<3){
		i++;
		%>
		<script>alert("i=");</script>
		<% 
		System.out.println("i="+i);
		
		
	}
%>
<script>alert("hello world3");</script>
</body>
</html>