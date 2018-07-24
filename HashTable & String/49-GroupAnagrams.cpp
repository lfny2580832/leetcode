#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

//方法一，排序建map
class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
        
        //key是排序后的字符串
        std::map<std::string, std::vector<std::string> > anagram;
        std::vector<std::vector<std::string> > result;

        for(int i = 0; i < strs.size(); i ++){
        	std::string str = strs[i];
        	std::sort(str.begin(), str.end());
        	//无匹配
        	if(anagram.find(str) == anagram.end()){
        		std::vector<std::string> item;
        		anagram[str] = item;
        	}
        	anagram[str].push_back(strs[i]);
        }

        std::map<std::string, std::vector<std::string> > ::iterator it;
        for(it = anagram.begin(); it != anagram.end(); it++){
        	result.push_back((*it).second); //second是map的value
        }
        return result;
    }
};

//方法二，二进制序列建map
class Solution2{
public:
	std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
		std::map<std::vector<int> , std::vector<std::string> > anagram;
		std::vector<std::vector<std::string> > result;

		for(int i = 0; i < strs.size(); i ++){
			std::vector<int> vec;
			change_to_vec(strs[i],vec);
			if(anagram.find(vec) == anagram.end()){
				std::vector<std::string> item;
				anagram[vec] = item;
			}
			anagram[vec].push_back(strs[i]);
		}

		std::map<std::vector<int> , std::vector<std::string> > ::iterator it;
		for(it = anagram.begin(); it != anagram.end(); it++){
			result.push_back((*it).second);
		}
		return result;
	}

private:
	void change_to_vec(std::string &str, std::vector<int> &vec){
		for(int i = 0; i < 26; i ++){
			vec.push_back(0);
		}
		for(int i = 0; i < str.length(); i++){
			vec[str[i]-'a'] ++;
		}
	}
};

int main(){
	std::vector<std::string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution2 solve;
	std::vector<std::vector<std::string> > result = solve.groupAnagrams(strs);
	for(int i = 0; i < result.size(); i ++){
		for(int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}

















