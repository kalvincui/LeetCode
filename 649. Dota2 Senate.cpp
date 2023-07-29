class Solution {
public:
    string predictPartyVictory(string senate) {
        //Input is a string containing R and D (representing the 2 parties)
        //Have 3 options:
        //If the person after you is part of the opposite party, ban their right to vote and all subsequent abilities to vote (remove the next)
        //If only your party remains in the string, you can announce victory (return the result)
        //If the person after you is part of the same party, you would do nothing (banning would be troll, and you cannot announce victory)
        //What can be done: push all the letters into the queue
        //Pop the current character from the queue. Check the next character in the queue, if it is the same, just push the current character
        //to the end of the queue
        //If the charcter is different, push into the end of the queue and pop the next element (skipping the turn)
        //Continue this while queue is not empty, can have 2 boolean variables to check to see if either party has won or not
        //Edit: you can ban anyone's right to vote
        //Always just ban the opposing parties right to vote
        queue <char> q;
        for (int i = 0; i<senate.size(); i++){
            q.push(senate[i]);
        }
        int rban = 0;
        int dban = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i<size; i++){
                char cur = q.front();
                q.pop();
                if (cur == 'R' && rban > 0){
                    rban--;
                    i++;
                }else if (cur == 'D' && dban > 0){
                    dban--;
                    i++;
                }else if (cur == 'R'){
                    q.push(cur);
                    dban++;
                }else if (cur == 'D'){
                    q.push(cur);
                    rban++;
                }
            }
            if (size == q.size()){
                break;
            }
        }
        if (q.front() == 'R'){
            return "Radiant";
        }else {
            return "Dire";
        }
    }
};
