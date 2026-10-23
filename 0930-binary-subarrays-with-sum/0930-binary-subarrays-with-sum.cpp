class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // vector<int> zeros(nums.size(), 0);
        // int cnt=0;
        // for (int i=n-1; i>=0; i--) {

        // }
        if (goal == 0) {
            int k = 0, count = 0;

            for (int x : nums) {
                if (x == 0) {
                    k++;
                    count += k;
                } else {
                    k = 0;
                }
            }

            return count;
        }
        
        int l=0, r=0, count=0, sum=0;
        while (r<n) {
            sum += nums[r];
            int zeros=0;
            if (sum==goal) {
                for (int i=r+1; i<n; i++) {
                    if (nums[i]==0) zeros++;
                    else break;
                }
            }
            while (sum==goal) {
                count++;
                count += zeros;
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return count;
    }
};