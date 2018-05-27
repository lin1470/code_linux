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
<div id="container" style="width:80%;border-left: 1px solid #000;"></div>

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
  	int array_length=array.length;
  	System.out.print(start);
  	//经过算法处理
  	
  		int[] a = new int[30];
  		a[0]=start;//起点
  		System.out.println("a[start]="+a[start]);
		for(int i=0;i<array_length;i++){//中间点
			System.out.println("array["+(i)+"]="+array[i]);
			a[i+1]=Integer.parseInt(array[i]);
			System.out.println("a["+(i+1)+"]="+a[i+1]);
		}
  		a[array_length+1]=end;//终点
  		System.out.println("a[end]="+a[array_length+1]);
		System.out.println("array_length="+array_length);
		int b_length=array_length+1;
		System.out.println("b_length="+b_length);
		int[] b=new int[array_length+1];
		
		
		 //System.out.println("b[0]"+b[0]);
		try {
			b = Way.ShowWay(a);
			int j=0;
			int num=0;
			
			num=b.length;
			for(j=0;j<num;j++){
				if(b[j]==0) break;
				System.out.println("n["+j+"]"+b[j]);
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
		
  	
  	//转换坐标与画图
  	//
	
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
	
	
	
	//----------
	for(i=0;i<b.length;i++){
		if(i==0){//第一个点
			temp2=change(b[0]);
			tempx2=temp2[0];
			tempy2=temp2[1];
			System.out.println("first place:"+tempx2+","+tempy2);
		}
		else{
			temp1=change(b[i]);
			tempx1=temp1[0];
			tempy1=temp1[1];
			System.out.println(tempx2+","+tempy2+"->"+tempx1+","+tempy1);
			%>
	    	 <script>
	    	 	alert(<%=tempx2%>+<%=tempy2%>+<%=tempx1%>,<%=tempy1%>);
		  	  	
		  	 	route(<%=tempx2%>,<%=tempy2%>,<%=tempx1%>,<%=tempy1%>);
		  	 	//route(116.638039,23.41094, 116.63776,23.411964);
		  	  </script>
	    	<% 
	    	tempx2=tempx1;
			tempy2=tempy1;
			}
		//保存上一个点
		
		
	}

	%>


</body>
</html>