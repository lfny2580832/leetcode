#include<stdio.h>
#include<string>

//滑动窗口[begin,i]思路
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int begin = 0;
        int result = 0;
        std::string word = "";
        int char_map[128] = {0};
        for(int i = 0 ; i < s.length(); i ++){
        	char_map[s[i]] ++;
        	if(char_map[s[i]] == 1){ //map加了=1，说明之前是0，没出现过该字符
        		word += s[i];
        		if(result < word.length()) result = word.length();
        	}else{

        		//------------------------
        		//当s[i]对应的字母（如b）在begin位置被减掉后，begin到达新的位置
	        	while(char_map[s[i]] > 1){	//此条件已包含begin<i
	        		char_map[s[begin]]--;
	        		begin++;
	        	}
	        	//------------------------

	        	//重新构造begin和i之间的分词word
	        	word = "";
	        	for(int j = begin; j <= i ; j++){
	        		word += s[j];
	        	}
	        }
	    }
	    return result;
    }
};

int main(){
	std::string s = "abcbadab";
	Solution solve;
	printf("最长子串长度为 %d\n", solve.lengthOfLongestSubstring(s));
	return 0;
}