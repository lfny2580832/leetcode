#include<stdio.h>
#include<vector>
#include<algorithm>

/*
input:{10,9,2,5,3,7,101,18}
output:4    
explanation:[2,3,7,101]

设第i个状态dp[i]，表示以第i个位置为结尾的最长上升序列的长度
若代表前i个元素中最长上升子序列，则找不到状态方程

以{1,3,2,3,1,4}为例

		   元素i		dp[5]对应的nums[5]是4，则4：
dp[0] = 1,  [1]		大于dp[0]对应的元素[1]，dp[5]至少=dp[0]+1 = 2
dp[1] = 2,	[3]		大于dp[1]对应的元素[3]，dp[5]至少=dp[1]+1 = 3
dp[2] = 2,	[2]		大于dp[2]对应的元素[2]，dp[5]至少=dp[2]+1 = 3
dp[3] = 3,	[3]		大于dp[3]对应的元素[3]，dp[5]至少=dp[3]+1 = 4
dp[4] = 1,	[1]		大于dp[4]对应的元素[1]，dp[5]至少=dp[4]+1 = 2
dp[5] = ？
*/

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
    	if(!nums.size())  return 0;
    	std::vector<int> dp(nums.size(),1);
    	int LIS = 1;
    	for(int i = 0; i < dp.size(); i ++){
    		int dp_i = 1;
    		for(int j = 0; j < i; j ++){
    			if(nums[i] > nums[j]){
    				int tmp_dp_i = dp[j] + 1;
    				if(dp_i < tmp_dp_i){
    					dp_i = tmp_dp_i;
    				}
    			}
    		}
    		dp[i] = dp_i;
    		if(LIS < dp[i]){
    			LIS = dp[i];
    		}
    	}
    	return LIS;
    }
};

int main(){
	// int nums[] = {10,9,2,5,3,7,101,18};
	int nums[] = {1,3,2,3,1,4,5,3};
	std::vector<int> nums_vec;
	for(int i = 0; i < 8; i ++){
		nums_vec.push_back(nums[i]);
	}
	Solution solve;
	printf("----%d\n", solve.lengthOfLIS(nums_vec));
	return 0;
}