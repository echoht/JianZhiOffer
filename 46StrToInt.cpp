#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
//但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0。
// 浮点数是合法数字吗？
// 溢出情况 需要返回0
int StrToInt(string str) {
    int flg = 0; // flg == 0 is positive 
	int idx = 0;
	if(str[idx] == '+'){
		idx++;
	}else if(str[idx] == '-'){
		idx++;
		flg = 1;
	}
	long res = 0; //直接设置成long 变成不会溢出？？
	while(idx < str.size()){
		if(str[idx] >= '0' && str[idx] <= '9'){
			//判断是否溢出
			
			res *= 10 ;
			res += (str[idx]-'0');
			if(flg == 0 && res >= 2147483648){
                return 0;
            }
            else if(res > 2147483648) {
				return 0;
			}
			
			idx++;
		}else if(str[idx] == '.'){
			break;
		}else{
			return 0;
		}
	}
	if(flg == 1){
		return (-1)*res;
	}
	return res; 
}

int main(){
    std::cout<<StrToInt("-2147483648") << std::endl;
    std::cout<<StrToInt("+123ab567") << std::endl;
}
