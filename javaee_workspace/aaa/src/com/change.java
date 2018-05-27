package com;

public class change {
	public double[] change(int index){	
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

}
