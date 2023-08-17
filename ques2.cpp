class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> mp;

        for(int i = 0; i< nums.size(); i++){
            if(mp.count(nums[i]) == 0){
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]] += 1;
            }
        }


        int count = 0;
        for(int i = 0; i< nums.size(); i++){
            if(mp[nums[i]] > 0){
                int val = k - nums[i];
                if(val == nums[i]){
                    if(mp[val]> 1){
                        count += 1;
                        mp[val] -= 2;
                    }
                }
                else if(mp[val] > 0 ){
                    count += 1;
                    mp[nums[i]] -=1;
                    mp[val] -= 1;
                }

            }
        }

        return count;
        
    }
};
