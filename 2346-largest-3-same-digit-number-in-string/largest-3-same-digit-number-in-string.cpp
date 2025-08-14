class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;
        string mxStr = "";

        for(int i=2; i<num.size(); i++) {
            if (num[i-2] == num[i-1] && num[i-1] == num[i]) {
                int n = (num[i-2]-'0')*100 + (num[i-1]-'0')*10 + (num[i]-'0');

                if (n > mx) {
                    mx = n;
                    mxStr = num.substr(i-2, 3);
                }
            }
        }

        return mxStr;
    }
};