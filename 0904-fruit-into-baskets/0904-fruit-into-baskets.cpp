class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = fruits[0];
        int second=-1;
        int firstIndex=0;
        int secondIndex=-1;
        int n = fruits.size();
        for (int i=1; i<n; i++) {
            if (fruits[i]!=first) {
                second = fruits[i];
                secondIndex = i;
                break;
            }
            firstIndex=i;
        }
        if (second==-1) return n;
        int l=0, r=secondIndex;
        int maxLength = 0;
        while (r<n) {
            if (fruits[r]==first) {
                firstIndex=r;
                maxLength = max(maxLength, r-l+1);
                r++;
            } else if (fruits[r]==second) {
                secondIndex=r;
                maxLength = max(maxLength, r-l+1);
                r++;
            } else {
                if (firstIndex<secondIndex) {
                    l = firstIndex+1;
                    first = fruits[r];
                    firstIndex = r;
                } else {
                    l = secondIndex+1;
                    second = fruits[r];
                    secondIndex = r;
                }
                maxLength = max(maxLength, r-l+1);
                r++;
            }
        }
        return maxLength;
    }
};