class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        
        char ch = keysPressed[0];
        int max = releaseTimes[0];
        
        int i = 1;
        while(i < n) {
            int diff = releaseTimes[i] - releaseTimes[i-1];
            if(diff == max && keysPressed[i] > ch) {
                ch = keysPressed[i];
            } else if(diff > max) {
                max = diff;
                ch = keysPressed[i];
            }
            i++;
        }
        
        return ch;
    }
};
