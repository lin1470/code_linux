<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/12/17
  Time: 10:25 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>test001</title>
</head>
<body>
<%String [] cities={"zhengzhou","beijing","chongqing","chengdu"};
    request.setAttribute("cities",cities);
%>
<%String[] getCities=(String[])request.getAttribute("cities");
    for(int i=0;i<getCities.length;i++){
        request.setAttribute("i",i);
%>
[${i}]:${cities[i]}<br>
<%} %>
</body>
</html>
