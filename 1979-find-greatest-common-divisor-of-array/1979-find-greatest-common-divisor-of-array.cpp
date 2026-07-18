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
        int min_ = *min_element(nums.begin(),nums.end());  
        int max_ = *max_element(nums.begin(),nums.end());  
        return find_gcd(min_,max_);
    }
};