#include<stdio.h>
#include<vector>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>

/*
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5
*/
class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::map<std::string , std::vector<std::string> > graph;
        construct_graph(beginWord,wordList,graph);
        return BFS_graph(beginWord,endWord,graph);
    }

private:
	int BFS_graph(std::string &beginWord, std::string &endWord,
				  std::map<std::string, std::vector<std::string> > &graph){

		std::queue<std::pair<std::string ,int> > Q;
		std::set<std::string> visit;
		Q.push(std::make_pair(beginWord,1));
		visit.insert(beginWord);
		while(!Q.empty()){
			std::string node = Q.front().first;
			int step = Q.front().second;
			Q.pop();
			if(node == endWord) return step;
			const std::vector<std::string> &neighbors = graph[node];
			for(int i = 0; i < neighbors.size(); i ++){
				if(visit.find(neighbors[i])  == visit.end()){
					Q.push(std::make_pair(neighbors[i], step+1));
					visit.insert(neighbors[i]);
				}
			}
		}
		return 0;
	}

	//str1、str2只差一个字母
	bool connect(const std::string &str1, std::string &str2){
		int cnt = 0; 
		for(int i = 0; i < str1.length(); i ++){
			if(str1[i] != str2[i]) cnt++;
		}
		return cnt == 1;
	}

	//构造图
	void construct_graph(std::string &beginWord, 
						 std::vector<std::string> &wordList,
						 std::map<std::string, std::vector<std::string> > &graph){
		wordList.push_back(beginWord);
		for(int i = 0; i < wordList.size(); i ++){
			//wordList[i]是个单词
			graph[wordList[i]] = std::vector<std::string>();
		}
		for(int i = 0; i < wordList.size(); i ++){
			//j从i+1开始，避免重复，因为j之前的在i遍历时已经双向连接
			for(int j = i+1; j < wordList.size(); j++){
				if(connect(wordList[i], wordList[j])){
					//无向图，双向连接
					graph[wordList[i]].push_back(wordList[j]);
					graph[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}
};

int main(){
	std::string beginWord = "hit";
	std::string endWord = "cog";
	std::vector<std::string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");
	Solution solve;
	int result = solve.ladderLength(beginWord,endWord,wordList);
	printf("result = %d\n", result);
	return 0;
}










