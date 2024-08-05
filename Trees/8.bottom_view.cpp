

vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int l = it.second;

        mp[l] = node->data;

        if (node->left != NULL)
            q.push({node->left, l - 1});
        if (node->right != NULL)
            q.push({node->right, l + 1});
    }

    for (auto p : mp)
    {
        ans.push_back(p.second);
    }

    return ans;
}