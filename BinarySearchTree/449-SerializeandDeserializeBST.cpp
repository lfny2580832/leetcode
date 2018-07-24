#include<stdio.h>
#include<vector>
#include<string>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):
		val(x),left(NULL),right(NULL){}	
};

//原理：将前序序列，重新插入一颗空树，得到的树跟原树一样
class Codec {
public:

    // Encodes a tree to a single string.
    //需要每个数之间用特殊符号分开，否则无法拆
    std::string serialize(TreeNode* root) {
        std::string data;
        BST_preoder(root,data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if(data.length() == 0) return NULL;
        std::vector<TreeNode *> node_vec;
        int val = 0;
        for(int i = 0; i < data.length(); i++){
        	if(data[i] == '#'){
        		node_vec.push_back(new TreeNode(val));
        		val = 0;
        	}else{
        		val = val*10 + data[i]-'0';
        	}
        }
        for(int i = 1; i < node_vec.size(); i ++){
        	BST_insert(node_vec[0],node_vec[i]);
        }
        return node_vec[0];
    }

private:
	void BST_insert(TreeNode *node, TreeNode *insert_node){
		if(insert_node->val < node->val){
			if(node->left){BST_insert(node->left, insert_node);}
			else{node->left = insert_node;}
		}else{
			if(node->right){BST_insert(node->right, insert_node);}
			else{node->right = insert_node;}
		}
	}

	//将1个int转换为string 如 15--》'15#'
	void change_int_to_string(int val, std::string &str_val){
		std::string tmp;
		while(val){
			tmp += val%10 + '0';
			val = val/10;
		}
		for(int i = tmp.length()-1; i >=0; i --){
			str_val += tmp[i];
		}
		str_val += '#';
	}

	//用前序遍历将树转化为字符串
	void BST_preoder(TreeNode *node, std::string &data){
		if(!node) return;
		std::string str_val;
		change_int_to_string(node->val, str_val);
		data += str_val;
		BST_preoder(node->left, data);
		BST_preoder(node->right, data);
	}
};


bool BST_search(TreeNode *node, int target){
	if(node->val == target) return true;
	if(target < node->val){
		if(node->left){return BST_search(node->left, target);}
		else{return false;}
	}else{
		if(node->right){return BST_search(node->right, target);}
		else{return false;}
	}
}

void preoder_print(TreeNode *node,int layer){
	if(!node) return;
	for(int i = 0; i < layer; i ++){
		printf("---");
	}
	printf("[%d]\n", node->val);
	preoder_print(node->left,layer+1);
	preoder_print(node->right,layer+1);
}

int main(){
	TreeNode a(8);
	TreeNode b(3);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	Codec solve;
	std::string data = solve.serialize(&a);
	printf("%s\n", data.c_str());
	TreeNode *root = solve.deserialize(data);
	preoder_print(root,0);
}






