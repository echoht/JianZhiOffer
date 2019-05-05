#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;
//一个整型数组里除了两个数字之外，其他的数字都出现了两次。
//请写程序找出这两个只出现一次的数字。
//参考的讨论区做法，应用异或特性，同为0，异为1
//   因此所有数据异或后的结果是num1和num2的异或结果，
//	 再通过异或结果中（从末尾往前）第一个bit位为1作为判断依据，将数组分成两对，一对是该bit位为1，一对是该bit位为0；

//检查第idx位的bit值是否是1
bool isBit(int data, int idx){
	while(idx > 0){
		data = data>>1;
		idx--;
	}
	return data&1;
}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
	if(data.size() < 2){
		return ;
	}
	int xor_res = data[0];
	for(int i = 1; i < data.size(); i++){
		xor_res = xor_res^data[i];
	}
	if(xor_res == 0){ //no num1 and num2
		return;
	}
	//find the first 1 bit
	int idx = 0;
		//这里注意优先级
	while((xor_res&1) == 0){
		idx++;
		xor_res = xor_res >> 1;
	}
	*num1 = 0;
	*num2 = 0;
	for(int i = 0; i < data.size(); i++){
		if(isBit(data[i], idx)){
			*num1 ^= data[i];
		}else{
			*num2 ^= data[i];
		}
	}
	return;
}
int main(){
    int a[] = {2,4,3,6,3,2,5,5};
    int num1, num2;
    vector<int> A(&a[0], &a[8]);

    FindNumsAppearOnce(A, &num1, &num2);
    std::cout<<num1<< " " << num2;
}
