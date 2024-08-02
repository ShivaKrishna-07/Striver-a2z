

// Postorder Traversal without using recursion with 2 stacks

vector<int> postOrder(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }
    stack<Node *> st;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                }
            }
            else
                curr = temp;
        }
    }
}