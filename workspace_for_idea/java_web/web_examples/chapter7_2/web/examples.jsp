<%@ page import="com.el.Adress" %>
<%@ page import="com.el.People" %><%-- automatically import by the idea
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/13/17
  Time: 7:25 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>examples</title>
</head>
<body>
this is a trial!<br>
<%
    Adress adress=new Adress();
    adress.setCity("lianjiang");
    adress.setStreet("dadao");
    People people=new People();
    people.setAdress(adress);
    people.setName("bru");
    people.setSex("male");
    request.setAttribute("people",people);

%>
    ${pageContext.request.contextPath}
</body>
</html>
