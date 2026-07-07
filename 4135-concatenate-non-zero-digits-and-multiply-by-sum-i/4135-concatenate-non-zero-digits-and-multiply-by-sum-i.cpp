class Solution {
public:
    long long sumAndMultiply(int n) {
        int start = 1;
        long long New_digit = 0;
        int sum = 0;
        for(int i = n ; n > 0 ; n = n / 10){
            int last_digit = n % 10;
            if(last_digit == 0){
                continue;
            }
            else{
                New_digit = start * last_digit + New_digit;
                sum += last_digit;
                start *=10;
            }
        }
        return New_digit * sum;
    }
};