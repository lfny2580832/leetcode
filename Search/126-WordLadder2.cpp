#include<stdio.h>
#include<vector>
#include<string>
#include<map>

struct Qitem{
	std::string node;
	int parent_pos;//前驱
	int step;//步数
	Qitem(std::string node, int parent_pos, int step):
		node(node),parent_pos(parent_pos),step(step){}
};

class Solution {
public:
    std::vector<std::vector<std::string> > findLadders(std::string beginWord,
    												  std::string endWord, 
    												  std::vector<std::string>& wordList) {
    	std::map<std::string, std::vector<std::string> > graph;
    	construct_graph(beginWord,wordList,graph);
    	std::vector<Qitem> Q;
    	std::vector<int> end_word_pos;
    	BFS_graph(beginWord,endWord,graph,Q,end_word_pos);
    	std::vector<std::vector<std::string> > result;
    	for(int i = 0; i < end_word_pos.size(); i ++){
    		int pos = end_word_pos[i];
    		std::vector<std::string> path;
    		while(pos != -1){
    			path.push_back(Q[pos].node);
    			pos = Q[pos].parent_pos;
    		}
    		result.push_back(std::vector<std::string> () );
    		for(int j = path.size()-1; j >=0; j--){
    			result[i].push_back(path[j]);
    		}
    	}
    	return result;
    }

private:
	void BFS_graph(std::string &beginWord, std::string &endWord,
				   std::map<std::string, std::vector<std::string> > &graph,
				   std::vector<Qitem> &Q,//使用vector实现队列，用于保存路径
				   std::vector<int> &end_word_pos){//终点所在队列位置下标

		std::map<std::string, int> visit;//<单词，步数>，步数即层数
		int min_step = 0;
		Q.push_back(Qitem(beginWord.c_str(), -1, 1));
		visit[beginWord] = 1;
		int front = 0; //队列头指针，用来指示各节点在vector位置
		while(front != Q.size()){
			const std::string &node = Q[front].node;//取队头元素
			int step = Q[front].step;
			if(min_step != 0 && step > min_step) break; //搜索完成
			if(node == endWord){
				min_step = step;
				end_word_pos.push_back(front);
			}
			const std::vector<std::string> &neighbors = graph[node];
			for(int i = 0; i < neighbors.size(); i ++){
				if(visit.find(neighbors[i]) == visit.end() ||
				   visit[neighbors[i]] == step + 1){//
					Q.push_back(Qitem(neighbors[i],front,step+1));
					visit[neighbors[i]] = step + 1;
				}
			}
			front ++;
		}
	}

	void construct_graph(std::string &beginWord,
						 std::vector<std::string> &wordList,
						 std::map<std::string, std::vector<std::string> > &graph){
		 int has_begin_word = 0;
        for(int i = 0; i < wordList.size(); i ++){
        	if(wordList[i] == beginWord){
        		has_begin_word = 1;
        	}
        	graph[wordList[i]] = std::vector<std::string>();
        }
        for(int i = 0; i < wordList.size(); i ++){
        	for(int j = i + 1; j < wordList.size(); j++){
        		if(connect(wordList[i], wordList[j])){
        			graph[wordList[i]].push_back(wordList[j]);
        			graph[wordList[j]].push_back(wordList[i]);
        		}
        	}
        	if(has_begin_word == 0 && connect(beginWord,wordList[i])){
        		graph[beginWord].push_back(wordList[i]);
        	}
        }
	}

	bool connect(const std::string &str1, std::string &str2){
		int cnt = 0; 
		for(int i = 0; i < str1.length(); i ++){
			if(str1[i] != str2[i]) cnt++;
		}
		return cnt == 1;
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
	std::vector<std::vector<std::string> > result = solve.findLadders(beginWord,endWord,wordList);
	for(int i = 0; i < result.size(); i ++){
		for(int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}






