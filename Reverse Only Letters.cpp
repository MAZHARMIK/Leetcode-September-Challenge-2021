class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        
        while(i < j) {
            if(isalpha(s[i]) && isalpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if(!isalpha(s[j])) j--;
              
            else i++;
        }
        return s;
    }
};
