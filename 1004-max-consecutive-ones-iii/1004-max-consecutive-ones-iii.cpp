class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size(), zeros=0, maxLength=0;
        while (r<n) {
            if (nums[r]==0) zeros++;
            if (zeros>k) {
                while (nums[l]!=0) {
                    l++;
                }
                l++;
                zeros=k;
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};

