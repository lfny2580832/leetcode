#include<stdio.h>
#include<vector>
#include<algorithm>

/*

从下往上推导简单，只考虑当前元素的上方和左上方，反之太过复杂

	原三角形				最优解三角形
	2			↑		11
	3,4			↑		9,10
	6,5,7		↑		7,6,10
	4,1,8,3		↑		4,1,8,3

状态转移公式： dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j]

*/
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle) {
    	if(!triangle.size()) return 0;
    	//初始化最优值三角形dp[i][j]
    	std::vector<std::vector<int> > dp;
    	for(int i = 0; i < triangle.size(); i ++){
    		dp.push_back(std::vector<int> ());
    		for(int j = 0; j < triangle[i].size(); j ++){
    			dp[i].push_back(0);
    		}
    	}
    	//设置边界值，最优解三角形的最后一行是三角形的最后一行,最后一行的长度与高度相同
    	for(int i = 0 ; i < dp.size(); i ++){
    		dp[dp.size()-1][i] = triangle[dp.size()-1][i]; 
    	}
    	//从倒数第二行开始往上进行状态转移
    	for(int i = dp.size() - 2; i >= 0; i --){
    		for(int j = 0; j < dp[i].size(); j++){
    			dp[i][j] = std::min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
    		}
    	}
    	return dp[0][0];
    }
};

int main(){
	int triangle[][10] = {{2},{3,4},{6,5,7},{4,1,8,3}};
	std::vector<std::vector<int> > triangle_vec;
	for(int i = 0; i < 4; i++){
		triangle_vec.push_back(std::vector<int> ());
		for(int j = 0; j < i+1; j++){
			triangle_vec[i].push_back(triangle[i][j]);
		}
	}
	Solution solve;
	printf("---%d\n", solve.minimumTotal(triangle_vec));
	return 0;
}















