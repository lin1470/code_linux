package com;

public class FLOYD {
	int[][] length = null;// ��������֮��·������
	int[][][] path = null;// ��������֮���·��

	public FLOYD(int[][] G) {
		int MAX = 100;
		int row = G.length;// ͼG������
		int[][] spot = new int[row][row];// ������������֮�侭���ĵ�
		int[] onePath = new int[row];// ��¼һ��·��
		length = new int[row][row];
		path = new int[row][row][];
		for (int i = 0; i < row; i++)// ����ͼ����֮���·��
			for (int j = 0; j < row; j++) {
				if (G[i][j] == 0)
					G[i][j] = MAX;// û��·����������֮���·��ΪĬ�����
				if (i == j)
					G[i][j] = 0;// �����·������Ϊ0
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

	void outputPath(int[][] spot, int i, int j, int[] onePath, int[] point) {// ���i//
																				// ��j//
																				// ��·����ʵ�ʴ��룬point[]��¼һ��·���ĳ���
		if (i == j)
			return;
		if (spot[i][j] == -1)
			onePath[point[0]++] = j;
		// System.out.print(" "+j+" ");
		else {
			outputPath(spot, i, spot[i][j], onePath, point);
			outputPath(spot, spot[i][j], j, onePath, point);
		}
	}
}
