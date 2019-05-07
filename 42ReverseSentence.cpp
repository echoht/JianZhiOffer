#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
//student. a am I  
//I am a student. 
// YX = (X^Y^)^
void swap(string &str, int i, int j){
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
	return;
}
string ReverseSentence(string str) {
    // swap each word in str
	int first=0, second=0;
	int sz = str.size();
	while(first < sz){
		while(second < sz && str[second] != ' '){
			second++;
		}
		for(int i = first, j = second-1; i<j; i++, j--){
			swap(str, i,j);
		}
		while(second<sz && str[second] == ' '){
			second++;
		}
		first = second;
	}
	for(int i = 0, j = sz -1; i < j ; i++, j--){
		swap(str, i, j);
	}
	return str;
}
int main(){
    int n = 3;
    std::cout<<ReverseSentence("student. a am I");
}
