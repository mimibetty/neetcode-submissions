class Solution {
public:
    int sumSquare(int n) {
        int sum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x*x;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        map<int,int>isExist;
        while (n > 1) {
            if (isExist[n]) {
                return false;
            }
            isExist[n] = 1;
            n = sumSquare(n);
       }
        return true; 
    }
};
