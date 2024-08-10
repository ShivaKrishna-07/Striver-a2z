

void findPath(Node *root, vector<vector<int>> &ans, vector<int> &ds)
{
    if (root == NULL)
        return;
    ds.push_back(root->data);
    if (root->right == NULL && root->left == NULL)
    {
        ans.push_back(ds);
    }

    findPath(root->left, ans, ds);
    findPath(root->right, ans, ds);
    ds.pop_back();
}

vector<vector<int>> Paths(Node *root)
{
    // code here
    vector<vector<int>> ans;
    vector<int> ds;
    findPath(root, ans, ds);
    return ans;
}