#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
//汇编语言中有一种移位指令叫做循环左移（ROL），
//现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
string LeftRotateString(string str, int n) {
    int sz = str.size();
    if(sz <= 1 || n <= 0 ){
        return str;
    }
	n = n % sz;
	stringstream res;
	for(int i = n; i < n+sz; i++){
		if(i < sz )
			res << str[i];
		else
			res << str[i%sz];
	}
	return res.str();
}
//参考讨论区，这题的考点是字符串的翻转问题  YX=(X^Y^)^
string LeftRotateString2(string str, int n) {
	if(str.size() <= 1 || n <= 0){
		return str;
	}
	n = n%str.size();
	//trans X 
	for(int i = 0, j = n-1; i<j; i++,j-- ){
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	//trans Y
	for(int i = n, j = str.size()-1; i<j; i++,j-- ){
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	//trans all
	for(int i = 0, j = str.size()-1; i<j; i++,j-- ){
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	return str;
}
int main(){
    int n = 3;
    std::cout<<LeftRotateString2("abcdefg", 1);
}
