class Solution {
public:
    int count_hour(int x, const vector<int>& piles) {
        int num = 0;
        for (auto i : piles) {
            num += (i/x);
            if (i%x != 0) num++;
        }
        return num;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2;
            cout <<l << ' ' << r << ' ' << mid << ' ' << count_hour(mid, piles)<< endl;
            if (count_hour(mid, piles) <= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
