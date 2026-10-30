class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), comp);

        int ans = 0;
        int last = INT_MIN;

        for (int i = 0; i < v.size(); i++) {
            if (v[i][0] >= last) {
                ans++;
                last = v[i][1];
            }
        }

        return v.size() - ans;
    }
};