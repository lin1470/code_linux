<%@ page import="java.sql.Driver" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="java.sql.SQLException" %>
<%@ page import="java.sql.Connection" %>
<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/15/17
  Time: 12:02 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>test</title>
</head>
<body>
<h2>try to connect to the data base!</h2>
<%
    try{
        Driver driver=new com.mysql.jdbc.Driver();
        DriverManager.registerDriver(driver);
        out.println("successfully\n");

    }catch (SQLException e)
    {
        e.printStackTrace();
        out.print("the driver ran failed!");
    }
%>
<h1>successfully run the driver!</h1>
<%
    try{
        String url="jdbc:mysql://localhost:3306/mydb1";
        Connection connection=DriverManager.getConnection(url,"root","qertu1014");
        out.print("数据库连接成功");
        connection.close();
    }catch(Exception e){
        out.print("数据库连接失败！<br>");
        out.print("错误信息:"+e.toString());

    }
%>
</body>
</html>
