<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<jsp:useBean id="place" class="com.place" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="place"/>
<title>Insert title here</title>

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
    walking.search([116.638039,23.41094], [116.63776,23.411964]);
    route(116.638039,23.41094,116.63776,23.411964);
    //route(116.635056,23.413027,116.63776,23.411964);
    //walking2.search([116.63776,23.411964], [116.436281, 39.800719]);
    //walking3.search( [116.635056,23.413027], [116.63776,23.411964]);
  	
  		
  
  
</script>

<%
  String[] array=place.getArr();
  int i=0;
  int n=array.length;
 

  while(i<n){
	  out.println(array[i]);
	  int a = Integer.parseInt(array[i]);
	  double tempx1;
	  double tempy1;
	  double tempx2;
	  double tempy2;
	  double x;
	  double y;
	  switch (a){
		case 0:
			x=116.638039;
			y=23.41094;
			if(i==0){
				tempx1=x;
			 	tempy1=y;
			}
			else{
				
				
				tempx2=x;
				tempy2=y;
				%>
<script type="text/javascript">
			//route(tempx1,tempy1,tempx2,tempy2);window.print(tempx1,tempy1,tempx2,tempy2);
			
			window.print("hello world");
</script>;

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
    walking.search([116.638039,23.41094], [116.63776,23.411964]);
    route(116.638039,23.41094,116.63776,23.411964);
    route(116.635056,23.413027,116.63776,23.411964);
    walking2.search([116.63776,23.411964], [116.436281, 39.800719]);
    walking3.search( [116.635056,23.413027], [116.63776,23.411964]);
    window.print("hello world");
  		
  
  
</script>

				<% 
				tempx1=0;
				tempy1=0;
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
				<script type="text/javascript">route(<%=tempx1%>,<%=tempy1%>,<%=tempx2%>,<%=tempy2%>);window.print(tempx1,tempy1,tempx2,tempy2);</script>;
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
  

%>
</body>
</html>