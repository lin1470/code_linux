<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %><%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/12/17
  Time: 10:58 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>test002</title>
</head>
<body>
<% List<String> cities=new ArrayList<String>();
cities.add("zhengzhou");
cities.add("beijing");
cities.add("chongqing");
cities.add("chengdu");
session.setAttribute("cities",cities);
%>
${sessionScope.cities[1]}
</body>
</html>
