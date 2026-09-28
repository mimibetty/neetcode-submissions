class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>d;
        set<int>s;
        for (auto i : hand) {
            s.insert(i);
            d[i]++;
        }

        for (auto i : s) {
            int hieu = d[i];
            for (int j = 0; j < groupSize; j++) {
                int val = j + i;
                d[val] -= hieu;
                if (d[val] < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

