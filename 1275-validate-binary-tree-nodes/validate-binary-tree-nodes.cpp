class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n);

        for(int i=0; i<n; i++) {
            int lc = leftChild[i];
            int rc = rightChild[i];
            if (lc != -1) {
                parents[lc]++;
            }
            if (rc != -1) {-
                parents[rc]++;
            }
        }

        int node = -1;
        for (int i=0; i<n; i++) {
            if (parents[i] == 0) {
                node = i;
                break;
            }
        }

        if (node == -1) return false;

        vector<bool> visited(n);
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int lc = leftChild[node];
            int rc = rightChild[node];


            if (lc != -1) {
                if (visited[lc]) return false;
                visited[lc] = true;
                q.push(lc);
            }
            if (rc != -1) {
                if (visited[rc]) return false;
                visited[rc] = true;
                q.push(rc);
            }
        }

        for (int n: visited) {
            if (!n) return false;
        }

        return true;
    }
};


