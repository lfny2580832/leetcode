#include <vector>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL) {}
};

//前序遍历和后序遍历结合，后序遍历正好是前序遍历退出结点的顺序
class Solution{
public:
	std::vector<std::vector<int> > pathSum(TreeNode* root, int sum) {
		std::vector<std::vector<int> > result;
		std::vector<int> path;
		int path_value = 0;
		preOrder(root, path_value, sum, path, result);
		return result;
	}
private:
	void preOrder(TreeNode *node, int &path_value,int sum,
				  std::vector<int> &path,
				  std::vector<std::vector<int> > &result){
		if(!node) return;

		path_value += node->val;
		path.push_back(node->val);

		if(!node->left && !node->right && path_value == sum) result.push_back(path);

		preOrder(node->left, path_value, sum,path,result);
		preOrder(node->right, path_value, sum,path,result);
		//遍历完成后将结点从路径弹出，重复利用path变量
		path_value -= node->val;
		path.pop_back();
	}
};

int main(){
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode x(5);
	TreeNode y(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.right = &f;
	c.left = &g;
	d.left = &h;
	f.left = &x;
	f.right = &y;
	Solution solve;
	std::vector<std::vector<int> > result = solve.pathSum(&a, 22);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}







