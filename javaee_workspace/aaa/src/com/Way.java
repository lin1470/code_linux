package com;

import java.io.IOException;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
public class Way {
	public static int[] ShowWay(int a[]) throws Exception{
		change app=new change();
		
		int o = 0;
		Scanner input = new Scanner(System.in);
		int g[] = new int[32];
		int data[][] = { { 0, 27, 44, 17, 11, 27, 42, 0, 0, 0 }, // x1
				{ 27, 0, 31, 27, 49, 0, 0, 0, 0, 0 }, // 1
				{ 44, 31, 0, 19, 0, 27, 32, 0, 0, 0 }, // 2
				{ 17, 27, 19, 0, 14, 0, 0, 0, 0, 0 }, // 3
				{ 11, 49, 0, 14, 0, 13, 20, 0, 0, 28 }, // 4
				{ 27, 0, 27, 0, 13, 0, 9, 21, 0, 26 }, // 5
				{ 42, 0, 32, 0, 20, 9, 0, 13, 0, 32 }, // 6
				{ 0, 0, 0, 0, 0, 21, 13, 0, 19, 0 }, // 7
				{ 0, 0, 0, 0, 0, 0, 0, 19, 0, 11 }, // 8
				{ 0, 0, 0, 0, 28, 26, 32, 0, 11, 0 },// 9
		};
		int sho[][] = new int[data.length][data.length];
		for (int i = 0; i < data.length; i++)
			for (int j = i; j < data.length; j++)
				if (data[i][j] != data[j][i]){}
					
		FLOYD test = new FLOYD(data);
		for (int i = 0; i < data.length; i++)
			for (int j = 0; j < data.length; j++) {
				sho[i][j] = test.length[i][j];
			}
		for (int i = 0; i < data.length; i++) {
			for (int j = 0; j < data.length; j++) {
				System.out.print(sho[i][j] + "\t");
			}
			System.out.println();
		}
		// 生成权矩阵
		// 形成新的数组
		/*
		System.out.println("How many places you want to go:");
		int num = input.nextInt();
		int[] a = new int[num];
		System.out.println("Please input the places you want to go(1-10):");
		for (int NUM = 0; NUM < num; NUM++) {
			a[NUM] = input.nextInt();
		}
		*/
		int num=a.length;
		System.out.println("num="+num);
		// 生成初始路径
		int change;
		for (int j = 1; j < num - 2; j++) {
			for (int i = 1; i < num - j - 1; i++) {
				if (a[i] > a[i + 1]) {
					change = a[i];
					a[i] = a[i + 1];
					a[i + 1] = change;
				}
			}
		}
		// 生成初始路径
		int choice[][] = new int[num + 2][num + 2];
		for (int n = 1, m = 0; m < num; m++, n++) {
			int l = a[m];
			choice[0][n] = l;
			choice[num + 1][n] = l;
		}
		for (int q = 0; q < num; q++) {
			int hang = a[q] - 1;
			for (int n = 1, m = 0; m < num; m++, n++) {
				int l = a[m] - 1;
				choice[q + 1][n] = sho[hang][l];
			}
		}
		System.out.print("翻转前数组：");
		for (int i = 0; i < num + 2; i++) {
			System.out.println();
			for (int j = 0; j < num + 2; j++) {
				System.out.print(choice[i][j] + "\t");
			}
		} // 形成新的数组
		System.out.println();
		int middle, temp = 0;
		for (int i = 2; i < num; i++) {
			for (int j = i + 2; j < num; j++) {
				int data1 = choice[i][j] + choice[i + 1][j + 1];
				int data2 = choice[i][i + 1] + choice[j][j + 1];
				if (data1 > data2) {// 判断翻转
					middle = (int) Math.floor((i + j) / 2);
					while (i < (middle + 1)) {
						for (int f = 0; f < choice.length; f++) {
							temp = choice[i][f];
							choice[i][f] = choice[j][f];
							choice[j][f] = temp;
						} // 行翻转
						for (int f = 0; f < choice.length; f++) {
							temp = choice[f][i];
							choice[f][i] = choice[f][j];
							choice[f][j] = temp;
						} // 列翻转
						i++;
						j--;
					} // while
				}
			}
		}
		System.out.print("翻转后数组：" + "\n");
		for (int f = 0; f < choice.length; f++) {
			for (int h = 0; h < choice.length; h++) {
				System.out.print(choice[f][h]);
				System.out.print("\t");
			}
			System.out.println();
		}
		// 路径
		try {
			System.out.print("路径为：" + "\n");
			for (int i = 1; i < num + 1; i++) {
				System.out.print("检测点一:"+app.change(choice[0][i])[0] + "\t"+app.change(choice[0][i])[1]);
				//System.out.print("检测点一:"+choice[0][i] + "\t");
			}
			System.out.println("");
			g[0] = test.path[choice[0][1] - 1][choice[0][2] - 1][0] + 1;
			System.out.print("检测点二:"+app.change(g[o])[0] + "\t"+ app.change(g[o])[1] );
			for (int l = 1; l < num + 1; l++) {
				int LEN1 = choice[0][l] - 1, LEN2 = choice[0][l + 1] - 1;
				for (int k = 1; k < test.path[LEN1][LEN2].length; k++) {
					o += 1;
					g[o] = test.path[LEN1][LEN2][k] + 1;
					//System.out.print("检测点二:"+g[o] + "\t" );
					System.out.print(g.length);
					System.out.print("检测点二:"+app.change(g[o])[0] + "\t"+ app.change(g[o])[1] );

					
				}
			}
			System.out.println("g.length="+g.length);
			System.out.println("choice[0].length="+choice[0].length);
			System.out.print("检测三");
			System.out.println();
			return g;
		} catch (Exception e) {
			return g;
		}
		
	}

}
