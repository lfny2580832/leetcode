#include<vector>

class Solution {
public:
	//g:greed factor of kids; s:size of cookies
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        //排序g、s
    	std::sort(g.begin(),g.end());
    	std::sort(s.begin(),s.end());
        int cookie = 0;
        int child = 0;
        while(child < g.size() && cookie < s.size()){
        	if(s[cookie] >= g[child]){
        		child++;
        	}
        	cookie++;
        }
        return child;
    }
};

int main(){
	std::vector<int> g;
	std::vector<int> s;
	
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);

	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);

	Solution solve;
	int result = solve.findContentChildren(g,s);
	printf("%d\n", result);
	return 0;
}