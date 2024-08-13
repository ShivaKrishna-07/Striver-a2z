


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, int ps, int pe,
                        vector<int>& inorder, int is, int ie,
                        map<int, int>& inMap) {
        if (ps > pe || is > ie) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - is;

        root->left = buildTree(postorder, ps, ps + numsLeft-1,
                               inorder, is, inRoot - 1, inMap);

        root->right = buildTree(postorder, ps + numsLeft, pe-1,
                                inorder, inRoot + 1, ie, inMap);

        return root;
    }