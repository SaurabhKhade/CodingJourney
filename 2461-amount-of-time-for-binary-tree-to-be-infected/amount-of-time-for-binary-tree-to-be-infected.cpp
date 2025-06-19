/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int depthFromTarget = 0;
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parents;
        unordered_map<int, bool> visited;
        queue<TreeNode*> q1;
        TreeNode* startNode;

        q1.push(root);

        while (!q1.empty()) {
            TreeNode* front = q1.front();
            q1.pop();

            if (front->val == start) {
                startNode = front;
            }
            if (front->left != NULL) {
                parents[front->left->val] = front;
                q1.push(front->left);
            }
            if (front->right != NULL) {
                parents[front->right->val] = front;
                q1.push(front->right);
            }
        }

        queue<pair<TreeNode*, int>> q2;

        q2.push({startNode, 0});
        visited[start] = true;
        int time = 0;

        while (!q2.empty()) {
            TreeNode* node = q2.front().first;
            int dist = q2.front().second;
            q2.pop();

            time = dist;

            if (node->left != NULL && !visited[node->left->val]) {
                q2.push({node->left, dist+1});
                visited[node->left->val] = true;
            }
            if (node->right != NULL && !visited[node->right->val]) {
                q2.push({node->right, dist+1});
                visited[node->right->val] = true;
            }
            if (parents[node->val] != NULL && !visited[parents[node->val]->val]) {
                q2.push({parents[node->val], dist+1});
                visited[parents[node->val]->val] = true;
            }
        }

        return time;
    }
};