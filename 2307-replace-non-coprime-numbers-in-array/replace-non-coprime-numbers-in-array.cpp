class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        int gcdd;

        for (long i: nums) {
            while (!st.empty() && (gcdd = gcd(st.back(), i)) > 1) {
                i = i * st.back() / gcdd;
                st.pop_back();
            }

            st.push_back(i);
        }

        return st;
    }
};
