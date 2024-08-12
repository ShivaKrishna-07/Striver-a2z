

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;

    int lh = findLeftH(root);
    int rh = findRightH(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findLeftH(TreeNode *node)
{
    int h;
    while (node)
    {
        h++;
        node = node->left;
    }
    return h;
}
int findRightH(TreeNode *node)
{
    int h;
    while (node)
    {
        h++;
        node = node->right;
    }
    return h;
}