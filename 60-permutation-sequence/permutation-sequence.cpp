class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";

        vector<int> vec(n);
        for (int i=1; i<=n; i++) {
            vec[i-1] = i;
        }

        vector<int> factorials(n, 1);
        for (int i=2; i<=n; i++) {
            factorials[i-1] = i * factorials[i-2];
        }

        string result = "";
        while (vec.size() > 0 && k > 0) {
            int elems = vec.size()-1;
            int factorial = factorials[elems-1];

            int sets = k/factorial;
            int isComplete = k%factorial == 0;
            
            k -= (sets)*factorial;
            result += ('0'+vec[sets-isComplete]);
            vec.erase(vec.begin() + sets-isComplete);
        }

        for (int i=vec.size()-1; i>=0; i--) {
            result += (vec[i] + '0');
        }

        return result;
    }
};
