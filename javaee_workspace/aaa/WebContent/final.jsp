<!doctype html>
<html>
<%@   page   import= "com.FLOYD "%>
<%@ page laugage="java" import="java.io.IOException" %>
<%@ page laugage="java" import="java.util.Scanner" %>
<%@ page laugage="java" import="java.io.BufferedReader" %>
<%@ page laugage="java" import="java.io.File" %>
<%@ page laugage="java" import="java.io.FileReader" %>
<%@ page laugage="java" import="java.io.FileWriter" %>

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
//
<%!
	void outputPath(int[][] spot, int i, int j, int[] onePath, int[] point) {// 输出i// 到j// 的路径的实际代码，point[]记录一条路径的长度
		if (i == j)return;
		if (spot[i][j] == -1)
		onePath[point[0]++] = j;
		// System.out.print(" "+j+" ");
		else {
		outputPath(spot, i, spot[i][j], onePath, point);
		outputPath(spot, spot[i][j], j, onePath, point);
		}
	}

%>>


<%!
//第一個函數
	int[][] length = null;// 任意两点之间路径长度
	int[][][] path = null;// 任意两点之间的路径
	void FLOYD(int[][] G) {
		int MAX = 100;int row = G.length;// 图G的行数
		int[][] spot = new int[row][row];// 定义任意两点之间经过的点
		int[] onePath = new int[row];// 记录一条路径
		length = new int[row][row];
		path = new int[row][row][];
		for (int i = 0; i < row; i++)// 处理图两点之间的路径
		for (int j = 0; j < row; j++) {
		if (G[i][j] == 0)G[i][j] = MAX;// 没有路径的两个点之间的路径为默认最大
		if (i == j)G[i][j] = 0;// 本身的路径长度为0
		}
		for (int i = 0; i < row; i++)// 初始化为任意两点之间没有路径
		for (int j = 0; j < row; j++)
		spot[i][j] = -1;
		for (int i = 0; i < row; i++)// 假设任意两点之间的没有路径
		onePath[i] = -1;
		for (int v = 0; v < row; ++v)
		for (int w = 0; w < row; ++w)
		length[v][w] = G[v][w];
		for (int u = 0; u < row; ++u)
		for (int v = 0; v < row; ++v)
		for (int w = 0; w < row; ++w)
		if (length[v][w] > length[v][u] + length[u][w]) {
		length[v][w] = length[v][u] + length[u][w];// 如果存在更短路径则取更短路径
		spot[v][w] = u;// 把经过的点加入
		}
		for (int i = 0; i < row; i++) {// 求出所有的路径
		int[] point = new int[1];
		for (int j = 0; j < row; j++) {
		point[0] = 0;
		onePath[point[0]++] = i;
		outputPath(spot, i, j, onePath, point);
		path[i][j] = new int[point[0]];
		for (int s = 0; s < point[0]; s++)
		path[i][j][s] = onePath[s];
		}
		}
	}

%>

<%
//main
	Scanner input = new Scanner(System.in);
		int b = 8;  //N*N数组
		int[][] data = new int[b][b];
		File file = new File("d:\\array.txt");  
	    
		  BufferedReader in = new BufferedReader(new FileReader(file));  
		  String line;  
		  int row=0;
		  while((line = in.readLine()) != null){
		   String[] temp = line.split("\t");  
		   for(int j=0;j<temp.length;j++){
		    data[row][j] = Integer.parseInt(temp[j]);
		   }
		   row++;
		  }
		  in.close();
	//生成矩阵
	int sho[][]=new int[data.length][data.length];
	for (int i = 0; i < data.length; i++)
	for (int j = i; j < data.length; j++)
	if (data[i][j] != data[j][i])return;
	FLOYD test=new FLOYD(data);
	for (int i = 0; i < data.length; i++)
	for (int j = 0; j < data.length; j++) {
	    sho[i][j]=test.length[i][j];
	}
	for (int i = 0; i < data.length; i++){
	for (int j = 0; j < data.length; j++) {
	    System.out.print(sho[i][j]+"\t");
	}
	System.out.println();
	}
	//生成权矩阵

	//形成新的数组
	System.out.println("How many places you want to gou ");
	//輸入
	int num=input.nextInt();
	int []a= new int[num];
	System.out.println("Please input the places you want to go(1-8)");
	for(int NUM=0;NUM<num;NUM++){
	a[NUM]=input.nextInt();
	}
	//生成初始路径
	int change;
	for(int j=1;j<num-2;j++){
	for(int i=1;i<num-j-1;i++){
		if (a[i]>a[i+1]){
			change=a[i];
			a[i]=a[i+1];
			a[i+1]=change;
		}
	}
	}
	//生成初始路径
	int choice[][]= new int[num+2][num+2];

	for(int n=1,m=0;m<num;m++,n++){
	 int l=a[m];
	choice[0][n]=l; 
	choice[num+1][n]=l; 
	}
	for(int q=0;q<num;q++){
	   int hang=a[q]-1;
	for(int n=1,m=0;m<num;m++,n++){
	    int l=a[m]-1;
		choice[q+1][n]=sho[hang][l]; 
	  }
	}
	System.out.print("翻转前数组：");	
	for(int i=0;i<num+2;i++){
	  System.out.println();
	  for(int j=0;j<num+2;j++){
		  System.out.print(choice[i][j]+"\t");
		  
	  }
	}//形成新的数组
	System.out.println();
	int middle,temp=0;
	for(int i=2;i<num;i++){
		for(int j=i+2;j<num;j++){
			int data1=choice[i][j]+choice[i+1][j+1];
			int data2=choice[i][i+1]+choice[j][j+1];
			
			if(data1>data2){//判断翻转
			middle=(int) Math.floor((i+j)/2);
			while(i<(middle+1)){
			for(int f=0;f<choice.length;f++){
				temp=choice[i][f];
				choice[i][f]=choice[j][f];
				choice[j][f]=temp;
				}//行翻转
			for(int f=0;f<choice.length;f++){
				temp=choice[f][i];
				choice[f][i]=choice[f][j];
				choice[f][j]=temp;
				}//列翻转
				i++;j--;
			}//while
			
			}
			
			
		        }
		
	            }
	System.out.print("翻转后数组："+"\n");	
	for(int f=0;f<choice.length ;f++){
		for(int h=0;h<choice.length;h++){
			System.out.print(choice[f][h]);
			System.out.print("\t");				
		}
		System.out.println();
	}
	//路径
	try{
		System.out.print("路径为："+"\n");	
		for(int i=1;i<num+1;i++){
			System.out.print(choice[0][i]+ "\t");
		}
		System.out.println();
	for (int l=1;l<num+1;l++){
		int LEN1=choice[0][l]-1,LEN2=choice[0][l+1]-1;
		for (int k = 0; k < test.path[LEN1][LEN2].length; k++){
			System.out.print(test.path[LEN1][LEN2][k]+1 + "\t");
			
		}
		System.out.println();
	}}
	catch(Exception e){

	}

	



%>

//

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