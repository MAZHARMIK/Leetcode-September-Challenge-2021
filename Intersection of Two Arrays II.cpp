class Solution {
public:
    //time : O(nlogn)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0)
            return {};
        sort(nums1.begin(), nums1.end()); //nlogn
        sort(nums2.begin(), nums2.end()); //nlogn
        
        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return result;
    }
};
