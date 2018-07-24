#include<vector>

class Solution {
public:
	//贪心策略：若从第0个位置可跳至第i个位置
	//第i个位置可跳到第index[i]的位置，index[i]=i+nums[i]
	//则应跳至这些位置里，又可向前跳到更远位置的位置上
    bool canJump(std::vector<int>& nums) {
    	std::vector<int> index;
        for(int i = 0; i < nums.size(); i++){
        	index.push_back(i + nums[i]);
        }
        int pos = 0;//当前跳到的在数组中位置
        int max_index = index[0];//能跳到的最大位置

        //******跳到所指位置************跳到数组尾部*****
        while(pos <= max_index && pos < nums.size()){
        	if(max_index < index[pos]){
        		max_index = index[pos];
        	}
        	pos++;
        }
        if(pos == nums.size()) return true;
        //若pos < nums.size()就跳出循环了
        //说明pos++之后大于max_index了
        return false;
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
	bool result = solve.canJump(v);
	printf("%d\n", result);
	return 0;
}