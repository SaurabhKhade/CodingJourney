class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (const int &i: nums) {
            pq.push(i);
        }

        long long score = 0;
        while (k--) {
            if (pq.top() == 0) break;
            score += pq.top();
            pq.push(pq.top()/3 + (pq.top()%3 != 0));
            pq.pop();
        }

        return score;
    }
};
