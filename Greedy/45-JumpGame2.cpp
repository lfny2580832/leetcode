#include<vector>

class Solution {
public:
	//贪心策略：若从第0个位置可跳至第i个位置
	//第i个位置可跳到第index[i]的位置，index[i]=i+nums[i]
	//则应跳至这些位置里，又可向前跳到更远位置的位置上
    int jump(std::vector<int>& nums) {
    	if(nums.size() < 2) return 0;
        int current_max = nums[0];//当前能跳到的最大位置
        int next_max = nums[0];//下一步能跳到的最大位置
        int jump_min = 1;
        for(int i = 0; i < nums.size(); i++){
            //指针无法再向前移动时，进行跳跃
            if(i > current_max){
                jump_min++;
                current_max = next_max;
            }
            if(next_max < nums[i] + i) next_max = nums[i] + i;
        }
        return jump_min;
    }
};

int main(){
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(4);

	Solution solve;
	int result = solve.jump(v);
	printf("%d\n", result);
	return 0;
}