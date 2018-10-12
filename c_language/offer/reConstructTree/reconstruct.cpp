#include<stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() <= 0 || vin.size() <= 0)
			return NULL;
		TreeNode *root = new TreeNode(0);
		root->val = pre[0];
		vector<int> l_pre;
		vector<int> l_vin;
		TreeNode *left_root = NULL;
		TreeNode *right_root = NULL;
		vector<int>::iterator it = find(vin.begin(), vin.end(), pre[0]);
		if (it != vin.begin())
		{
			//handle left tree
			vector<int>::iterator lit;
			for (lit = vin.begin(); lit != it; lit++)
				l_vin.push_back(*lit);
			int llen = l_vin.size();
			for (int i = 0; i<llen; i++)
				l_pre.push_back(pre.at(i + 1));
			left_root = reConstructBinaryTree(l_pre, l_vin);
		}
		l_vin.clear();
		l_pre.clear();
		if (it != vin.end()-1)
		{
			// handle right tree
			vector<int>::iterator lit;
			for (lit = it + 1; lit != vin.end(); lit++)
				l_vin.push_back(*lit);
			int llen = l_vin.size();
			for (int i = 0; i<llen; i++)
				l_pre.push_back(pre.at(pre.size() - llen + i));
			right_root = reConstructBinaryTree(l_pre, l_vin);
		}
		root->left = left_root;
		root->right = right_root;
		return root;
}

void print_tree(TreeNode *root)
{
	printf("%d ", root->val);
	if (root->left != NULL)
		print_tree(root->left);
	if (root->right != NULL)
		print_tree(root->right);
}
int main()
{
	int pre_arr[] = { 1,2,4,7,3,5,6,8 };
	int vin_arr[] = { 4,7,2,1,5,3,8,6 };
	vector<int> pre(pre_arr,pre_arr+8);
	vector<int> vin(vin_arr,vin_arr+8);
	TreeNode *root = reConstructBinaryTree(pre, vin);
	print_tree(root);
	printf("helloe");
	system("pause");
}