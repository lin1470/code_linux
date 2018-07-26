<%--
  Created by IntelliJ IDEA.
  User: bruce
  Date: 6/12/17
  Time: 8:06 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>考试开始</title>
    <script>
        function createXMLHttpRequest(){
            return new XMLHttpRequest();
        }
        function send(){
            var XmlHttp=createXHTMLHttpRequest();
        }
        function close(){

        }
    </script>
</head>
<body>
<div style=" margin-left:900px;width:200px;"><a href="#">张三</a> <input type="button" onclick="close()" value="注销"/> </div>
<div style="height:30px;text-align:center;background-color: blue;"><span>试卷难度</span>
<select>
    <option>初级</option>
    <option>中级</option>
    <option>高级</option>
</select>
    <input type="button" onclick="send()"value="确定"/>
</div>
<div id="display"style="background-color:burlywood">
    sdfdf
</div>

</body>
</html>
