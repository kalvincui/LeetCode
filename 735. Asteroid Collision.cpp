class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> ast;
        for (int i = 0; i<asteroids.size(); i++){
            if (ast.empty()){
                ast.push(asteroids[i]);
            }else {
                int cur = asteroids[i];
                bool explode = false;
                while (!ast.empty() && (ast.top()>0 && cur<0)){
                    if (abs(ast.top()) < abs(cur)){
                        ast.pop();
                    }else if (abs(ast.top()) > abs(cur)){
                        ast.push(cur);
                        explode = true;
                        break;
                    }else {
                        explode = true;
                        break;
                    }
                }
                if (!explode){
                    ast.push(cur);
                }else {
                    ast.pop();
                }
            }
        }
        vector <int> ans;
        while (!ast.empty()){
            ans.push_back(ast.top());
            ast.pop();
        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};
