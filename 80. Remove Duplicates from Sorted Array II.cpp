class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Nums is already sorted
        //Each unique element appears at most twice
        //Cannot have another array or datastructure, must be done in place
        //Idea: int that keeps track of array index, initially set to 0
        //index only gets incremented when a new element gets detected
        //have a int that keeps track of the current element
        //can do this in O(n) time using a for loop and while loop together
        int k = 0;
        int i = 0;
        while (i<nums.size()){
            int cur = nums[i];
            int count = 0;
            while (i<nums.size() && cur == nums[i]){
                nums[k] = cur;
                nums[k+(count%2)] = cur;
                i++;
                count++;
            }
            if (count >= 2){
                k+=2;
            }else {
                k+=1;
            }
        }
        return k;
    }
};
