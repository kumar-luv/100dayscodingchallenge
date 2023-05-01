#include<bits/stdc++.h>
using namespace std;
vector<int> nextgreater(vector<int> v,int n){
	stack<int> st;
	vector<int> ans;
	for(int i=n-1;i>=0;i--){
		if(st.empty()){
			ans.push_back(-1);
		}else if(st.size()>0 && st.top()>v[i]){
			ans.push_back(st.top());
		}else if(st.size()>0 && st.top()<=v[i]){
			while(st.size()>0 &&  st.top()<=v[i]){
				st.pop();
			}
			if(st.empty()){
				ans.push_back(-1);
			}else{
				ans.push_back(st.top());
			}
		}
		st.push(v[i]);

	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int>nge = nextgreater(v,n);
	for(int i=0;i<v.size();i++){
		cout<<nge[i]<<" ";
	}
}