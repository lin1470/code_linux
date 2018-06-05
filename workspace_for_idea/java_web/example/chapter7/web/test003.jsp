<%@ page import="java.util.Map" %>
<%@ page import="java.util.HashMap" %><%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/12/17
  Time: 11:04 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>test003</title>

</head>
<body>
<%
    Map<String,String> cityMap=new HashMap<String,String>();
    cityMap.put("1","zhengzhou");
    cityMap.put("2","beijing");
    cityMap.put("3","chongqing");
    cityMap.put("4","chengdu");
    application.setAttribute("cities",cityMap);
%>
${applicationScope.cities["2"]}
${1==4}
${pageContext.request.requestURI}
${param.user}
<br>
${header["user-agent"]}
<br>
${initParam.user}
${"wohso"}

</body>
</html>
