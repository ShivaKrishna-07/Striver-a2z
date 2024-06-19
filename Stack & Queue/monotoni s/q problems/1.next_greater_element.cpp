

// GFG - Next Greater Element

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    vector<long long> nge(n, -1);
    stack<long long> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (i < n)
        {
            if (!st.empty())
                nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}