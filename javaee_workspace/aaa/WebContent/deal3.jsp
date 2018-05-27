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
    <script type="text/javascript" src="http://webapi.amap.com/maps?v=1.3&key=1aab8f31adcc55b5b2a97e0fa4cbcece&plugin=AMap.Walking"></script>
    <script type="text/javascript" src="http://cache.amap.com/lbs/static/addToolbar.js"></script>
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
	 	//route(116.638039,23.41094, 116.63776,23.411964);
</script>
<%!

	
	double[] change(int index){
	
	
		double[] temp;
		temp =new double[2];
		//temp[0]=>tempx1 temp[1]=>tempy1,temp[2]=>tempx2,temp[3]=>tempy2
		switch(index){
		case 0:
			temp[0]=116.638039;
			temp[1]=23.41094;
			  break;
		  case 1:
			  temp[0]=116.63776;
			  temp[1]=23.411964  ;
			  break;
		  case 2:
			  temp[0]=116.635056;
			  temp[1]=23.413027;
			  break;
		  case 3:
			  temp[0]=116.638103;
			  temp[1]=23.412368;
		 	 break;
		  case 4:
			  temp[0]=116.632801;
			  temp[1]=23.415125;
		 	 break;
		  case 5:
			  temp[0]=116.636183;
			  temp[1]=23.411777;
		 	 break;
		  case 6:
			  temp[0]=116.63329;
			  temp[1]=23.412743;
		 	 break;
		  case 7:
			  temp[0]=116.633853;
			  temp[1]=23.409848;
		 	 break;
		  case 8:
			  temp[0]=116.633511;
			  temp[1]=23.413963;
		 	 break;
		  case 9:
			  temp[0]=116.631258;
			  temp[1]=23.41539;
		 	 break;
		  default:
			 temp[0]=0;
			  temp[1]=0;
			  break;
		  
		  }
		return temp;
	}
%>
<%
	out.println(place.getStart());
	int start=Integer.parseInt(place.getStart());
	int end=Integer.parseInt(place.getEnd());
  	out.println(place.getEnd());
  	String[] array=place.getArr();
  	System.out.print(start);
  	
  	
    int i=0;
    int n=0;
    
    double tempx1=0;
	double tempy1=0;
	double tempx2=0;
	double tempy2=0;
	double[] temp1;
	temp1 =new double[2];  
	
	double[] temp2;
	temp2 =new double[2]; 
	
    if(array==null){
    	temp1=change(start);
    	tempx1=temp1[0];
    	tempy1=temp1[1];
    	/*
    	switch(start){
		  
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
		 
		  default:
			 tempx1=0;
			  tempy1=0;
			  break;
		  
		  }
    	*/
    	//
    	temp2=change(end);
    	tempx2=temp2[0];
    	tempy2=temp2[1];
    	/*
    	switch(end){
		  
		  case 0:
			tempx1=116.638039;
			tempy1=23.41094;
			  break;
		  case 1:
			  tempx2=116.63776;
			  tempy2=23.411964  ;
			  break;
		  case 2:
			  tempx2=116.635056;
			  tempy2=23.413027;
			  break;
		  case 3:
			tempx2=116.638103;
			  tempy2=23.412368;
		 
		  default:
			 tempx2=0;
			  tempy2=0;
			  break;
		  
		  }
    	*/
    	%>
    	 <script>
    	 	alert(<%=tempx2%>+<%=tempy2%>+<%=tempx1%>,<%=tempy1%>);
	  	  	
	  	 	route(<%=tempx1%>,<%=tempy1%>,<%=tempx2%>,<%=tempy2%>);
	  	 	//route(116.638039,23.41094, 116.63776,23.411964);
	  	  </script>
    	<% 
    }
    else{
	    n=array.length;
	    //System.out.println("n="+n);
	   	//int a[]={10};
		int[]  a;
		a=new int[20];
		
		
		temp1=change(start);
		tempx1=temp1[0];
    	tempy1=temp1[1];
		
		/*
		switch(start){
		  
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
		 
		  default:
			 tempx1=0;
			  tempy1=0;
			  break;
		  
		  }
		*/
		
	    while(i<n){
	  	  out.println(array[i]);
	
	  	  a[i] = Integer.parseInt(array[i]);
	  	 
	  	 System.out.print("->"+a[i]+"->");
	  	  
	  	  out.println("\n");
	  	  out.println(a[i]);
	  	 
	  	  double x;
	  	  double y;
		  
	  	  
	  	  /*
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
		  	 
		  	  default:
		  		 tempx1=0;
				  tempy1=0;
		  		  break;
		  	  
		  	  }
	  	  }*/
	  	  
	  		  tempx2=tempx1;
	  		  tempy2=tempy1;
	  		  temp1=change(a[i]);
			  tempx1=temp1[0];
		      tempy1=temp1[1];
	  		 /*switch(a[i]){
		  	  
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
	  	  */
	  	  
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
	    tempx2=tempx1;
		tempy2=tempy1;
	    if((i==n) &&(n!=0)){
	    	 temp1=change(end);
			  tempx1=temp1[0];
		      tempy1=temp1[1];
		   /* switch(end){
		  	  
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
		  	 
		  	  default:
		  		 tempx1=0;
		  		  tempy1=0;
		  		  break;
		  	  
		  	  }*/
		  	  
	    }
	    
    }
  %>
 
  	  <script>
  	  	alert(<%=tempx2%>+<%=tempy2%>+<%=tempx1%>,<%=tempy1%>);
  	 	route(<%=tempx2%>,<%=tempy2%>,<%=tempx1%>,<%=tempy1%>);
  	 	//route(116.638039,23.41094, 116.63776,23.411964);
  	  </script>
  	 
  <%
  System.out.println(end);
  %>


</body>
</html>