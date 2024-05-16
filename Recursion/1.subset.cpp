// Leetcode - 78.Subsets
//Find all the subsequences of the given array

// Time complexity = O(2^n)
// Space complexity = O(n) - stack space(depth of recursion tree)

void findSubset(int idx, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    ds.push_back(nums[idx]);
    findSubset(idx + 1, ds, nums, ans);
    ds.pop_back();
    findSubset(idx + 1, ds, nums, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;

    findSubset(0, ds, nums, ans);

    return ans;
}