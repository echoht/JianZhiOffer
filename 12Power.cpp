#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution {
public:
	//快速幂做法
    double Power(double base, int exponent) {
		if(exponent == 0){
			return 1;
		}
		//负指数幂
		int flg = 0;
		if(exponent < 0){
			flg = 1;
			exponent = -exponent;
		}
		//快速幂算法
		double res = 1;
		while(exponent != 0){
			if(exponent & 1 == 1){
				res *= base;
			}
			base *= base;
			exponent = exponent >> 1;
		}
		if(flg == 1){
			return 1/res;
		}
		return res;
    }
	double PowerImp(double base, int exp){ //exp is always > 0
		//base situation 
		if(exp == 1){
			return base;
		}
		double res;
		res = PowerImp(base, exp/2);
		if(exp % 2 == 0){
			return res*res;
		}
		return res*res*base;
	}
	// 二分做法
	double Power2(double base, int exponent) {
		if(exponent == 0){
			return 1;
		}
		//负指数幂
		int flg = 0;
		if(exponent < 0){
			flg = 1;
			exponent = -exponent;
		}
		double res = PowerImp(base, exponent);
		if(flg == 1){
			return 1/res;
		}
		return res;
    }
};
