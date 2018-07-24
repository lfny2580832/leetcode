#include<stdio.h>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   		std::vector<TreeNode *> path;
   		std::vector<TreeNode *> p_path;
   		std::vector<TreeNode *> q_path;
   		int finish = 0;
   		preOrder(root, p, path, p_path, finish);
   		path.clear();
   		finish = 0;
   		preOrder(root, q, path, q_path, finish);
   		int path_len = 0;
   		if(p_path.size() < q_path.size()) path_len = p_path.size();
   		else path_len = q_path.size();
   		TreeNode *result = 0;
   		for(int i = 0; i < path_len; i++){
   			if(p_path[i]->val == q_path[i]->val) result = p_path[i];
   		}
   		return result;
    }
private:
	//存储到search节点的路径至result
	void preOrder(TreeNode *node, TreeNode *search,
				 std::vector<TreeNode *> &path,
				 std::vector<TreeNode *> &result,
				 int &finish){
		if(!node || finish) return;
		path.push_back(node);
		if(node == search){
			finish = 1;
			result = path;
		}
		preOrder(node->left, search,path,result,finish);
		preOrder(node->right, search,path,result,finish);
		path.pop_back();
	}
};