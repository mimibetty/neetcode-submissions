class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> a;
        for (int i = 1; i <= 2; i++) {
            for (auto j : nums) {
                a.push_back(j);
            }
        }
        return a;
    }
};