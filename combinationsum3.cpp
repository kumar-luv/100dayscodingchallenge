class Solution {
public:
void solve(int index, int n, int k, vector<vector<int>> &ans,vector<int>& ds,vector<int> &arr){

    if(n==0){
        if(ds.size()==k){
            ans.push_back(ds);
        }
        return;
    }
    for(int i=index;i<9;i++){
        if(arr[i]>n) break;
        ds.push_back(arr[i]);
        solve(i+1,n-arr[i],k,ans,ds,arr);
        ds.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
         for (int i = 1; i <= 9; i++) {
        arr.push_back(i);
}
        vector<vector<int>> ans;
        vector<int> ds;
        // int sum=0;
        solve(0,n,k,ans,ds,arr);
        return ans;
    }
};