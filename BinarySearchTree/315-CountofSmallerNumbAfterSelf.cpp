#include<stdio.h>
#include<vector>

struct BSTNode{
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x):
		val(x),left(NULL),right(NULL),count(0) {}	
};
/*逆序数数组
input:[5,2,6,1];
output:[2,1,1,0];
*/
class Solution {
public:
	//思路：将原数组逆置，构建二叉查找树，插入时判断有几个比他小。最后再倒过来即可
    std::vector<int> countSmaller(std::vector<int>& nums) {
    	std::vector<BSTNode *> node_vec;
    	std::vector<int> count; //倒转数组构建BST时，比当前值小的有多少
    	for(int i = nums.size()-1; i >=0; i --){
    		node_vec.push_back(new BSTNode(nums[i]));
    	}
    	count.push_back(0);
    	//构建BST，同时计算比自己小的个数
    	for(int i = 1; i < node_vec.size(); i ++){
    		int count_small = 0;
    		BST_insert(node_vec[0],node_vec[i],count_small);
    		count.push_back(count_small);
    	}
    	std::vector<int> result;
    	for(int i = node_vec.size()-1; i >= 0; i --){
    		delete node_vec[i];
    		result.push_back(count[i]);
    	}
    	return result;
    }

private:
	//插入构建二叉排序树
	void BST_insert(BSTNode *node, BSTNode *insert_node,int &count_small){
		if(insert_node->val <= node->val){
			node->count++;
			if(node->left){
				BST_insert(node->left,insert_node,count_small);
			}else{
				node->left = insert_node;
			}
		}else{
			count_small += node->count + 1;
			if(node->right){
				BST_insert(node->right,insert_node,count_small);
			}else{
				node->right = insert_node;
			}
		}
	}
};

int main(){
	int test[] = {5,-7,9,1,3,5,-2,1};
	std::vector<int> nums;
	for(int i = 0; i < 8; i ++){
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	for(int i = 0; i < result.size(); i ++){
		printf("[%d]", result[i]);
	}
	printf("\n");
	return 0;
}

