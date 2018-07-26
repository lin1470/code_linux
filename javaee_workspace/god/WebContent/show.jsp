<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!doctype html>
<jsp:useBean id="user" class="com.place" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="place"/>
<html>
<head>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no, width=device-width">
    <title>基本地图展示</title>
    <link rel="stylesheet" href="http://cache.amap.com/lbs/static/main1119.css"/>
    <script src="http://cache.amap.com/lbs/static/es5.min.js"></script>
    <script src="http://webapi.amap.com/maps?v=1.3&key=您申请的key值"></script>
    <script type="text/javascript" src="http://cache.amap.com/lbs/static/addToolbar.js"></script>
</head>
<body>
<div id="container"></div>
<div class='button-group' style="background-color: #0d9bf2;right: 20px">
<form action="deal3.jsp" method="get">
	<select name="start">
							<option value="0">东门</option>
   							<option value="1">四饭</option>
   							<option value="2">法院</option>
   							<option value="3">g座</option>
                            <option value="4">ABCD座</option>
                            <option value="4">ABCD座</option>
                            <option value="5">EF座</option>
                            <option value="6">大礼堂</option>
                            <option value="7">弘毅书院</option>
                            <option value="8">新行政楼</option>
                            <option value="9">体育馆</option>
                            
                        </select>
   	<select name="end">
   							<option value="0">东门</option>
   							<option value="1">四饭</option>
   							<option value="2">法院</option>
   							<option value="3">g座</option>
                            <option value="4">ABCD座</option>
                            <option value="5">EF座</option>
                            <option value="6">大礼堂</option>
                            <option value="7">弘毅书院</option>
                            <option value="8">新行政楼</option>
                            <option value="9">体育馆</option>
                            
                        </select>

	<input type="checkbox" name="arr" value="0"/>东门
	<input type="checkbox" name="arr" value="1"/>四饭
	<input type="checkbox" name="arr" value="2"/>法院
	<input type="checkbox" name="arr" value="3"/>g座
	<input type="checkbox" name="arr" value="4"/>ABCD座
	<input type="checkbox" name="arr" value="5"/>EF座
	<input type="checkbox" name="arr" value="6"/>大礼堂
	<input type="checkbox" name="arr" value="7"/>弘毅书院
	<input type="checkbox" name="arr" value="8"/>新行政楼
	<input type="checkbox" name="arr" value="9"/>体育馆

    <button value="提交" name="submit" type="submit" onclick="">tijiao</button>
    </form>
</div>
<div>
<script>
    var map = new AMap.Map('container', {
        resizeEnable: true,
        zoom:15,
        center: [116.62997999999993, 23.41606]
    });

</script>
</div>

</body>
</html>