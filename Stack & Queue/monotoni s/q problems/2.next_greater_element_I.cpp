

// Leetcode - 496. Next Greater Element I

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    stack<int> s;
    vector<int> ans;
    unordered_map<int, int> m;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums2[i])
        {
            s.pop();
        }
        if (!s.empty())
            m[nums2[i]] = s.top();
        s.push(nums2[i]);
    }
    for (int num : nums1)
    {
        if (m[num])
            ans.push_back(m[num]);
        else
            ans.push_back(-1);
    }
    return ans;
}