class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> vec(100001, 0);
        traverse(root, vec, 0);

        sort(vec.begin(), vec.end(), greater<long long>());

        if (vec[k-1] == 0) return -1;
        return vec[k-1];
    }

    void traverse(TreeNode* root, vector<long long> &vec, int level) {
        if (root == NULL) return;
        // cout<<level<<" ";
        vec[level] += static_cast<long long>(root->val);

        traverse(root->left, vec, level+1);
        traverse(root->right, vec, level+1);
    }
};