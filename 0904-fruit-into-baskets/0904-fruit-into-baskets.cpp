class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;
        int right=0;
        while (right<fruits.size()) {
            freq[fruits[right]]++;

            if (freq.size() > 2) {
                freq[fruits[left]]--;

                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};
