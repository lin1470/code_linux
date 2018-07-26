<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 5/12/17
  Time: 11:46 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>calculator</title>
</head>
<body>
<form action="calc.jsp" method="post">
    the first number:<input type="text" name="calc01"><br>
    choose operation:
    <select name="op">
        <option selected="selected" value="+">+</option>
        <option value="-">-</option>
        <option value="*">*</option>
        <option value="/">/</option>

    </select><br>
    the second number:<input type="text" name="calc02"><br>
    <input type="submit" value="calculate">

</form>
<%
    if(request.getParameter("op")!=null){
        String op=request.getParameter("op");
    }
%>
<%if(request.getParameter("op")!=null){
    String op = request.getParameter("op");
%>${param.calc01}${param.op}${param.calc02}=
<%if(op.equals("+")) {%>
${param.calc01+param.calc02  }
<%}else if(op.equals("-")){%>
${param.calc01-param.calc02  }
<%} else if(op.equals("*")){%>
${param.calc01*param.calc02  }
<%}else {%>
${param.calc01/param.calc02  }
<%}} %>
</body>
</html>
