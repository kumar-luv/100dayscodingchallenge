class Solution {
public:

    void solve(vector<int> nums, int index, vector<vector<int>> & ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, index + 1, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans, res;
        int index = 0;

        map<vector<int>, int> mp;

        solve(nums, index, ans);

        for(int i = 0; i < ans.size(); i++)
        {
            mp[ans[i]]++;
        }

        for(auto & it: mp)
        {
            res.push_back(it.first);
        }

        return res;
    }
};