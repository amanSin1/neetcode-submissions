class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int n = nums.size();
        if(n == 0)return 0;
        int prev = nums[0];
        int maxi = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == prev)continue;
            if(nums[i] == prev+1){
                cnt++;
                prev = nums[i];
            }
            else{
                maxi = max(cnt,maxi);
                cnt = 1;
                prev = nums[i];
            }
        }
        return max(maxi, cnt);
    }
};
