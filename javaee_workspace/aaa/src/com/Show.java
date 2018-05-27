package com;

public class Show {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = new int[5];
		a[0]=1;
		a[1]=4;
		a[2]=2;
		a[3]=7;
		a[4]=5;
		int[] b=new int[14];
		
		
		 //System.out.println("b[0]"+b[0]);
		try {
			b = Way.ShowWay(a);
			int i=0;
			int num=0;
			
			num=b.length;
			for(i=0;i<num;i++){
				if(b[i]==0) break;
				System.out.println("b["+i+"]"+b[i]);
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
		
	}
}
