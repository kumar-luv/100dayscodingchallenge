class Solution {
public:
// int res[40];
    void combinations(vector<vector<int>> &ans,vector<int>& candidates,int index,int sum,int target,vector<int> &ds){
        int n= candidates.size();
	if(index>=n)
		return;
	if(sum>target)
		return;
	if(sum==target){
        ans.push_back(ds);
		return;
	}
    // res[len]=candidates[index];
    ds.push_back(candidates[index]);
    sum += candidates[index];
	combinations(ans,candidates,index,sum,target,ds);
    sum -= candidates[index];
    ds.pop_back();
	combinations(ans,candidates,index+1,sum,target,ds);
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(ans,candidates,0,0,target,ds);
        return ans;
    } 
};