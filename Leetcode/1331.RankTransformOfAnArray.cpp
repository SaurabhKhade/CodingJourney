class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> vec(arr.size());

        for (int i=0; i<arr.size(); i++) {
            vec[i] = { arr[i], i };
        }

        sort(vec.begin(), vec.end());
        
        int rank = 0, last = INT_MIN;

        for (int i=0; i<arr.size(); i++) {
            if (vec[i].first != last) {
                rank++;
                last = vec[i].first;
            }
            arr[vec[i].second] = rank;
        }

        return arr;
    }
};