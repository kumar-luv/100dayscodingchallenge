#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e3+10; 
vector<int> graph_dfs[N];
int depth[N],height[N];

void dfs(int vertex,int parent=0) 
{
	/*
	Take action on vertex after entering the vertex
	*/
 
	for(int child : graph_dfs[vertex]) 
	{
		/*
		take action on child node before entering child node
		*/
		if(child==parent)continue;
        depth[child]=depth[vertex]+1;
		dfs(child,vertex);
		/*
		Take action on child after exiting child node
		when you are returning
		*/
        height[vertex]=max(height[vertex], height[child]+1);
	}
	/*
	Take action on vertex before exiting the vertex
	when you visited all childs of vertex
	*/ 
 
}
int main()
{
    int n;
    cin>>n;
	for(int i=0;i<n;i++)
	{ 
		int v1,v2; 
		cin>>v1>>v2;
       graph_dfs[v1].push_back(v2);
	   graph_dfs[v2].push_back(v1);
 
	}
    
     dfs(1);	
    for(int i=1;i<=n;i++)
    {
        cout<<depth[i]<<" "<<height[i]<<"\n";
    }

	return 0;
}