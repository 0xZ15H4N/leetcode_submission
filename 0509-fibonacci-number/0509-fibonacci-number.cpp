class Solution {
vector<int>arr;
public:
    int solve(int n ){
        if(n <= 1){
            return n;
        }
        if(arr[n] != -1){
            return arr[n];
        }
        return arr[n] = solve(n-1) + solve(n-2);
    }
    int fib(int n) {
        arr.resize(n+1,-1);
        return solve(n);
    }
};