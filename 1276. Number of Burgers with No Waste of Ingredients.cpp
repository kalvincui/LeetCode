//TLE
class Solution {
public:
    vector <int> res;
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        allComb (tomatoSlices, cheeseSlices, 0, 0);
        return res;
    }
    void allComb (int tomato, int cheese, int jumbo, int small){
        if (tomato == 0 && cheese == 0){
            if (res.empty()){
                res.push_back(jumbo);
                res.push_back(small);
            }
            return;
        }else if (tomato <=0 || cheese <= 0){
            return;
        }
        allComb (tomato-4, cheese-1, jumbo+1, small);
        allComb (tomato-2, cheese-1, jumbo, small+1);
    }
};

//Very slow but passes
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int jumbo = 0;
        int small = 0;
        while (tomatoSlices > 2*cheeseSlices && cheeseSlices > 0){
            jumbo++;
            tomatoSlices -=4;
            cheeseSlices -=1;
        }
        if (tomatoSlices == 2*cheeseSlices){
            small += tomatoSlices /2;
            return {jumbo, small};
        }
        return {};
    }
};


//Linear Equation
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 == 0 && cheeseSlices * 2 <= tomatoSlices && tomatoSlices <= cheeseSlices * 4)
            return {tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
        return {};
    }
};
