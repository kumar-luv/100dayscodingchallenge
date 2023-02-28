#include<bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);
class Solution
{
    private:
    vector<string> valid;
    void generate(string &s, int open, int close){
        if(close == 0 && open ==0){
            valid.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            generate(s,open-1,close);
            cout<<s<<endl;
            s.pop_back();
            cout<<s<<endl;
        }
        if(close>0){
            if(open<close){
                s.push_back(')');
                //cout<<s<<endl;
                generate(s,open,close-1);
                s.pop_back();
                //cout<<s<<endl;
            }
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
       string s;
       generate(s,n,n);
       return valid;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution obj;
        vector<string> result = obj.AllParenthesis(n);
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<"\n";
        }
    }
    return 0;
}