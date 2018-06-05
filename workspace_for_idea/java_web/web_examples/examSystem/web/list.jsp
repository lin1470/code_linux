<%@ page import="com.student.Student" %>
<%@ page import="java.util.List" %><%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/24/17
  Time: 4:51 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>list</title>
</head>
<body>
<table border="1" cellpadding="1" cellspacing="1">
    <tr>
        <td align="center"colspan="4"><h2>查看人员信息</h2></td>
    </tr>
    <tr align="center" style="font-weight:bold;">
        <td width="20%">账号</td>
        <td width="20%">姓名</td>
        <td>学号</td>
        <td>邮箱</td>
    </tr>
        <%
            List<Student> lt=(List<Student>) application.getAttribute("students");
            if(lt!=null){
                for(Student student:lt){%>
                    <tr align="center">
                        <td><%=student.getAccount()%></td>
                        <td><%=student.getName()%></td>
                        <td><%=student.getIdNumber()%></td>
                        <td><%=student.getPassword()%></td>
                    </tr>
                <% }
}
%>


</table>
</body>
</html>
