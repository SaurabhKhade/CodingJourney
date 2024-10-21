class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        int m = image.size(), n = image[0].size();

        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            auto &front =q.front();
            q.pop();
            if (front.first > 0 && image[front.first-1][front.second] == initialColor) {
                image[front.first-1][front.second] = color;
                q.push({front.first-1, front.second});
            }
            if (front.second > 0 && image[front.first][front.second-1] == initialColor) {
                image[front.first][front.second-1] = color;
                q.push({front.first, front.second-1});
            }
            if (front.first < m-1 && image[front.first+1][front.second] == initialColor) {
                image[front.first+1][front.second] = color;
                q.push({front.first+1, front.second});
            }
            if (front.second < n-1 && image[front.first][front.second+1] == initialColor) {
                image[front.first][front.second+1] = color;
                q.push({front.first, front.second+1});
            }
        }

        return image;
    }
};