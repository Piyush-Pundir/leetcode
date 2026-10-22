class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);

        int l = 0, r = 0, maxLength = 0;
        int n = s.size();

        while (r<n) {

            if (hash[s[r]]!=-1) {
                if (hash[s[r]]>=l) { // the duplicate is within the range
                    l = hash[s[r]]+1;
                } 
            }

            maxLength = max(maxLength, r - l + 1);
            hash[s[r]]=r;
            r++;
            
        }

        return maxLength;
    }
};