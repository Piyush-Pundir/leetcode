class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int l = 0, r = 0;
        int maxFreq = 0, maxLen = 0;
        int n = s.size();

        while (r < n) {
            hash[s[r] - 'A']++;

            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;

                maxFreq = 0;
                int i = 0;

                while (i < 26) {
                    maxFreq = max(maxFreq, hash[i]);
                    i++;
                }
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};