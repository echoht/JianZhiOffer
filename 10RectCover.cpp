#include <iostream>
#include
#define INT_MIN -2^31
#define INT_MAX 2^31
using namespace std;
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
// fibonacci
class Solution {
public:
    int rectCover(int number) {
		if(number <= 0){
			return 0;
		}
		if(number == 1){
			return 1;
		}
		if(number == 2){
			return 2;
		}
		int first = 1; 
		int second = 2;
		int n = 3;
		while(n <= number){
			int tmp = first+second;
			first = second;
			second = tmp;
			n++;
		}
		return second;
    }
};
