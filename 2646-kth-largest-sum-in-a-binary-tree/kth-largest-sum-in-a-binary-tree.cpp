class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> vec;
        traverse(root, vec, 0);

        sort(vec.begin(), vec.end(), greater<long long>());

        if (vec.size() < k) return -1;
        return vec[k-1];
    }

    void traverse(TreeNode* root, vector<long long> &vec, int level) {
        if (root == NULL) return;
        if (vec.size() == level) vec.resize(level+1);
        vec[level] += root->val;

        traverse(root->left, vec, level+1);
        traverse(root->right, vec, level+1);
    }
};