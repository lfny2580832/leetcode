#include<vector>
#include<queue>
//贪心规律：用光的时候加油最合适，油量最多的加油站加油最合适
/*
1.设置最大堆，存储经过的加油站的汽油量
2.遍历各个加油站之间的距离
3.每次需要走两个加油站之间的距离d，若汽油不够走d时，从最大堆中取出一个油量添加，直到
足够走d
4.如果把最大堆的汽油都添加仍然不够行进d，无法达到
5.当前油量减少p
6.将当前加油站油量添加至最大堆

trick：从全局考虑，并不是按实际开车加油走的顺序考虑。
相当于第一次把油走光，再看之前加油站哪个多，应该在哪些地方加
然后第二次走的时候从选出来的那些加油站加油
*/

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b){
	return a.first < b.first;
}
//pair<加油站到终点的距离，加油站汽油量>,L为起点到终点的距离,P为初始油量
int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop){
	std::priority_queue<int> Q;	//油量最大堆
	int result = 0;
	stop.push_back(std::make_pair(0,0));
	std::sort(stop.begin(), stop.end(), cmp);
	//一个加油站到下一个加油站
	for(int i = 0; i < stop.size(); i++){
		int dis = L - stop[i].first; //加油站之间的距离
		while(dis > P && !Q.empty()){
			P = P + Q.top();
			Q.pop();
			result ++;
		}
		if(Q.empty() && dis < P) return -1;
		P = P - dis;
		L = stop[i].first;
		Q.push(stop[i].second);
	}
	return result;
} 

int main(){
	std::vector<std::pair<int, int> > stop;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &distance, &fuel);
		stop.push_back(std::make_pair(distance,fuel));
	}
	scanf("%d %d", &L, &P);
	printf("%d\n", get_minimum_stop(L,P,stop));
	return 0;
}


