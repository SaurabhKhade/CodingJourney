class Solution {
    public:
    int largest(vector<int> &arr) {
        int largest = INT_MIN;
        for (auto &i:arr) {
            largest = largest > i ? largest : i;
        }
        
        return largest;
    }
};