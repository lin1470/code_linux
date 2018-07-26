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
    //route(116.638039,23.41094,116.63776,23.411964);
    //route(116.635056,23.413027,116.63776,23.411964);
    //walking2.search([116.63776,23.411964], [116.436281, 39.800719]);
    //walking3.search( [116.635056,23.413027], [116.63776,23.411964]);
  	
  		
  
  
</script>
<%



String[] picked =request.getParameterValues("arr");
double tempx1;
double tempy1;
double tempx2;
double tempy2;
if ((picked!=null)&&(picked.length!=0))
{
	int i=0;
	
	int num=picked.length;
	while(i<num){
		System.out.println(i);
		double x,y;
		out.println(picked[i]);
		int a = Integer.parseInt(picked[i]);
		switch (a){
			case 0:
				x=116.638039;y=23.41094;
				if(i==0){
					tempx1=x;
				 	tempy1=y;
				}
				else{
					
					
					tempx2=x;
					tempy2=y;
					%>
					<script type="text/javascript">
					route(tempx1,tempy1,tempx2,tempy2);window.print(tempx1,tempy1,tempx2,tempy2);
					</script>;
					<% 
					tempx1=tempx2;
					tempy1=tempy2;
				}
				break;
			case 1:
				x=116.63776;y=23.411964;
				if(i==0){
					tempx1=x;
				 	tempy1=y;
				}
				else{
					
					
					tempx2=x;
					tempy2=y;
					%>
					<script type="text/javascript">route(tempx1,tempy1,tempx2,tempy2);window.print(tempx1,tempy1,tempx2,tempy2);</script>;
					<% 
					tempx1=tempx2;
					tempy1=tempy2;
				}
				break;
			case 2:
				x=116.635056;y=23.413027;
				if(i==0){
					tempx1=x;
				 	tempy1=y;
				}
				else{
					
					
					tempx2=x;
					tempy2=y;
					%>
					<script type="text/javascript">route(tempx1,tempy1,tempx2,tempy2);window.print(tempx1,tempy1,tempx2,tempy2);</script>;
					<% 
					tempx1=tempx2;
					tempy1=tempy2;
				}
				break;
			case 3:
				x=116.638103;y=23.412368;
				if(i==0){
					tempx1=x;
				 	tempy1=y;
				}
				else{

					tempx2=x;
					tempy2=y;
					%>
					<script type="text/javascript">route(tempx1,tempy1,tempx2,tempy2);window.print(tempx1,tempy1,tempx2,tempy2);</script>;
					<% 
					tempx1=tempx2;
					tempy1=tempy2;
				}
				break;
			
			default:
				System.out.println("输入有误");
		}
		
		i++;
		
	}
	//out.println(picked[1]);
}

out.print(picked.length);
out.print("ceshi");
out.print(place.getStart());
out.print(place.getEnd());

%>

 


</body>
</html>