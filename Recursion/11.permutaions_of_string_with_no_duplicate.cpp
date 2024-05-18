// GFG - Permutations of a given string

//Time complexity: O(n!) * O(n) * O(log(n!))
// Space complexity: O()
// Stack space: O(n)

void findPermutations(int idx, string &s, set<string> &ans)
{
    if (idx == s.length())
    {
        ans.insert(s);
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        swap(s[i], s[idx]);
        findPermutations(idx + 1, s, ans);
        swap(s[i], s[idx]);
    }
}

vector<string> find_permutation(string s)
{
    // Code here there
    set<string> ans;

    findPermutations(0, s, ans);
    vector<string> result(ans.begin(), ans.end());

    return result;
}