#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> previous;
       stack<int> st;
       for(int i=0;i<n;i++){
           if(st.size()==0){
               previous.push_back(-1);
           }
           else if(st.size()>0 && price[st.top()]>price[i]){
               previous.push_back(st.top());
           }
           else if(st.size()>0 && price[st.top()]<=price[i]){
               while(st.size()>0 && price[st.top()]<=price[i]){
                   st.pop();
               }
               if(st.size()==0){
                   previous.push_back(-1);
               }else{
                   previous.push_back(st.top());
               }
           }
           st.push(i);
       }
       vector<int> answer;
       for(int i=0;i<n;i++){
           answer.push_back(i-previous[i]);
       }
       return answer;
    }
};
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution obj;
    vector<int> s = obj.calculateSpan(a,n);
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}