

// Leetcode - 907. Sum of Subarray Minimums

vector<int> findNsl(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> nsl(n);

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }
    return nsl;
}
vector<int> findNsr(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> nsr(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            nsr[i] = n;
        }
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }
    return nsr;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();

    vector<int> nsl = findNsl(arr, n);
    vector<int> nsr = findNsr(arr, n);

    long long sum = 0;
    int M = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        long long ls = i - nsl[i];
        long long rs = nsr[i] - i;

        long long totalMin = ls * rs;

        long long totalSum = arr[i] * totalMin;

        sum = (sum + totalSum % M) % M;
    }
    return sum;
}