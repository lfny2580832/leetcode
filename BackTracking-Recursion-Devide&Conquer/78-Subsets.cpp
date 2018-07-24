#include<vector>

class Solution {
public:
    vector<vector<int>> subsets(std::vector<int>& nums) {
		std::vector<std::vector<int> > result;
		std::vector<int> item;
		//空集      
		result.push_back(item);
		generate(0, nums, item, result);
		return result;
    }
private:
	void generate(int i,std::vector<int> &nums,
						std::vector<int> &item,
						std::vector<std::vector<int> > &result){
		if(i >= nums.size()) return;
		item.push_back(nums[i]);
		result.push_back(item);
		//选择加入
		generate(i+1, nums, item, result);
		//选择不加入
		item.pop_back();
		generate(i+1, nums, item, result);
	}
};