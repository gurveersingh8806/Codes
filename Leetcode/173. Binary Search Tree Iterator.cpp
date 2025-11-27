class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        int val = curr->val;
        if (curr->right) {
            pushLeft(curr->right);
        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
