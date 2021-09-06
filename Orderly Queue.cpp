class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string ans = s;
            for(int i = 1; i<s.length(); i++) {
                string temp = s.substr(i) + s.substr(0, i);
                ans = min(ans, temp);
            }
            return ans;
        } else {
            sort(begin(s), end(s));
        }
        return s;
    }
};
