#pragma  GCC  optimize("O3,unroll-loops")
#pragma  GCC  target("avx2,bmi,bmi2,lzcnt,popcnt")

int speedup = []{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cout << std::unitbuf;
	return  0;
}();

class Solution {
    public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1,1}};

        vector<vector<int>> result = {{1}, {1,1}};

        for (int i=2; i<numRows; i++) {
            vector<int> row = {1};

            for (int j=1; j<result[i-1].size(); j++) {
                row.push_back(result[i-1][j] + result[i-1][j-1]);
            }

            row.push_back(1);
            result.push_back(row);
        }

        return result;
    }
};