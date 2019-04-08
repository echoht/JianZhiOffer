#include <iostream>
#define INT_MIN -2^31
#define INT_MAX 2^31
using namespace std;
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
//fibonacci
class Solution {
public:
    int jumpFloor(int number) {
        int first = 1; //n=0
		int second = 1; //n=1
		if(number == 0){
			return 0;
		}
		if(number == 1){
			return 1;
		}
		int n = 2;
		while(n<=number){
			int tmp = first + second;
			first = second;
			second = tmp;
			n++;
		}
		return second;
    }
};
