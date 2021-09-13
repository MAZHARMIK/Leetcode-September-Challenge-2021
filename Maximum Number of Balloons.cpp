class Solution {
public:
    int maxNumberOfBalloons(string text) { 
        int t[26] = {0};
        for(const char& ch : text) {
            t[ch-'a']++;
        }
        
        int count = INT_MAX;
        count = min(count, t['b'-'a']);
        count = min(count, t['a'-'a']);
        count = min(count, t['l'-'a']/2);
        count = min(count, t['o'-'a']/2);
        count = min(count, t['n'-'a']);
        
        return count;
    }
};
