//Find the all subsequences of sum = k


void subsetOfSumK(int idx, vector<int>ds, int sum, int k, vector<int>nums, vector<vector<int>>ans){
    if(idx == nums.size()){
        if(sum == k) ans.push_back(ds);
        return;
    }

    ds.push_back(nums[idx]);
    sum += nums[idx];
    subsetOfSumK(idx+1, ds, sum, k, nums, ans);
    sum -= nums[idx];
    ds.pop_back();
    subsetOfSumK(idx+1, ds, sum, k, nums, ans);
}

vector<vector<int>> subsets(vector<int> &nums, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;

    subsetOfSumK(0, ds, 0, k, nums, ans);

    return ans;
}