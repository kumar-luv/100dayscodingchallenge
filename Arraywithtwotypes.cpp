#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int n){
    int i=-1,j=n;
    while(true)
    {
        do{i++;}while(arr[i]%2!=0);
        do{j--;}while(arr[j]%2==0);
        if(i>=j)return;
        swap(arr[i],arr[j]);
    }
}

int main() {
	
    int arr[]={10,8,7,9,12};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,n);
	
	for(int x:arr)
	    cout<<x<<" ";
}