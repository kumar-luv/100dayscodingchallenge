#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int cows,n;
int positions[N];
bool canplacecows(int mindis){
	int lastpos = -1;
	int cows_ct = cows;
 for(int i=0;i<n;i++){
 	if(lastpos == -1 || positions[i]-lastpos>=mindis){
 		lastpos= positions[i];
 		cows_ct--;
 	}
 	if(cows_ct==0) break;
 }
 return cows_ct == 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>cows;
		for(int i=0;i<n;i++){
			cin>>positions[i];
		}
	}
	sort(positions,positions+n);
	//TTTTTFFFFFFF
	int lo = 0;
	int hi = 1e9;
	int mid;
	while(hi-lo >1){
		mid = (lo+hi)/2;
		if(canplacecows(mid)){
			lo = mid;
		}else{
			hi = mid-1;
		}
	}
	if(canplacecows(hi)){
		cout<<hi<<endl;
	}else{
		cout<<lo<<endl;
	}
}