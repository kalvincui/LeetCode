class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        int32_t holder = 0;
        for (int i = 0; i<=n; i++){
            int32_t temp = holder;
            int ones = 0;
            while (temp != 0){
                if (temp&1 == 1){
                    ones++;
                }
                temp = temp >>1;
            }
            ans.push_back(ones);
            holder++;
        }
        return ans;
    }
};



//Alternative Solution that is Faster (simplifying while loop)
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        int32_t holder = 0;
        for (int i = 0; i<=n; i++){
            int32_t temp = holder;
            int ones = 0;
            while (temp != 0){
                temp = temp&(temp-1);
                ones++;
            }
            ans.push_back(ones);
            holder++;
        }
        return ans;
    }
};


//Alternative Solution that doesn't require int32_t holder
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
		
		// iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0
            int sum = 0;
            int num = i;
			// while num not equals zero
            while(num != 0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                sum += num%2;
                num = num/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
		// return 
        return ans;
    }
};
