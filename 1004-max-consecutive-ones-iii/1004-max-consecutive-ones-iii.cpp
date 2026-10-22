class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size(), nk=0, maxLength=0;
        while (r<n) {
            if (nums[r]==1) {
                maxLength = max(maxLength, r-l+1);
                r++;
            } else {
                if (nk<k) {
                    nk++;
                    maxLength = max(maxLength, r-l+1);
                    r++;
                } else {
                    while (nums[l]!=0) l++;
                    l++;
                    maxLength = max(maxLength, r-l+1);
                    r++;
                }
            }
        }
        return maxLength;
    }
};