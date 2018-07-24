#include<stack>
#include<sting>

class Solution {
public:
	//移掉k个数字，不一定连续k个
	//说白了就是碰到小的就把大的弹出来，弹k次
    std::string removeKdigits(std::string num, int k) {
    	std::vector<int> S;//把vector当栈用
    	std::string result = "";
    	for(int i = 0; i < num.length(); i++){
    		int number = num[i] - '0';//将字符转化为整型
    		while(S.size() && number < S[S.size()-1] && k > 0){
    			S.pop_back();
    			k--;
    		}
    		//1.栈不空，0或非0都可以进
    		//2.数字不为0，栈空不空都可以进
    		//********** NOTICE **************
    		if(S.size() || number) S.push_back(number);
    	}
    	//没删够k的情况
    	while(S.size() && k > 0){
    		S.pop_back();
    		k--;
    	}
    	//遍历，存储
    	for(int i = 0; i < S.size(); i++){
    		result.append(1, S[i] + '0'); 
    	}
    	if(result == "") result = "0";
    	return result;

    }
};