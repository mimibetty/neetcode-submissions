class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        map<vector<int>, int> isExist;

        sort(nums.begin(), nums.end());

        map<long long, int> d;
        for (auto x : nums) d[x]++;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    d[nums[i]]--;
                    d[nums[j]]--;
                    d[nums[k]]--;

                    long long final_number =
                        1LL * target - nums[i] - nums[j] - nums[k];

                    if (d.count(final_number) && d[final_number] > 0) {
                        vector<int> tmp{
                            nums[i],
                            nums[j],
                            nums[k],
                            static_cast<int>(final_number)
                        };

                        sort(tmp.begin(), tmp.end());

                        if (isExist[tmp] == 0) {
                            res.push_back(tmp);
                            isExist[tmp]++;
                        }
                    }

                    d[nums[i]]++;
                    d[nums[j]]++;
                    d[nums[k]]++;
                }
            }
        }

        return res;
    }
};