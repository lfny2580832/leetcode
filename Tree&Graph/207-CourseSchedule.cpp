#include<stdio.h>
#include<vector>
#include<queue>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x): label(x){};
};
//本质是判断图是否有环
class Solution{
public:
	//<课程1,课程2>，代表课程1依赖课程2
	//用拓扑排序
	bool canFinish(int numCourse, 
				   std::vector<std::pair<int,int> > &preRequisites){
		std::vector<GraphNode *> graph;
		std::vector<int> degree;

		for(int i = 0; i < numCourse; i ++){
			degree.push_back(0);
			graph.push_back(new GraphNode(i));
		}
		for(int i = 0; i < preRequisites.size(); i++){
			GraphNode *begin = graph[preRequisites[i].second];
			GraphNode *end = graph[preRequisites[i].first];
			begin->neighbors.push_back(end);
			degree[preRequisites[i].first] += 1;
		}
		std::queue<GraphNode *>Q;
		for(int i = 0; i < numCourse; i ++){
			if(degree[i] == 0){
				Q.push(graph[i]);
			}
		}
		while(!Q.empty()){
			GraphNode *node = Q.front();
			Q.pop();
			for(int i = 0; i < node->neighbors.size(); i ++){
				degree[node->neighbors[i]->label] --;
				if(degree[node->neighbors[i]->label] == 0){
					Q.push(node->neighbors[i]);
				}
			}
		}
		for(int i = 0; i < graph.size(); i ++){
			delete graph[i];
		}
		for(int i = 0; i < degree.size(); i ++){
			if(degree[i]){
				return false;
			}
		}
		return true;
	}
	//用DFS
	bool canFinish1(int numCourse,
				   std::vector<std::pair<int,int> >&preRequisites){
		std::vector<GraphNode* > graph;
		std::vector<int> visit;//-1未访问，0正在访问，1已访问完成
		for(int i = 0; i < numCourse; i++){
			graph.push_back(new GraphNode(i));
			visit.push_back(-1);
		}
		for(int i = 0; i < preRequisites.size(); i++){
			GraphNode *begin = graph[preRequisites[i].second];
			GraphNode *end = graph[preRequisites[i].first];
			begin->neighbors.push_back(end);
		}
		for(int i = 0; i < graph.size(); i++){
			if(visit[i] == -1 && !DFS_graph(graph[i],visit)){
				return false;
			}
		}
		for(int i = 0; i < numCourse; i++){
			delete graph[i];
		}
		return true;
	}

private:
	//返回ture 1无环，返回false 0有环
	bool DFS_graph(GraphNode *node, std::vector<int> &visit){
		visit[node->label] = 0;
		for(int i = 0; i < node->neighbors.size(); i++){
			//深度遍历到二层以上时时遇到了环
			if(visit[node->neighbors[i]->label] == -1){
				if(DFS_graph(node->neighbors[i],visit) == 0){
					return false;
				}
			}
			//1->2,2->1，最简单的环
			else if(visit[node->neighbors[i]->label] == 0){
				return false;
			}
		}
		visit[node->label] = 1;
		return true;
	}

};



int main(){
	std::vector<std::pair<int , int> > preRequisites;
	preRequisites.push_back(std::make_pair(1,0));
	preRequisites.push_back(std::make_pair(2,0));
	preRequisites.push_back(std::make_pair(3,1));
	preRequisites.push_back(std::make_pair(3,2));
	Solution solve;
	printf("%d\n", solve.canFinish(4,preRequisites));
	return 0;
}








