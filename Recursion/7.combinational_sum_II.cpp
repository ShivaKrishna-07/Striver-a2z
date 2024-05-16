// Leetcode - 40. Combinationa Sum II

void findCombination(int idx, int target, vector<int> &ds, vector<int> &candidates, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        findCombination(i + 1, target - candidates[i], ds, candidates, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;

    findCombination(0, target, ds, candidates, ans);

    return ans;
}