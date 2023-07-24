class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //Input Sorted Unqieu Integer Array
        //Smallest Sorted List of Ranges that Cover all the numbers in the array exactly
        //Each range has to include all the numbers 
        //Idea:
        //Two pointers maybe?, one for the start and one for the end
        //Nested while loops, outer while loop for the left pointer, inner while loop for the right pointer
        //Next number in array has to be = current number + 1, if not add to the range
        //Can probably do this in a for loop
        vector <string> ans;
        if (nums.size() == 0){
            return ans;
        }
        int dist = 0;
        long low = nums[0];
        for (int i = 0; i<nums.size(); i++){
            cout <<low + dist << " " << nums[i] << '\n';
            if (low + dist == nums[i]){
                dist++;
            }else {
                if (dist == 1){
                    ans.push_back(to_string(low));
                }else {
                    ans.push_back(to_string(low) + "->" + to_string(low+dist-1));
                }
                low = nums[i];
                dist = 1;
            }
        }
        if (low == nums[nums.size()-1]){
            ans.push_back(to_string(low));
        }else if (dist != 1){
            ans.push_back(to_string(low) + "->" + to_string(low+dist-1));
        }
        return ans;
    }
};
