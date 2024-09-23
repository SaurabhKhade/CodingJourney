class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ele = 0;
        for (int &i : nums) {
            if (cnt == 0) {
                cnt++;
                ele = i;
            } else if (ele == i) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ele;
    }
};