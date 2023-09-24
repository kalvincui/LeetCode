//TLE
class StockSpanner {
public:
    public: stack<int> s;
    StockSpanner() {
        while (!s.empty()){
            s.pop();
        }
    }
    
    int next(int price) {
        stack <int> cpy = s;
        int res = 1;
        while (!cpy.empty()){
            if (price >= cpy.top()){
                res++;
                cpy.pop();
            }else {
                break;
            }
        }
        s.push(price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
public:
    public : stack <pair<int, int>> s;
    StockSpanner() {
        while (!s.empty()){
            s.pop();
        }
    }
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price){
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
