class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        for(auto it : mp){
            int el = it.first;
            int freq = it.second;
            vec.push_back({freq,el});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        int cnt = 0;
        for(int i = vec.size()-1; i>=0; i--){
            if(cnt == k){
                break;
            }
            cnt++;
            int el = vec[i].second;
            ans.push_back(el);
            
        }
        return ans;
    }
};
