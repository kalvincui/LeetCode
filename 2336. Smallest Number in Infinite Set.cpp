class SmallestInfiniteSet {
public:
    priority_queue <int, vector<int>, greater<int>> pq;
    set <int> check;
    SmallestInfiniteSet() {
        for (int i = 1; i<=1000; i++){
            pq.push(i);
            check.insert(i);
        }
    }
    
    int popSmallest() {
        int ans = pq.top();
        pq.pop();
        auto itr = check.find(ans);
        check.erase(itr);
        return ans;
    }
    
    void addBack(int num) {
        if (!check.count(num)){
            pq.push(num);
            check.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
