class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxFreq = 0;
        int result = 0;
        int right = 0;

        while (right < s.size()) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            while (right - left + 1 - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};