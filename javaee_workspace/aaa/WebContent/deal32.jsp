<!doctype html>
<html>
<jsp:useBean id="place" class="com.place" scope="page"></jsp:useBean>
<jsp:setProperty property="*" name="place"/>
<%@   page   import= "com.test "%>
<%@   page   import= "com.FLOYD "%>
<%@   page   import= "com.Way "%>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no, width=device-width">
    <title>æèµ·ç»ç¹ç»çº¬åº¦è§åè·¯çº¿</title>
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
			  
		  case 4://大礼堂
				temp[0]=116.633297;
				temp[1]=23.412732;
				break;
			  case 5:////体育馆
				  temp[0]=116.631258;
				  temp[1]=23.41539;
				  break;
			  case 6://789
				  temp[0]=116.6304;
				  temp[1]=23.413717;
				  break;
			  case 7://三饭
				  temp[0]=116.63334;
				  temp[1]=23.414957;
				  break;
			  case 8://机电楼
				  temp[0]=116.634016;
				  temp[1]=23.415174;
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
  	//對數據進行處理
  	 int n=0;
  	 n=array.length;
	 System.out.println("n="+n);
	   	//int a[]={10};
	int[]  b;
    b=new int[n];
    int i=0;
    while(i<n){
    	b[i] = Integer.parseInt(array[i]);
    	i++;
    }
    //進行算法
    int[] a=new int[14];
		
		
		 //System.out.println("b[0]"+b[0]);
		try {
			a = Way.ShowWay(b);
			int j=0;
			int num=0;
			
			num=b.length;
			for(j=0;j<num;j++){
				if(a[j]==0) break;
				System.out.println("a["+j+"]"+a[j]);
			}
			/*
			while(b[i]!=0){
				System.out.print("plpl");
				System.out.print(b[i]+"-"+"i="+i);
				i++;
			}
			
			
			 */
			System.out.println("num="+num);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
  	
	//ciugai
  	/*
  	int[] a = new int[5];
	a[0]=1;
	a[1]=5;
	a[2]=2;
	a[3]=7;
	a[4]=3;
	Way.ShowWay(a);
	System.out.println("hello");
	*/
	
  	
  	//
   
   
    
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
    	
    	temp2=change(end);
    	tempx2=temp2[0];
    	tempy2=temp2[1];
    	System.out.println("");
    	System.out.println("place1："+tempx1+":"+tempy1);
    	System.out.println("place2："+tempx2+":"+tempy2);
    	System.out.println("Two");
    	%>
    	 <script>
	  	 	route(<%=tempx1%>,<%=tempy1%>,<%=tempx2%>,<%=tempy2%>);
	  	  </script>
    	<% 
    }
    else{
	    
		temp1=change(start);
    	tempx1=temp1[0];
    	tempy1=temp1[1];
		
    	System.out.println("Totol"+n);
    	i=0;
	    while(i<n){
	  	  out.println(array[i]);
	
	  	  //a[i] = Integer.parseInt(array[i]);
	  	 
	  	  double x;
	  	  double y;
	  	  
	  	  
	  		  tempx2=tempx1;
	  		  tempy2=tempy1;
	  		  
	  		temp1=change(a[i]);
	    	tempx1=temp1[0];
	    	tempy1=temp1[1];
	    	System.out.println("place3："+tempx1+":"+tempy1);
	    	System.out.println("");
	  	  
	  	  
	  	  %>
	  	  <script>
	  	 	route(<%=tempx2%>,<%=tempy2%>,<%=tempx1%>,<%=tempy1%>);
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
	    }
	    
    }
  %>
 
  	  <script>
  	 	route(<%=tempx2%>,<%=tempy2%>,<%=tempx1%>,<%=tempy1%>);
  	  </script>
  	 
  


</body>
</html>