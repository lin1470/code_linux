<!doctype html>
<html>
<jsp:useBean id="place" class="com.place" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="place"/>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no, width=device-width">
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
    <!--  
    <script type="text/javascript" src="http://webapi.amap.com/maps?v=1.3&key=1aab8f31adcc55b5b2a97e0fa4cbcece&plugin=AMap.Walking"></script>
    <script type="text/javascript" src="http://cache.amap.com/lbs/static/addToolbar.js"></script>
    -->
</head>
<body>
<div id="container"></div>
<div id="panel"></div>
<script type="text/javascript">
	function route( x1,y1,x2,y2){
		var walking = new AMap.Walking({
	        map: map,
	        panel: "panel"
	    }); 
		walking.search([x1,y1], [x2,y2]);
	}
    var map = new AMap.Map('container', {
        resizeEnable: true,
        zoom:15,
        center: [116.62997999999993, 23.41606]
    });
	 	route(116.638039,23.41094, 116.63776,23.411964);
</script>

<%
	out.println(place.getStart());
  	out.println(place.getEnd());
  	String[] array=place.getArr();
    int i=0;
    int n=0;
    n=array.length;
   	//int a[]={10};
	int[]  a;
	a=new int[20];
	 double tempx1=0;
 	  double tempy1=0;
 	  double tempx2=0;
 	  double tempy2=0;
    while(i<n){
  	  out.println(array[i]);

  	  a[i] = Integer.parseInt(array[i]);
  	  out.println("\n");
  	  out.println(a[i]);
  	 
  	  double x;
  	  double y;
  	  if(i==0){
	  	  switch(a[i]){
	  	  
	  	  case 0:
	  		tempx1=116.638039;
	  		tempy1=23.41094;
	  		  break;
	  	  case 1:
	  		  tempx1=116.63776;
	  		  tempy1=23.411964  ;
			  break;
	  	  case 2:
	  		  tempx1=116.635056;
	  		  tempy1=23.413027;
			  break;
	  	  case 3:
	  		tempx1=116.638103;
			  tempy1=23.412368;
	  		  break;
	  	  default:
	  		 tempx1=0;
			  tempy1=0;
	  		  break;
	  	  
	  	  }
  	  }
  	  else{
  		  tempx2=tempx1;
  		  tempy2=tempy1;
  		 switch(a[i]){
	  	  
	  	  case 0:
	  		tempx1=116.638039;
	  		tempy1=23.41094;
	  		  break;
	  	  case 1:
	  		  tempx1=116.63776;
	  		  tempy1=23.411964  ;
			  break;
	  	  case 2:
	  		  tempx1=116.635056;
	  		  tempy1=23.413027;
			  break;
	  	  case 3:
	  		tempx1=116.638103;
			  tempy1=23.412368;
	  		  break;
	  	  default:
	  		 tempx1=0;
			  tempy1=0;
	  		  break;
	  	  
	  	  }
  	  }
  	  
  	  //
  	  
  	  %>
  	  <script>
  	  	alert(<%=tempx2%>+<%=tempy2%>+<%=tempx1%>,<%=tempy1%>);
  	 	route(<%=tempx2%>,<%=tempy2%>,<%=tempx1%>,<%=tempy1%>);
  	 	//route(116.638039,23.41094, 116.63776,23.411964);
  	  </script>
  	 <%
  	  i++;
  	
   } 
  %>



</body>
</html>