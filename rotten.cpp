 #include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
//int vis[N][N];
//int level[N][N]; 
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int level[n][m];
        queue<pair<int,int>> q;
        vector<pair<int,int>> movements = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=2;
                    level[i][j]=0;
                }
                else{
                    vis[i][j]=0;
                    level[i][j]=0;
                }
            }
        }
        int ans=0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto movement : movements){
                int newx = row + movement.first;
                int newy = col +movement.second;
                if(newx<n && newy<m && newx>=0 && newy>=0 && vis[newx][newy] ==0 && grid[newx][newy]==1){
                    q.push({newx,newy});
                    vis[newx][newy]=2;
                    level[newx][newy]=level[row][col]+1;
                    ans=max(ans,level[newx][newy]);
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2&& grid[i][j]==1){
                    return -1;
                }
            }
        }
         return ans;
}
int main(){
   int t;
   cin>>t;
  for(int i = 1;i<=t;i++){
    int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int out = orangesRotting(grid);
        cout<<"#"<<i<<" "<<out<<endl;
  }
}