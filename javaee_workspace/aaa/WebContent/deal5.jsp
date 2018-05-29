<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<jsp:useBean id="place" class="com.place" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="place"/>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Version5</title>
</head>
<body>
<% 
out.print(place.getStart());
out.print(place.getEnd());
%>

</body>
</html>