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

        vector<int> zeros(n, 0);
        int cnt=0;
        for (int i=n-1; i>=0; i--) {
            zeros[i]=cnt;
            if (nums[i]==0) cnt++;
            else cnt=0;
        }

        int l=0, r=0, count=0, sum=0;
        while (r<n) {
            sum += nums[r];
            while (sum==goal) {
                count++;
                count += zeros[r];
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return count;
    }
};