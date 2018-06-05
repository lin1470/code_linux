<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title name="zhuce">注册</title>
<script type="text/javascript">
function isRegisterUserName()
{ 
var username=document.getElementById("zcuser_name").value;
var patrn=/^[a-zA-Z]{1}([a-zA-Z0-9]|[._]){4,19}$/;
if (username==''||!patrn.exec(username)){
alert("用户名格式不对！");
return false;
}
return true ;
}
function isPasswd()
{ 
var password=document.getElementById("zcpassword").value;
var patrn=/^(\w){6,20}$/;
if (password==' '||!patrn.exec(password)){
alert("密码格式不对！");
return false;
}
return true ;
}
function ensurePassword(){
	var ensurepass=document.getElementById("ensurepass").value;
	var password=document.getElementById("zcpassword").value;
	if(ensurepass!=password){
		alert("两次输入的密码不一样！");
		return false;
	}
	else return true;
}
function gotoLogin(){
	window.open("login.jsp","_self");
}
function isRegister(){
	var message="<%=request.getAttribute("mes")%>";
	alert(message);
}
</script>
</head>
<body style="background:#56a9a9;">
<div id="mainDiv" style=" width: 100%;height:100%;">
<div style="margin-left:300px;margin-top:100px;"><h2>注册账号</h2></div>
<div id="zhuceDiv" style="width:500px;height:400px; margin: 0 auto;">
	<form id="zheceFrom" action="ZhuceServer" method="post">
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;账号：<input type="text" id="zcuser_name" name="zcusername" placeholder="必须字母开头,不少于5位" onchange="isRegisterUserName()" ><br><br><br>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;密码：<input type="password" id="zcpassword" name="zcpassword" placeholder="不少于6位" onchange="isPasswd()"><br><br><br>
		确认密码：<input type="password" id="ensurepass" name="ensurepass" onchange="ensurePassword()"><br><br><br>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;性别:&nbsp;&nbsp;<select name="sex">
			<option value="man">男</option>
			<option value="woman">女</option>
		</select><br><br><br>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;等级：<select name="level">
			<option value="chuji">初级</option>
			<option value="zhongji">中级</option>
			<option value="gaoji">高级</option>
		</select><br><br><br>
		<input type="submit" value="注册" style="margin-left: 250px;">
		<input type="button" value="取消" onclick="gotoLogin()">
	</form>
</div>
</div>
</body>
</html>