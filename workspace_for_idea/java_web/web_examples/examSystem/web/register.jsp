<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/23/17
  Time: 3:53 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册</title>
    <link rel="stylesheet" href="style.css"/>
    <script type="text/javascript">
        function check_password(){
            var password=document.getElementById("password").value;
            var re_password=document.getElementById("re_password").value;
            if(password!==re_password){
                document.getElementById("addInfo").innerHTML="两次输入的密码不一样！";
            }else{
                document.getElementById("addInfo").innerHTML=" ";
            }
        }

    </script>
</head>
<body  style="background: forestgreen; margin-top: 50px;margin-left:500px;">
<h2>欢迎来到注册界面</h2><br>
<form style="margin: 20px;" action="registerServlet" method="post">
    &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp账号：<input type="text" id="account" name="account"/><br>
    &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp密码：<input type="password" id="password" name="password"/><br>

    <span class="front">确认密码：</span><input type="password" id="re_password" name="re_password" onblur="check_password()"/>
    <span id="addInfo">提示</span><br>

    <span class="front">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp姓名：</span><input type="text" name="name"/><br>
    <span class="front">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp学号：</span><input type="text" name="idNumber"/><br>
    <span class="front">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp邮箱：</span><input type="text" name="eMail"/><br>
    <input  style="margin-left:220px;" type="submit" value="提交"><br>
</form>
</body>
</html>
