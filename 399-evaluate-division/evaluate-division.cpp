typedef unordered_map<string, bool> umb;
typedef unordered_map<string, double> umd;
typedef unordered_map<string, umb> uumb;
typedef unordered_map<string, umd> uumd;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        uumb rechable;
        uumd evaluation;
        umb exists;
        set<string> set;

        for (int i=0; i<values.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            set.insert(a);
            set.insert(b);

            rechable[a][b] = rechable[b][a] = rechable[a][a] = rechable[b][b] = true;
            exists[a] = exists[b] = true;
            evaluation[a][b] = values[i];
            evaluation[b][a] = 1 / values[i];
            evaluation[a][a] = evaluation[b][b] = 1;
        }

        vector<string> variables(set.begin(), set.end());
        int n = set.size();

        for (int k=0; k<n; k++) {
            if (!exists[variables[k]]) continue;
            string varK = variables[k];
            for (int i=0; i<n; i++) {
                if (!exists[variables[i]]) continue;
                string varI = variables[i];
                for (int j=i+1; j<n; j++) {
                    if (!exists[variables[j]]) continue;
                    string varJ = variables[j];

                    if (!rechable[varI][varJ] && rechable[varI][varK] && rechable[varK][varJ]) {
                        rechable[varI][varJ] = rechable[varJ][varI] = true;
                        evaluation[varI][varJ] = evaluation[varI][varK] * evaluation[varK][varJ];
                        evaluation[varJ][varI] = 1 / evaluation[varI][varJ];
                    }
                }
            }
        }

        vector<double> result;
        for(auto &q: queries) {
            string a = q[0];
            string b = q[1];

            if (!exists[a] || !exists[b] || !rechable[a][b]) {
                result.push_back(-1);
            } else {
                result.push_back(evaluation[a][b]);
            }
        }

        return result;
    }
};