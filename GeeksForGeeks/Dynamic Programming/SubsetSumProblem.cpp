class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<bool> memory(sum+1), next(sum+1);
        
        memory[0] = true;
        next[0] = true;
        
        if (arr[0] <= sum) memory[arr[0]] = true;
        
        for (int i=1; i<arr.size(); i++) {
            for (int j=1; j<=sum; j++) {
                next[j] = memory[j] | (arr[i] > j ? false : memory[j-arr[i]]);
            }
            memory = next;
        }
        
        return next[sum];
    }
};