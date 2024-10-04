class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemistry = 0;
        int teamSkill = accumulate(skill.begin(), skill.end(), 0) * 2 / skill.size();

        unordered_map<int, int> map;
        for (const int &i:skill) map[i]++;

        for (const auto &[key,value]: map) {
            if (value != map[teamSkill - key]) {
                return -1;
            }
            chemistry += static_cast<long>(value) * key * (teamSkill - key);
        }

        return chemistry/2;
    }
};
