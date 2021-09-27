class Solution {
public:
    string filter(string &s) {
        string str = "";
        int n = s.length();
        for(int i = 0; i<n; i++) {
            if(s[i] == '.') continue;
            if(s[i] == '+' || s[i] == '@') break;
            str.push_back(s[i]);
        }
        return str;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;

        for(string &email : emails) {
            string domain = email.substr(email.find('@'));
            email = filter(email);
            st.insert(email+domain);
        }
        
        return (int)st.size();
    }
};
