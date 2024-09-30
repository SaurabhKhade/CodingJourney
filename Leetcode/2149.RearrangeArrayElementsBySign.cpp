class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0, j=1, n=nums.size();
        vector<int> res(n);
        for (auto &el:nums){
            if (el>0) {
                res[i] = el;
                i+=2;
            }
            else {
                res[j] = el;
                j+=2;
            }
        }

        return res;
    }
};