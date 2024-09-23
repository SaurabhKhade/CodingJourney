class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = binary_search(matrix, target);
        return binary_search(matrix[row], target);
    }

    int binary_search(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size()-1, mid;
        int row = 0;
        while (l <= h) {
            mid = (l+h)/2;
            if (matrix[mid][0] == target) return mid;
            else if (matrix[mid][0] > target) h = mid-1;
            else {
                row = max(row, mid);
                l = mid+1;
            }
        }

        return row;
    }

    bool binary_search(vector<int> &row, int target) {
        int l = 0, h = row.size()-1, mid;
        while (l <= h) {
            mid = (l+h)/2;
            if (row[mid] == target) return true;
            else if (row[mid] > target) h = mid-1;
            else l = mid+1;
        }

        return false;
    }
};