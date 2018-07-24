#include<stdio.h>
#include<vector>


/*
1.原问题与子问题
2.确认状态
3.确认边界状态的值
4.状态转移方程dp[n] = dp[n-1] + dp[n-2] （i>=3）
*/
class Solution {
public:
    int climbStairs(int n) {
        
       	std::vector<int> dp(n+3,0); //传0时也按下面处理，不用写if
       	dp[1] = 1;
       	dp[2] = 2;
       	for(int i = 3; i <= n ; i ++){
       		dp[i] = dp[n-1] + dp[n-2];
       	}
       	return dp[n];
    }
};

int main(){
	Solution solve;
	printf("%d\n", solve.climbStairs(5));
	return 0;
}