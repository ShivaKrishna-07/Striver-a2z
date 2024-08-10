

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *leftN = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightN = lowestCommonAncestor(root->right, p, q);

    if (leftN == NULL)
        return rightN;
    else if (rightN == NULL)
        return leftN;
    else
        return root;
}