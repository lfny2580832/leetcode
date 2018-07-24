#include<stdio.h>
#include<vector>
#include<string>

class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        //每当一次递归找到结果，将location push进result
        //location用.来初始化，mark用0初始化
        std::vector<std::string> location;
		std::vector<std::vector<std::string> > result;
		std::vector<std::vector<int> > mark;

		for (int i = 0; i < n; ++i){
			mark.push_back(std::vector<int>());
			for (int j = 0; j < n; ++j){
				mark[i].push_back(0);
			}
			location.push_back("");
			location[i].append(n, '.');
		}
		generate(0, n, location, result, mark);
		return result;
    }

private:
	void put_down_the_queen(int x, int y, std::vector<std::vector<int> > &mark){
		static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
		static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

		mark[x][y] = 1;
		for(int i = 1; i < mark.size(); i++){
			for(int j = 0; j < 8; j++){
				int new_x = x + i * dx[j];
				int new_y = y + i * dy[j];
				if(new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()){
					mark[new_x][new_y] = 1;
				}
			}
		}
	}

	/*
	k:正在放置第k行皇后
	location:某次结果
	result:	 最终结果
	mark: 	 棋盘标记数组
	*/
	void generate(int k, int n, std::vector<std::string> &location,
								std::vector<std::vector<std::string> > &result,
								std::vector<std::vector<int> > &mark){

		if(k == n){
			result.push_back(location);
			return;
		}
		for(int i = 0; i < n ; i++){
			if(mark[k][i] == 0){	//满足条件，放置皇后
				std::vector<std::vector<int> > temp_mark = mark; //用于回溯
				location[k][i] = 'Q';
				put_down_the_queen(k, i , mark);
				generate(k+1, n, location, result, mark);
				/*
				如当第k行的i=2，4列时可以放置，(运行generat)，
				则当(k,2)的尝试不行时(不做任何处理，没写else，因为没改变状态)，撤回到上个状态，进行(k,4)的放置
				*/
				mark = temp_mark;
				location[k][i] = '.';
			}
			//都是1，第i行没地放，for循环结束，回溯
		}
	}

};

int main(){
	std::vector<std::vector<std::string> > result;
	Solution solve;
	result = solve.solveNQueens(4);
	for (int i = 0; i < result.size(); ++i){
		printf("i = %d\n", i);
		for(int j = 0; j < result[i].size(); j++){
			printf("%s\n", result[i][j].c_str());
		}
		printf("\n");
	}
}

