class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        int gcdd;

        for (long i: nums) {
            while (!st.empty() && (gcdd = gcd(st.top(), i)) > 1) {
                i = i * st.top() / gcdd;
                st.pop();
            }

            st.push(i);
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// 2009 899 20677 825

