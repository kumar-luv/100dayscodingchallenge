#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int visited[N];
int level[N];
void bfs(int source){
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	while(!q.empty()){
		int curr_v = q.front();
		q.pop();
		for(int child: graph[curr_v]){
			if(!visited[child]){
				q.push(child);
				visited[child]=1;
				level[child]=level[curr_v]+1;
			}
		}
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(1);
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<level[i]<<endl;
	}
}

