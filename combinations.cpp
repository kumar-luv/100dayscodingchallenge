#include<bits/stdc++.h>
using namespace std;
int arr[20];
int res[20];
int n;
int target;
void combinations(int index, int len,int sum){
	if(index>=n)
		return;
	if(sum>target)
		return;
	if(sum==target){
		for(int i=0;i<len;i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
		return;
	}

	res[len]=arr[index];
	combinations(index,len+1,sum+arr[index]);
	combinations(index+1,len,sum);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>target;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			arr[i]=x;
		}
		int sum=0;
		combinations(0,0,0);
	}
}