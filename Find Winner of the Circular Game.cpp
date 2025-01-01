class Solution {
public:
    int findAnswer(int n, int k) {
            if(n == 1) return 0;
            return (findAnswer(n-1, k) + k) % n;
        }
    int findTheWinner(int n, int k) {
        
        //0 base to 1 base
        return findAnswer(n,k) + 1;
    }
};

//iterative approach
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;
        for(int i = 2; i<= n; i++){
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};
