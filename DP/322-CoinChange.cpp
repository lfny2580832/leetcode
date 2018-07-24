#include<stdio.h>
#include<vector>

/*
 最少数量钞票组成某个金额
 钞票面值[1,2,5,7,10],dp[i]代表金额i的最优解，i之前的最优解已知
 5个状态转移方程：
 dp[i] = dp[i-1] + 1块一张
 dp[i] = dp[i-2] + 2块一张
 dp[i] = dp[i-5] + 5块一张
 dp[i] = dp[i-7] + 7块一张
 dp[i] = dp[i-10] + 10 块一张
 
 dp[i] = min(dp[i-1],dp[i-2],dp[i-5],dp[i-7],dp[i-10]) + 1
 */
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp;
        for(int i = 0; i <= amount; i ++){
            dp.push_back(-1);
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
            	//如i=4，进入条件的是
                if(i - coins[j] >= 0 && dp[i-coins[j]] != -1){
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1){
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main(){
    Solution solve;
    std::vector<int> coins;
    // coins.push_back(1);
    coins.push_back(2);
    // coins.push_back(5);
    // coins.push_back(7);
    // coins.push_back(10);
    for(int i = 0; i <= 14; i++){
        printf("dp[%d] = %d\n", i,solve.coinChange(coins,i));
    }
    return 0;
}




















