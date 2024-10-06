class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string shorter = sentence1.size() < sentence2.size() ? sentence1 : sentence2;
        string longer = sentence1.size() >= sentence2.size() ? sentence1 : sentence2;
        string word1, word2;

        int i=0, j=shorter.size()-1, k=longer.size()-1;

        while (i<=j) {
            int x = i;
            word1="", word2="";

            while (x < shorter.size() && shorter[x] != ' ') word1 += shorter[x++];
            x = i;
            while (x < longer.size() && longer[x] != ' ') word2 += longer[x++];

            if (word1 == word2) i = x+1;
            else break;
        }

        while (i<=j) {
            word1="", word2="";
            int x = j, y = k;
            
            while (x >= i && shorter[x] != ' ') word1 += shorter[x--];
            while (y >= i && longer[y] != ' ') word2 += longer[y--];

            if (word1 == word2) j = x-1, k = y-1;
            else break;
        }

        return j < i;
    }
};