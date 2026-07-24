class Solution {
public:

    int fib(int n) {

        if (n <= 1)
            return n;

        int fib0 = 0;
        int fib1 = 1;

        for (int i = 2; i <= n; i++) {

            int sum = fib0 + fib1;

            fib0 = fib1;
            fib1 = sum;
        }

        return fib1;
    }
};