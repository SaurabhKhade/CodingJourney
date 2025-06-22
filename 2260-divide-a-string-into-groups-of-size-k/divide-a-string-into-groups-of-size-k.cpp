class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i=0;
        vector<string> vec;

        while (i<s.size()) {
            string word = s.substr(i, k);

            if (word.size() < k) {
                word += string(k-word.size(), fill);
            }
            vec.push_back(word);
            i += k;
        }

        return vec;
    }
};