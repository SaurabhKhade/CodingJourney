class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> vec;
        for (char chr='a'; chr<=target[0]; chr++) {
            vec.push_back(string(1,chr));
        }

        for (int i=1; i<target.size(); i++) {
            string back = vec.back();
            for (char j='a'; j<=target[i]; j++) {
                vec.push_back(back+j);
            }
        }

        return vec;
    }
};