class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for(auto &str : strs) {
            s += to_string(str.size());
            s += '#';
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while(i < s.size()) {

            // Find '#'
            int j = i;

            while(s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract string
            string str = s.substr(j, len);

            ans.push_back(str);

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};