class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int first = 0;
        int second = 1;
        int i=2;
        while(i <= n){
            int tmp = first + second;
            first = second;
            second = tmp;
            i++;
        }
        return second;
    }
};
