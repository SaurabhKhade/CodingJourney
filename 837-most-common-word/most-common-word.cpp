class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& b) {
        unordered_map<string, bool> banned;
        
        for (string str: b) {
            toLower(str);
            banned[str] = true;
        }
        
        int i = 0, j = 0;
        int freq = 0;
        string mostFreq;
        unordered_map<string, int> freqs;
        
        
        while (j < paragraph.size()) {
            while (j < paragraph.size() && !isInvalid(paragraph[j])) j++;
            string str = paragraph.substr(i, j-i);
            // cout<<str<<" "<<j<<" "<<i<<endl;
            toLower(str);
            
            if (!banned[str]) {
                freqs[str]++;
                if (freqs[str] > freq) {
                    freq = freqs[str];
                    mostFreq = str;
                }
            }
            
            while (j < paragraph.size() && isInvalid(paragraph[j])) j++;
            i = j;
        }
        
        return mostFreq;
    }
    
    bool isInvalid(char chr) {
        return chr == ' ' || chr == '.' || chr == '!' || chr == '?' || chr == '\'' || chr == ',' || chr == ';';
    }
    
    void toLower(string &str) {
        for (char &chr: str) {
            if (chr >= 'A' && chr <= 'Z') {
                chr += 32;
            }
        }
    }
};