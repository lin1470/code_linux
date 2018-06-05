<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/26/17
  Time: 10:15 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>exam</title>
    <script>
        var tFlag=0;
        var tPass=0;
        function timer(id) {
            if (tFlag != 0) {
                var tNew = new Date().getTime();
                tPass = tPass + (tNew - tFlag);
                tFlag = tNew;

            } else {
                tFlag = new Date().getTime();
            }
            setTimeout("timer('" + id + "')", 100);
            var sc = Math.floor((tPass / 1000) % 60);
            var mi = Math.floor((tPass / 1000 / 60) % 60);
            var hr = Math.floor((tPass / 1000/ 60 / 60) % 24);
            var info =hr + "时" + mi + "分" + sc + "秒";
            document.getElementById(id).innerHTML = info;
        }
    </script>

</head>
<body style="margin:50px;margin-left:450px;background-color:lightsalmon" onload="timer('time')">
<h1>考生在线考试系统</h1>
<%
    String degree=request.getParameter("degree");
%>
<div style="position: fixed;top:50px;right:100px;color:red;font-weight: bolder;">难度为：<%=degree%></div>
<h3>选择题</h3>
<%
    if(degree.equals("easy")){
%>
<form action="result.jsp" method="post">
    1.JAVA语言的开发的公司是（）？<br>
    <input type="radio" name="number1" value="A"/>A.微软<br>
    <input type="radio" name="number1" value="B"/>B.SUN公司<br>
    <input type="radio" name="number1" value="C"/>C.甲骨文<br>
    <input type="radio" name="number1" value="D"/>D.谷歌<br>
    2.java的系统的输出流是（）？<br>
    <input type="radio" name="number2" value="A"/>A.out<br>
    <input type="radio" name="number2" value="B"/>B.system.out<br>
    <input type="radio" name="number2" value="C"/>C.print.out<br>
    <input type="radio" name="number2" value="D"/>D.system.print<br>
    3.java声明私有属性的关键字是（）？<br>
    <input type="radio" name="number3" value="A"/>A.private<br>
    <input type="radio" name="number3" value="B"/>B.public<br>
    <input type="radio" name="number3" value="C"/>C.default<br>
    <input type="radio" name="number3" value="D"/>D.protected<br>
    4.Java中int的存储字节大小为（）？<br>
    <input type="radio" name="number4" value="A" />A.1<br>
    <input type="radio" name="number4" value="B" />B.2<br>
    <input type="radio" name="number4" value="C" />C.3<br>
    <input type="radio" name="number4" value="D" />D.4<br>
    5.Java创建一个对象用的关键字是（）？<br>
    <input type="radio" name="number5" value="A"/>A.old<br>
    <input type="radio" name="number5" value="B"/>B.this<br>
    <input type="radio" name="number5" value="C"/>C.new<br>
    <input type="radio" name="number5" value="D"/>D.chuangjian<br>
    <div ><input style="margin-top:20px;margin-left:200px;width:100px;height:25px;font-size:15px;background-color: red;"type="submit" value="提交答案"/><br></div>
</form>
<%
    }else if(degree.equals("hard")){
%>
<form action="result.jsp" method="post">
    1.JAVA的判断字符串内容是否相等用的方法是什么（）？<br>
    <input type="radio" name="number1" value="A"/>A.=<br>
    <input type="radio" name="number1" value="B"/>B.equals()<br>
    <input type="radio" name="number1" value="C"/>C.==<br>
    <input type="radio" name="number1" value="D"/>D.equal()<br>
    2.java的对类名的第一个字母的一般要求是什么（）？<br>
    <input type="radio" name="number2" value="A"/>A.小写字母<br>
    <input type="radio" name="number2" value="B"/>B.大写字母<br>
    <input type="radio" name="number2" value="C"/>C.下划线<br>
    <input type="radio" name="number2" value="D"/>D.字母<br>
    3.Java对指针如何处置（）？<br>
        <input type="radio" name="number3" value="A" />A.没有指针，只有引用<br>
    <input type="radio" name="number3" value="B" />B.和c/c++一样<br>
    <input type="radio" name="number3" value="C" />C.智能指针<br>
    <input type="radio" name="number3" value="D" />D.以上都对<br>
    4.一般我们使用servlet的完整的类名是（）？<br>
    <input type="radio" name="number4" value="A"/>A.servlet<br>
    <input type="radio" name="number4" value="B"/>B.HttpServlet<br>
    <input type="radio" name="number4" value="C"/>C.servlet.http.HttpServlet<br>
    <input type="radio" name="number4" value="D"/>D.javax.servlet.HttpServlet<br>
    5.一般servlet对表单处理的需要的是继承的方法是（）？<br>
    <input type="radio" name="number5" value="A"/>A.servlet();<br>
    <input type="radio" name="number5" value="B"/>B.init();<br>
    <input type="radio" name="number5" value="C"/>C.doPost(HttpServletRequest request,HttpServletResponse response);<br>
    <input type="radio" name="number5" value="D"/>D.doForward(HttpServletRequest request,HttpServletResponse response);<br>
    <input style="margin-top:20px;margin-left:200px;width:100px;height:25px;font-size:15px;background-color: red;"type="submit" value="提交答案" ><br>
    <%
        }
    %>
</form>
<div  style="position:fixed;top:50px;left:50px;"><span id="time" style="background:red;color:blue;text-align: center">我打针的</span></div>
</body>
</html>
