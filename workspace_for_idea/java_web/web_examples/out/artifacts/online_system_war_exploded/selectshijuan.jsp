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
<div style="margin-left: 400px"><h3>请选择试卷等级：</h3></div>
<div style="text-align: center">
<form action="TikuServer" method="post">
<select name="level" >
			<option value="chuji">初级</option>
			<option value="zhongji">中级</option>
			<option value="gaoji">高级</option>
		</select><br><br><br><br><br><br>
		<input type="submit" value="确定" >
</form>
</div>
</body>
</html>