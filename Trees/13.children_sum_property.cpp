

int isSumProperty(Node *root)
{
    // Add your code here
    if (!root || (!root->left && !root->right))
        return 1;

    int leftSum = 0, rightSum = 0;
    if (root->left)
        leftSum = root->left->data;
    if (root->right)
        rightSum = root->right->data;

    if (root->data == (leftSum + rightSum) && isSumProperty(root->left) && isSumProperty(root->right))
    {
        return 1;
    }
    return 0;
}