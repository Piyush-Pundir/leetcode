class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return true;
        int cnt = 1;
        for (int i=n-2; i>=0; i--) {
            if (nums[i]>=cnt) {
                cnt=1;
            } else {
                cnt++;
                if (i==0) return false;
            }
        }
        return true;
    }
};