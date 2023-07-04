class Solution {
public:
    int clumsy(int n) {
        stack <int> s;
        int ans = 0;
        s.push(n);
        int count = 0;
        for (int i = n-1; i>0; i--){
            if (count %4 == 0){
                int temp = s.top();
                s.pop();
                s.push(temp*i);
            }else if (count%4 == 1){
                int temp = s.top();
                s.pop();
                s.push(temp/i);
            }else if (count%4 == 2){
                s.push(i);
            }else{
                s.push(i*-1);
            }
            count++;
        }
        while (!s.empty()){
            int temp = s.top();
            ans += temp;
            s.pop();
        }
        return ans;
    }
};
