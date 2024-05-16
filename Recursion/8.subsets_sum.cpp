// GFG - Subsets sum
// Print the sum's of all subsequences in an array

void solve(int idx, int sum, vector<int> &arr, int n, vector<int> &ans)
{
    if (idx == n)
    {
        ans.push_back(sum);
        return;
    }

    // Pick
    solve(idx + 1, sum + arr[idx], arr, n, ans);

    // Not pick
    solve(idx + 1, sum, arr, n, ans);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    // Write Your Code here
    vector<int> ans;

    solve(0, 0, arr, n, ans);

    return ans;
}