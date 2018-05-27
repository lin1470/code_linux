<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no, width=device-width">
    <jsp:useBean id="place" class="com.place" scope="page"></jsp:useBean>
 	<jsp:setProperty property="*" name="place"/>
    <title>按起终点经纬度规划路线</title>
    <link rel="stylesheet" href="http://cache.amap.com/lbs/static/main1119.css"/>
    <style type="text/css">
        #panel {
            position: fixed;
            background-color: white;
            max-height: 90%;
            overflow-y: auto;
            top: 10px;
            right: 10px;
            width: 280px;
        }
    </style>
    <script type="text/javascript" src="http://webapi.amap.com/maps?v=1.3&key=1aab8f31adcc55b5b2a97e0fa4cbcece&plugin=AMap.Walking"></script>
    <script type="text/javascript" src="http://cache.amap.com/lbs/static/addToolbar.js"></script>
</head>
<body>
<div id="container"></div>
<div id="panel"></div>
<%

String[] picked = request.getParameterValues("arr");
if ((picked!=null)&&(picked.length!=0))
{
	int i=0;
	int num=picked.length;
	while(i<num){
		out.println(picked[i]);
		
		i++;
		
	}
	//out.println(picked[1]);
}

out.print(picked.length);
out.print("ceshi");
out.print(place.getStart());
out.print(place.getEnd());

%>
<script type="text/javascript">

    var map = new AMap.Map("container", {
        resizeEnable: true,
        center: [116.397428, 39.90923],//地图中心点
        zoom: 13 //地图显示的缩放级别
    });
    //步行导航
    var walking = new AMap.Walking({
        map: map,
        panel: "panel"
    }); 
      var walking2 = new AMap.Walking({
        map: map,
        panel: "panel"
    }); 
      var walking3 = new AMap.Walking({
        map: map,
        panel: "panel"
    }); 
    function route( x1,y1,x2,y2){
    		var walking = new AMap.Walking({
    	        map: map,
    	        panel: "panel"
    	    }); 
    		walking.search([x1,y1], [x2,y2]);
    	}
    //根据起终点坐标规划步行路线
    //walking.search([116.638039,23.41094], [116.63776,23.411964]);
    route(116.638039,23.41094,116.63776,23.411964);
    //walking2.search([116.63776,23.411964], [116.436281, 39.800719]);
    //walking3.search( [116.635056,23.413027], [116.63776,23.411964]);
  	
  		
  
  
</script>
 




</body>
</html>