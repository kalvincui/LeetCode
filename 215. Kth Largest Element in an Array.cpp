class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Make a priority queue, add all elements in nums into the queue
        //Pop from the queue k times
        //Return q.top()
        priority_queue <int, vector<int>, less<int>> pq;
        for (auto i : nums){
            pq.push(i);
        }
        for (int i = 1; i<k; i++){
            pq.pop();
        }
        return pq.top();
    }
};
