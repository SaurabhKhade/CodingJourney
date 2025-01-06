class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> cnts(n);
        
        int balls = 0, moves = 0;
        for (int i=0; i<n; i++) {
            balls += boxes[i] == '1';
            cnts[i] = moves;
            moves += balls;
        }
        
        balls = moves = 0;
        for (int i=n-1; i>=0; i--) {
            balls += boxes[i] == '1';
            cnts[i] += moves;
            moves += balls;
        }

        return cnts;
    }
};