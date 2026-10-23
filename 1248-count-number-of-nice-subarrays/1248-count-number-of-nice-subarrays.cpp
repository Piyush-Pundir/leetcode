class Solution {
public:
    int func(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, cnt = 0, odd = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 != 0)
                odd++;

            while (odd > k) {
                if (nums[l] % 2 != 0)
                    odd--;
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);
    }
};