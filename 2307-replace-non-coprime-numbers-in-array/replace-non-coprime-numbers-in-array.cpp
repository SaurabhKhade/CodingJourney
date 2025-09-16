class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        int gcdd;

        for (int i: nums) {
            while (!st.empty() && (gcdd = gcd(st.back(), i)) > 1) {
                i = i / gcdd * st.back();
                st.pop_back();
            }

            st.push_back(i);
        }

        return st;
    }
};
