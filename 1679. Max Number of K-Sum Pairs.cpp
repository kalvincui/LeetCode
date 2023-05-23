class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort (nums.begin(), nums.end());
        int ans = 0;
        int lower = 0;
        int upper = nums.size() - 1;
        while (upper >= 0){
            if (nums[upper] > k){
                upper--;
            }else {
                break;
            }
        }
        while (lower < upper){
            if (nums[lower] > k){
                return ans;
            }
            if (nums[lower] + nums[upper] > k){
                upper--;
            }else if (nums[lower] + nums[upper] < k){
                lower++;
            }else if (nums[lower] + nums[upper] == k){
                //nums.erase(nums.begin() + upper);
                //nums.erase(nums.begin() + lower);
                //upper -=2;
                //lower = 0;
                lower++;
                upper--;
                ans++;
            }
        }
        return ans;
    }
};

//Alternative Solution 
class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
			if(m[k - nums[i]] > 0){
			   m[k - nums[i]]--;
				ans++;
			}
			else{
				m[nums[i]]++;
			}
		}
		return ans;
	}
};
