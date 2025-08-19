class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long i=0, j=0;

        while (j<nums.size()) {
            if (nums[j] != 0) {
                count += (j-i)*(j-i+1)/2;
                i = j+1;
            }
            j++;
            // cout<<j<<" "<<i<<endl;
        }

        return count + (j-i)*(j-i+1)/2;
    }
};

//           i
//               j
// 1 3 0 0 2 0 0 4
// 0 1 2 3 4 5 6 7