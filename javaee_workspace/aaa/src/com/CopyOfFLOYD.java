package com;

import java.io.IOException;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;

public class CopyOfFLOYD {
	int[][] length = null;// ��������֮��·������
	int[][][] path = null;// ��������֮���·��
	public CopyOfFLOYD(int[][] G) {
		int MAX = 100;int row = G.length;// ͼG������
		int[][] spot = new int[row][row];// ������������֮�侭���ĵ�
		int[] onePath = new int[row];// ��¼һ��·��
		length = new int[row][row];
		path = new int[row][row][];
		for (int i = 0; i < row; i++)// ����ͼ����֮���·��
		for (int j = 0; j < row; j++) {
		if (G[i][j] == 0)G[i][j] = MAX;// û��·����������֮���·��ΪĬ�����
		if (i == j)G[i][j] = 0;// �����·������Ϊ0
		}
		for (int i = 0; i < row; i++)// ��ʼ��Ϊ��������֮��û��·��
		for (int j = 0; j < row; j++)
		spot[i][j] = -1;
		for (int i = 0; i < row; i++)// ������������֮���û��·��
		onePath[i] = -1;
		for (int v = 0; v < row; ++v)
		for (int w = 0; w < row; ++w)
		length[v][w] = G[v][w];
		for (int u = 0; u < row; ++u)
		for (int v = 0; v < row; ++v)
		for (int w = 0; w < row; ++w)
		if (length[v][w] > length[v][u] + length[u][w]) {
		length[v][w] = length[v][u] + length[u][w];// ������ڸ���·����ȡ����·��
		spot[v][w] = u;// �Ѿ����ĵ����
		}
		for (int i = 0; i < row; i++) {// ������е�·��
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
		void outputPath(int[][] spot, int i, int j, int[] onePath, int[] point) {// ���i// ��j// ��·����ʵ�ʴ��룬point[]��¼һ��·���ĳ���
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
		//���ɾ���
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
		//����Ȩ����
	
		//�γ��µ�����
		System.out.println("How many places you want to gou ");
		int num=input.nextInt();
		int []a= new int[num];
		System.out.println("Please input the places you want to go(1-8)");
		for(int NUM=0;NUM<num;NUM++){
		a[NUM]=input.nextInt();
		}
		//���ɳ�ʼ·��
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
		//���ɳ�ʼ·��
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
		System.out.print("��תǰ���飺");	
		for(int i=0;i<num+2;i++){
		  System.out.println();
		  for(int j=0;j<num+2;j++){
			  System.out.print(choice[i][j]+"\t");
			  
		  }
		}//�γ��µ�����
		System.out.println();
		int middle,temp=0;
		for(int i=2;i<num;i++){
			for(int j=i+2;j<num;j++){
				int data1=choice[i][j]+choice[i+1][j+1];
				int data2=choice[i][i+1]+choice[j][j+1];
				
				if(data1>data2){//�жϷ�ת
				middle=(int) Math.floor((i+j)/2);
				while(i<(middle+1)){
				for(int f=0;f<choice.length;f++){
					temp=choice[i][f];
					choice[i][f]=choice[j][f];
					choice[j][f]=temp;
					}//�з�ת
				for(int f=0;f<choice.length;f++){
					temp=choice[f][i];
					choice[f][i]=choice[f][j];
					choice[f][j]=temp;
					}//�з�ת
					i++;j--;
				}//while
				
				}
				
				
			        }
			
		            }
		System.out.print("��ת�����飺"+"\n");	
		for(int f=0;f<choice.length ;f++){
			for(int h=0;h<choice.length;h++){
				System.out.print(choice[f][h]);
				System.out.print("\t");				
			}
			System.out.println();
		}
		//·��
		try{
			System.out.print("·��Ϊ��"+"\n");	
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
		//���ɾ���
		int sho[][]=new int[data.length][data.length];
		for (int i = 0; i < data.length; i++)
		for (int j = i; j < data.length; j++)
		if (data[i][j] != data[j][i])return;
		Scanner input = new Scanner(System.in);
		int b = 8;  //N*N����
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
	//���ɾ���
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
	//����Ȩ����

	//�γ��µ�����
	System.out.println("How many places you want to gou ");
	int num=input.nextInt();
	int []a= new int[num];
	System.out.println("Please input the places you want to go(1-8)");
	for(int NUM=0;NUM<num;NUM++){
	a[NUM]=input.nextInt();
	}
	//���ɳ�ʼ·��
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
	//���ɳ�ʼ·��
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
	System.out.print("��תǰ���飺");	
	for(int i=0;i<num+2;i++){
	  System.out.println();
	  for(int j=0;j<num+2;j++){
		  System.out.print(choice[i][j]+"\t");
		  
	  }
	}//�γ��µ�����
	System.out.println();
	int middle,temp=0;
	for(int i=2;i<num;i++){
		for(int j=i+2;j<num;j++){
			int data1=choice[i][j]+choice[i+1][j+1];
			int data2=choice[i][i+1]+choice[j][j+1];
			
			if(data1>data2){//�жϷ�ת
			middle=(int) Math.floor((i+j)/2);
			while(i<(middle+1)){
			for(int f=0;f<choice.length;f++){
				temp=choice[i][f];
				choice[i][f]=choice[j][f];
				choice[j][f]=temp;
				}//�з�ת
			for(int f=0;f<choice.length;f++){
				temp=choice[f][i];
				choice[f][i]=choice[f][j];
				choice[f][j]=temp;
				}//�з�ת
				i++;j--;
			}//while
			
			}
			
			
		        }
		
	            }
	System.out.print("��ת�����飺"+"\n");	
	for(int f=0;f<choice.length ;f++){
		for(int h=0;h<choice.length;h++){
			System.out.print(choice[f][h]);
			System.out.print("\t");				
		}
		System.out.println();
	}
	//·��
	try{
		System.out.print("·��Ϊ��"+"\n");	
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




