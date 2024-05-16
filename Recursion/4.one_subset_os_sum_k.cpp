//Find any one subsequence of sum = k


bool subsetOfSumK(int idx, vector<int>ds, int sum, int k, vector<int>nums, vector<vector<int>>ans){
    if(idx == nums.size()){
        if(sum == k){
            ans.push_back(ds); 
            return true; 
        } 
        return false;
    }

    ds.push_back(nums[idx]);
    sum += nums[idx];

    if(subsetOfSumK(idx+1, ds, sum, k, nums, ans) == true) return true;
    
    sum -= nums[idx];
    ds.pop_back();

    if(subsetOfSumK(idx+1, ds, sum, k, nums, ans) == true) return true;
}

vector<vector<int>> subsets(vector<int> &nums, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;

    subsetOfSumK(0, ds, 0, k, nums, ans);

    return ans;
}