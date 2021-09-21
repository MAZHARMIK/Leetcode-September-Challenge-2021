//Approach-1 (Using Two pointer)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n    = nums.size();
        int l    = 0;
        int r    = 0;
        int maxL = 0;
        
        while(r < n) {
            if(nums[r] != 1) {
                maxL = max(maxL, r-l);
                l = r+1;
            }
            r++;
        }
        return max(maxL, r-l);
    }
};

//Approach-2 (Using Simple Counter)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxL = 0;
        int n = nums.size();
        int count = 0;
        
        for(const int&x : nums) {
            if(x == 1) count++;
            else {
                maxL = max(maxL, count);
                count = 0;
            }
        }
        return max(maxL, count);
    }
};
