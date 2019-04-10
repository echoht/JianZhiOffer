#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
class Solution {
public:
     int  NumberOf1(int n) {
		int mask = 1;
		int res = 0;
		if(n < 0){
			res = 1;
			n = n & INT_MAX;
		}
		while(n != 0){
			if((n&mask) == 1){
				res += 1;
			}
			n = n >> 1;
		}
		return res;
     }
};
