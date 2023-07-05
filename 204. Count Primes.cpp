class Solution {
public:
    int countPrimes(int n) {
        //Sieve of Eratosthenes
        if (n < 2){
            return 0;
        }
        vector <bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i<n; i++){
            if (isPrime[i]){
                for (int j = i+i; j<n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        int prime = 0;
        for (int i = 0; i<isPrime.size(); i++){
            if (isPrime[i]){
                prime++;
            }
        }
        return prime;
    }
};
