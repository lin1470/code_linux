<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/26/17
  Time: 5:02 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
    <title>out</title>
</head>
<body>
<c:out value="<font color='red'>传智播客</font>" > </c:out><br>
<c:out value="<font color='red'>传智播客</font>" > </c:out><br>
<c:set value="黄" var="name1" scope="session"/>
<c:out value="${name1}"/><br>
<c:url value="http://localhost:8080/JSTL" var="url" scope="session"/>
<a href="${url}">Tomcat首页</a>


</body>
</html>
