package com;

import java.io.IOException;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;

public class CopyOfFLOYD {
	int[][] length = null;// 任意两点之间路径长度
	int[][][] path = null;// 任意两点之间的路径
	public CopyOfFLOYD(int[][] G) {
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
	
	
	public void f(int[][] data) throws NumberFormatException, IOException{
		//
		//生成矩阵
		int sho[][]=new int[data.length][data.length];
		for (int i = 0; i < data.length; i++)
		for (int j = i; j < data.length; j++)
		if (data[i][j] != data[j][i])return;
		//
		CopyOfFLOYD test=new CopyOfFLOYD(data);
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
	}
	public static void main(String[] args) throws IOException{
		//生成矩阵
		int sho[][]=new int[data.length][data.length];
		for (int i = 0; i < data.length; i++)
		for (int j = i; j < data.length; j++)
		if (data[i][j] != data[j][i])return;
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
	CopyOfFLOYD test=new CopyOfFLOYD(data);
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

	}

}




