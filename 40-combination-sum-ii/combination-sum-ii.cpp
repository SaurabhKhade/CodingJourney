class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        helper(candidates, target, 0, {}, result);
        return result;
    }

    void helper(vector<int>& candidates, int target, int ind, vector<int> combination, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(combination);
        }
        if (target <= 0) return;

        for (int i=ind; i<candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i-1]) continue;
            if (target < candidates[i]) return;
            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i+1, combination, result);
            combination.pop_back();
        }
    }
};

// 1 1 2 5 6 7 10
// 1 1 6