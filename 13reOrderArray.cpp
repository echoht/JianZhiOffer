#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
	//类似冒泡排序，in place swap
    void reOrderArray(vector<int> &array) {
		int idx = 0;
		int endIdx = 0;
        while(idx < array.size()){
			// find first odd idx 
			if(array[idx] % 2 == 0){
				idx++;
				continue;
			}
			//swap with evan num which before idx 
			int j = idx-1;
			int i = idx;
			while(j >= endIdx){
				if(array[j] % 2 == 1){
					endIdx = i;
					break;
				}
				//swap 
				int tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				i--;
				j--;
			}
			idx++;
		}
    }
};
