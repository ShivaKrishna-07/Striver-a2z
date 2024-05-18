// Leetcode - 46. Permutations

// Approach-1

// Time complexity: O(n!)*O(n)
// Space complexity: O(n)+O(n)
// Stack space: O(n)

void findPermutations(vector<int> &ds, int freq[], vector<int> &nums, vector<vector<int>> &ans)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            findPermutations(ds, freq, nums, ans);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;

    findPermutations(ds, freq, nums, ans);

    return ans;
}

//---------------------------------------------------------------------------------------

// Approach-2

// Time complexity: O(n!)
// Space complexity: O(1)
// Stack space: O(n)

void recurPermute(int idx, vector<int> &nums, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        recurPermute(idx + 1, nums, ans);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}