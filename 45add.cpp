#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
int add(int a, int b) {
	if(b == 0){
		return a;
	}
	int sum = a^b; // a b 各bit上直接想加 不考虑进位
	int carry = (a&b)<<1;
	return add(sum, carry); //这里递归是因为 a&b 之后可能还有进位
}
