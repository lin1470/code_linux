<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>

<%@   page   import= "com.test "%>
<%@   page   import= "com.FLOYD "%>
<%@   page   import= "com.Way "%>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>


<%!
 	
%>

<%


	int[] a = new int[5];
	a[0]=1;
	a[1]=5;
	a[2]=2;
	a[3]=7;
	a[4]=3;
	
	Way.ShowWay(a);
	System.out.println("hello");
	
%>



</body>
</html>