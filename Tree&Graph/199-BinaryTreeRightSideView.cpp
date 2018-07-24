#include <stdio.h>
#include <queue>
#include <pair>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	std::vector<int> rightSideView(TreeNode *root){
		std::queue<std::pair<TreeNode *, int > > Q;
		std::vector<int> result;

		if(root){
			Q.push(std:make_pair(root, 0));
		}

		while(!Q.empty()){
			TreeNode *node = Q.front().first;
			int depth = Q.front().second;
			Q.pop();
			//----------------
			//这一步整层的结点会一一进入，然后替代掉result的最后一个值
			//如1，5，3，else后变成1，5，4，再else后变成1，5，6，即为最终结果
			if(result.size() == depth){
				result.push_back(node->val);			
			}else{
				result[depth] = node->val;
			}
			//----------------
			if(node->left) Q.push(std::make_pair(node->left, depth+1));
			if(node->left) Q.push(std::make_pair(node->right, depth+1));
		}
		return result;
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
	std::vector<int> result = solve.rightSideView(&a);
	for(int i = 0; i < result.size(); i++){
			printf("[%d]\n", result[i]);
		}
	return 0;
}