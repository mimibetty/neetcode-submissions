class Solution {
public:
    int count1(int n) {
        int res = 0;
        while (n > 0) {
            res += n%2;
            n /= 2;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(count1(i));
        }
        return res;
    }
};
