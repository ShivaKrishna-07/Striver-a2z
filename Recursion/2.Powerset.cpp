// GFG - Power Set
//Powerset: all subsequences except empty set

// Time complexity = O(2^n)
// Space complexity = O(n) - stack space(depth of recursion tree)

void findPowerset(int idx, string &str, string &s, vector<string> &ans)
{

    if (idx >= s.length())
    {
        if (str != "")
        {
            ans.push_back(str);
        }
        return;
    }

    str.push_back(s[idx]);
    findPowerset(idx + 1, str, s, ans);
    str.pop_back();
    findPowerset(idx + 1, str, s, ans);
}

vector<string> AllPossibleStrings(string s)
{
    // Code here
    vector<string> ans;
    string str = "";
    findPowerset(0, str, s, ans);

    sort(ans.begin(), ans.end());
    return ans;
}