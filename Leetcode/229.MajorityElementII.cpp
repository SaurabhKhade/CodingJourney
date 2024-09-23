class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, ele1 = INT_MIN, cnt2 = 0, ele2 = INT_MIN;
        
        for (auto &i: nums) {
            if (cnt1 == 0 && i != ele2) {
                cnt1++;
                ele1 = i;
            } else if (cnt2 == 0 && i != ele1) {
                cnt2++;
                ele2 = i;
            } else if (ele1 == i) {
                cnt1++;
            } else if (ele2 == i) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (auto &i: nums) {
            if (i == ele1) cnt1++;
            if (i == ele2) cnt2++;
        }

        vector<int> result;
        if (cnt1 > nums.size()/3) result.push_back(ele1);
        if (cnt2 > nums.size()/3) result.push_back(ele2);
        return result;
    }
};