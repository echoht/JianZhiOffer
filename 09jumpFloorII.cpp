#include <iostream>
#include
#define INT_MIN -2^31
#define INT_MAX 2^31
using namespace std;
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//f[n] = f[n-1] + ...+ f[1] + 1
class Solution {
public:
    int jumpFloorII(int number) {
		vector<int> res;
		res.push_back(1);
		int n = 2;
		while(n<=number){
			int tmp = 0;
			for(int i = 0; i < res.size(); ++i){
				tmp += res[i];
			}
			res.push_back(tmp+1);
			n++;
		}
		return res[res.size()-1];
    }
};
