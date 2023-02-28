#include<bits/stdc++.h>
using namespace std;
	unordered_map<char,int> symbol = {{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
	string isbalanced(string s){
		stack<char> st;
		for(auto bracket : s){
			if(symbol[bracket]<0){
				st.push(bracket);
			}else {
				if(st.empty()) return "NO";
				char top = st.top();
				st.pop();
				if(symbol[bracket] + symbol[top] !=0){
					return "NO";
				}
			}
		}
		if(st.empty()) return "YES";
		return "NO";
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<< isbalanced(s) <<endl;
	}

}	
