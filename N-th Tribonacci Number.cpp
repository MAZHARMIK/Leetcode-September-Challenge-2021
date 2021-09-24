class Solution {
public:
    int tribonacci(int n) {
        static int t[38];
        memset(t, -1, sizeof(t));
        
        if(t[n] != -1) return t[n];
        
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        
        for(int i = 0; i<=34; i++)
            t[i+3] = t[i] + t[i+1] + t[i+2];
        
        return t[n];
    }
};
