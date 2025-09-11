class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char chr: s) {
            if (chr == 'a' || chr =='e' || chr == 'i' || chr == 'o' || chr == 'u' || chr == 'A' || chr =='E' || chr == 'I' || chr == 'O' || chr == 'U') {
                vowels.push_back(chr);
            }
        }

        sort(vowels.begin(), vowels.end());
        int index = 0;

        for (char &chr: s) {
            if (chr == 'a' || chr =='e' || chr == 'i' || chr == 'o' || chr == 'u' || chr == 'A' || chr =='E' || chr == 'I' || chr == 'O' || chr == 'U') {
                chr = vowels[index++];
            }
        }

        return s;
    }
};