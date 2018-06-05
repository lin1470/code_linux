<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/26/17
  Time: 11:44 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>成绩</title>
</head>
<body>
<%
    String number1=request.getParameter("number1");
    String number2=request.getParameter("number2");
    String number3=request.getParameter("number3");
    String number4=request.getParameter("number4");
    String number5=request.getParameter("number5");
    int score=0;
%>
<strong>你的答案为：</strong>
1.<%
    if(!number1.equals("B")){
        out.print("<span style='background-color:red;'>"+number1+"</span><br>");
    }
    else{
        out.print(number1+"<br>");
        score+=20;
    }
%>
2.<%
    if(!number2.equals("B")){
        out.print("<span style='background-color:red;'>"+number2+"</span><br>");
    }
    else{
        out.print(number2+"<br>");
        score+=20;
    }
%>


3.<%
    if(!number3.equals("A")){
        out.print("<span style='background-color:red;'>"+number3+"</span><br>");
    }
    else{
        out.print(number3+"<br>");
        score+=20;
    }
%>
4.<%
    if(!number4.equals("D")){
        out.print("<span style='background-color:red;'>"+number4+"</span><br>");
    }
    else{
        out.print(number4+"<br>");
        score+=20;
    }
%>
5.<%
    if(!number5.equals("C")){
        out.print("<span style='background-color:red;'>"+number5+"</span><br>");
    }
    else{
        out.print(number5+"<br>");
        score+=20;
    }
%>
<div style="background-color: blue;font-size: large;font-weight: bolder;">
<strong>你的总成绩为：</strong>
<%=score%><br>
</div>
</body>
</html>
