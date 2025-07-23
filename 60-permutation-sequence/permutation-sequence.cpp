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

        // for(int i=0; i<n; i++) {
        //     cout<<vec[i]<<" "<<factorials[i]<<endl;
        // }

        string result = "";
        while (vec.size() > 0 && k > 0) {
            int elems = vec.size()-1;
            int factorial = factorials[elems-1];

            int sets = k/factorial;
            int isComplete = k%factorial == 0;
            
            cout<<sets<<" "<<factorial<<" "<<k<<endl;
            k -= (sets)*factorial;
            cout<<sets<<" "<<factorial<<" "<<k<<endl;
            result += ('0'+vec[sets-isComplete]);
            vec.erase(vec.begin() + sets-isComplete);
        }

        // for (int i=0; i<vec.size(); i++) {
        //     result += (vec[i] + '0');
        // }
        for (int i=vec.size()-1; i>=0; i--) {
            result += (vec[i] + '0');
        }

        return result;
    }
};

// 1 1 3
// 2 1 4
// 3 1 5
// 4 2 6
// 5 2 7
// 6 2 8

