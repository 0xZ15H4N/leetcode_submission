class Solution {
private:
    int find_gcd(int min_,int max_){
        if(max_ == 0){
            return min_;
        }
        return find_gcd(max_ , min_ % max_);
    }
public:
    int findGCD(vector<int>& nums) {
        return find_gcd( *min_element(nums.begin(),nums.end()),*max_element(nums.begin(),nums.end()));
    }
};