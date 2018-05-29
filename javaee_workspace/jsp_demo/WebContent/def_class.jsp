<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>声明一个类</title>
</head>
<body>
<p>请输入一个数:</p>
<br>
<form
name="form" method="post" action="def_class.jsp">
<input type="text" name="number" value="1">
<input type="submit" name="submit" value="送出" >
</form>
<!-- 下面的代码声明一个类SquareROOT -->
<%! public class SquareRoot 
{
	double number;
	SquareRoot(double number)
	{this.number=number;
	}
	double compute()
	{return Math.sqrt(number);
	}
}
%>
<% %>
</body>
</html>