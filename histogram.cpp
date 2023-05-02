#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    long long getMaxArea(long long arr[], int n)
    {
         vector<int> previous;
       stack<int> st1;
       for(int i=0;i<n;i++){
           if(st1.size()==0){
               previous.push_back(-1);
           }
           else if(st1.size()>0 && arr[st1.top()]<arr[i]){
               previous.push_back(st1.top());
           }
           else if(st1.size()>0 && arr[st1.top()]>=arr[i]){
               while(st1.size()>0 && arr[st1.top()]>=arr[i]){
                   st1.pop();
               }
               if(st1.size()==0){
                   previous.push_back(-1);
               }else{
                   previous.push_back(st1.top());
               }
           }
           st1.push(i);
       }
        vector<int> next;
       stack<int> st2;
       for(int i=n-1;i>=0;i--){
           if(st2.size()==0){
               next.push_back(n);
           }
           else if(st2.size()>0 && arr[st2.top()]<arr[i]){
               next.push_back(st2.top());
           }
           else if(st2.size()>0 && arr[st2.top()]>=arr[i]){
               while(st2.size()>0 && arr[st2.top()]>=arr[i]){
                   st2.pop();
               }
               if(st2.size()==0){
                   next.push_back(n);
               }else{
                   next.push_back(st2.top());
               }
           }
           st2.push(i);
       }
        long long ans = INT_MIN;
        for(int i=0;i<n;i++){
            long long maxarea = ((next[n-1-i]-previous[i]-1)*arr[i]);
            if(maxarea>ans){
                ans=maxarea;
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.getMaxArea(arr,n);
}