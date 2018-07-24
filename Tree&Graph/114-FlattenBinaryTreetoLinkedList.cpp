#include<stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//就地将二叉树转换为单链表
class Solution{
	public:
		void flatten(TreeNode *root){
			TreeNode *last = NULL;
			preOrder(root, last);
		}

	private:
		//递归，last是传出来用的
		void preOrder(TreeNode *node, TreeNode *&last){
			if(!node) return;
			//叶结点
			if(!node->left && !node->right){
				last = node;
				return;
			}
			//前序
			TreeNode *left = node->left;
			TreeNode *right = node->right;
			TreeNode *left_last = NULL;
			TreeNode *right_last = NULL;
			//有左子树
			if(left){
				//拿到左子树链表的最后一个结点
				preOrder(left, left_last);
				node->left = NULL;
				node->right = left;
				last = left_last;
			}
			//有右子树
			if(right){
				preOrder(right, right_last);
				if(left_last){
					left_last->right = right;
				}
				last = right_last;
			}
		}
};

int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	Solution solve;
	solve.flatten(&a);
	TreeNode *head = &a;
	while(head){
		if(head->left) printf("Error\n");
		printf("[%d]\n", head->val);
		head = head->right;
	}
	printf("\n");
	return 0;
}