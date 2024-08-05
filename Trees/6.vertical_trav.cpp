

void preorder(TreeNode *root, int v, int l, map<int, map<int, multiset<int>>> &nodes)
{
    if (root == NULL)
        return;

    nodes[v][l].insert(root->val);
    preorder(root->left, v - 1, l + 1, nodes);
    preorder(root->right, v + 1, l + 1, nodes);
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;

    preorder(root, 0, 0, nodes);

    vector<vector<int>> ans;

    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}