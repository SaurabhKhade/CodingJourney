class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        if (root->val == subRoot->val && isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == NULL && tree2 == NULL) return true;
        if (tree1 == NULL || tree2 == NULL) return false;
        if (tree1->val != tree2->val) return false;
        return isSameTree(tree1->left, tree2->left) && isSameTree(tree1->right, tree2->right);
    }
};