class Solution {
public:
    int maximum69Number (int num) {
        vector<int> vec;
        while (num > 0) {
            vec.push_back(num%10);
            num /= 10;
        }

        bool flip = false;
        for (int i=vec.size()-1; i>=0; i--){
            if (!flip && vec[i] == 6) {
                vec[i] = 9;
                flip = true;
            }
            num = num * 10 + vec[i];
        }

        return num;
    }
};