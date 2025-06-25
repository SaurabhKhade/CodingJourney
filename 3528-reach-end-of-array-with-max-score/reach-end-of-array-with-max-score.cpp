class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        int i = 0, curr = nums[0];
        long long score = 0;

        for (int j=1; j<n; j++) {
            if (nums[j] > nums[i]) {
                score += (long long)(j-i)* nums[i];
                i = j;
            }
        }

        return score + (long long)(n-i-1)* nums[i];
        
        // vector<long long> maxScores(n, 0);

        // maxScores[0] = 0;

        // for (long long i = 0; i<n-1; i++) {
        //     for (long long j = i+1; j<n; j++) {
        //         // cout<<i<<" "<<j<<" "<<nums[i]<<" "<<nums[j]<<" "<<maxScores[j]<<endl;
        //         long long newScore = maxScores[i] + (j-i)*nums[i];
        //         maxScores[j] = newScore > maxScores[j] ? newScore : maxScores[j];;
        //         // cout<<maxScores[j]<<endl;
        //     }
        // }

        // return maxScores[n-1];
    }
};

// 1 1 2 3
// - 1 4 7
// - - 4 7
//    |
// 0  1  2  3  4 
// 4  4  8  12 16




