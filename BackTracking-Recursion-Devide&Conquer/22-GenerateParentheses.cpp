#include<stdio.h>
#include<vector>
#include<string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate("", n, n, result);
        return result;
    }
private:
	//left:当前还能放置的左括号的数量，剩几个
	void generate(std::string item, int left, int right,
				std::vector<std::string> &result){
		if(left == 0 && right == 0){
			result.push_back(item);
			return;
		}
		if(left > 0){
			generate(item + '(', left-1, right, result);
		}
		if(left < right){
			generate(item + ')', left, right-1, result);
		}
	}
};

//练习：生成所有结果
void generate(std::string item, int n,
				std::vector<std::string> &result){
	if(item.size() == 2*n){
		result.push_back(item);
		return;
	}
	generate(item + '(', n, result);
	generate(item + ')', n, result);
}

int main(){
	std::vector<std::string> result;
	Solution solve;
	result = solve.generateParenthesis(3);
	for(int i = 0; i < result.size(); i++){
		printf("'%s'\n", result[i].c_str());
	}
	return 0;
}