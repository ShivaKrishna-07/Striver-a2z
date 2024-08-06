

bool check(TreeNode *l, TreeNode *r)
{
    if (l == NULL || r == NULL)
        return l == r;

    if (l->val == r->val && check(l->left, r->right) && check(l->right, r->left))
    {
        return true;
    }
    return false;
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    return check(root->left, root->right);
}