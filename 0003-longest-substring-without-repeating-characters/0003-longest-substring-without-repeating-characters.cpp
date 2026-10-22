class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        else if (s.size()==1) return 1;
        int hash[256] =  {0};
        int l=0;
        int r=0;
        int n=s.size();
        int maxLength=0;
        while (r<n) {
            if (hash[s[r]]==0) {
                hash[s[r]]=1;
                maxLength = max(r-l+1, maxLength);
                r++;
            } else {
                while (s[l]!=s[r]) {
                    hash[s[l]]=0;
                    l++;
                }
                l++;
                maxLength = max(r-l+1, maxLength);
                r++;
            }
        }
        return maxLength;
    }
};