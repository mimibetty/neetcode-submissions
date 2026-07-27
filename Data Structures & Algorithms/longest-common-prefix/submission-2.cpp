class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int res = 0;
        int m = 200;
        for (string i : strs) {
            m = min(m, (int)i.size());
        }
        for (int i = 1; i <= m; i++) {
            bool ok = 1;
            for (string s : strs) {
                if (ok == 0) break;
                for (int j = 0; j < i; j++) {
                    if (s[j] != strs[0][j]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) res = i;
            else break;
        }
        string a;
        for (int i = 0; i < res; i++) a += strs[0][i];
        return a;
    }
};