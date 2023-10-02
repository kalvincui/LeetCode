//TLE
class Solution {
public:
    bool winnerOfGame(string colors) {
        //First thought: Use a queue
        queue <char> q;
        bool alice = false;
        bool bob = false;
        int a = 0; 
        int b = 0;
        for (int i = 0; i<colors.size(); i++){
            q.push(colors[i]);
        }
        while (!q.empty()){
            alice = false;
            bob = false;
            a = 0;
            b = 0;
            int size = q.size();
            for (int i = 0; i<size; i++){
                if (alice && q.front() == 'A'){
                    b = 0;
                }
                if (bob && q.front() == 'B'){
                    a = 0;
                }
                if (!alice && q.front() == 'A'){
                    q.pop();
                    b = 0;
                    a++;
                    if (a == 3){
                        alice = true;
                    }else {
                        q.push('A');
                    }
                }else if (!bob && q.front() == 'B'){
                    q.pop();
                    a = 0;
                    b++;
                    if (b == 3){
                        bob = true;
                    }else {
                        q.push('B');
                    }
                }else {
                    q.push(q.front());
                    q.pop();
                }
            }
            if (alice == false){
                return false;
            }
            if (alice == true && bob == false){
                return true;
            }
            if (q.size() == size){
                break;
            }
        }
        return false;
    }
};
