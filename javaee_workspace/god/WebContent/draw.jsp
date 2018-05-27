<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no, width=device-width">
    <title>折线、多边形、圆</title>
    <link rel="stylesheet" href="http://cache.amap.com/lbs/static/main1119.css"/>
    <script src="http://webapi.amap.com/maps?v=1.3&key=1aab8f31adcc55b5b2a97e0fa4cbcece"></script>
    <script type="text/javascript" src="http://cache.amap.com/lbs/static/addToolbar.js"></script>
</head>
<body>
<div id="container"></div>
<script>
    var map = new AMap.Map('container', {
        resizeEnable: true,
        zoom:15,
        center: [116.62997999999993, 23.41606]
    });
    var lineArr = [
        [116.638039,23.41094],//东门
        [116.63776,23.411964],//四饭
        [116.635056,23.413027],//法院
        [116.638103,23.412368],//G座
        [116.636183,23.411777],//E座
        [116.633297,23.412732],//大礼堂
        [116.633511,23.413963],//新行政楼
        [116.631258,23.41539],//体育馆
        [116.6304,23.413717],//789
        [116.63334,23.414957],//三饭
        [116.634016,23.415174],//机电楼
		[116.630454,23.41794],//艺术学院
		[116.636505,23.410093]//真理钟
    ];
    var polyline = new AMap.Polyline({
        path: lineArr,          //设置线覆盖物路径
        strokeColor: "#3366FF", //线颜色
        strokeOpacity: 1,       //线透明度
        strokeWeight: 5,        //线宽
        strokeStyle: "solid",   //线样式
        strokeDasharray: [10, 5] //补充线样式
    });
    polyline.setMap(map);

    var polygonArr = new Array();//多边形覆盖物节点坐标数组
    polygonArr.push([116.403322, 39.920255]);
    polygonArr.push([116.410703, 39.897555]);
    polygonArr.push([116.402292, 39.892353]);
    polygonArr.push([116.389846, 39.891365]);
    var  polygon = new AMap.Polygon({
        path: polygonArr,//设置多边形边界路径
        strokeColor: "#FF33FF", //线颜色
        strokeOpacity: 0.2, //线透明度
        strokeWeight: 3,    //线宽
        fillColor: "#1791fc", //填充色
        fillOpacity: 0.35//填充透明度
    });
    polygon.setMap(map);

    var circle = new AMap.Circle({
        center: new AMap.LngLat("116.62997999999993, 23.41606"),// 圆心位置
        radius: 1000, //半径
        strokeColor: "#F33", //线颜色
        strokeOpacity: 1, //线透明度
        strokeWeight: 3, //线粗细度
        fillColor: "#ee2200", //填充颜色
        fillOpacity: 0.35//填充透明度
    });
    circle.setMap(map);
</script>
</body>
</html>