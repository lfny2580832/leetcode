//从1到n入栈，判断出栈序列是否合法
#include <stack>
#include <queue>

bool check_is_valid_order(std::queue<int> &order){
	std::stack<int> s;
	int n = order.size();
	for(int i = 1; i <= n; i++){
		s.push(i);
		while(s.top() == order.pop() && !s.empty()){
			s.pop();
			order.pop();
		}
	}
	if(!s.empty()){
		return false;
	}
	return true;
}

int main(){
	int n;
	int train;
	scanf("%d", &n);
	while(n){
		scanf("%d",&train);
		while(train){
			std::queue<int> order;
			order.push(train);
			for(int i = 1; i < n; i++){
				scanf("%d",&train);
				order.push(train);
			}
			if(check_is_valid_order(order)){
				printf("Yes\n");			
			}else{
				printf("No\n");
			}
			scanf("%d",&train);
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}