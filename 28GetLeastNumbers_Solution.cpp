#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;

//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

//方法一 类似于快排思想 分而治之 也叫选择算法
int partition(vector<int> &input, int start, int end){
	if(start >= end){
		return start;
	}
	int povit=input[start];
    int idx = start;
	start += 1;
	while(start < end){
		while(start < end && input[start] <= povit){
			start++;
		}
		while(start < end && input[end] > povit){
			end--;
		}
		int tmp = input[start];
		input[start] = input[end];
		input[end] = tmp;
	}
	if(input[start] < povit){
        input[idx] = input[start];
        input[start] = povit;
    }
    return start;
}
void solution1(vector<int> &input, int k, int left, int right, vector<int> &res){
	if(k == 0){
		return;
	}	
	int pidx = partition(input, left, right);
	//left part size is pidx-left 
	int left_part_sz = pidx-left;
	int right_part_sz = right-pidx;
	if(left_part_sz < k){
		for(int i = left; i < pidx; i++){
			res.push_back(input[i]);
		}
		solution1(input, k-left_part_sz, pidx, right, res);
	}else if(left_part_sz > k){
		solution1(input, k, left, pidx-1, res);
	}else {
		for(int i = left; i < pidx; i++){
			res.push_back(input[i]);
		}
	}
	return;
}
//adapt heap at top 
void heapAdapt(vector<int> &input, int k){
    int cur = 0;
    int son = 2*cur+1;
    while(true){
        int tmp = input[cur];
        if(son >= k){
            break;
        }
        if((son < k && input[cur] >= input[son]) && ((son+1 < k && input[cur] >= input[son+1])||son+1>=k) ){
            break;
        }
        if(son+1 < k && input[son] < input[son+1] ){
            input[cur] = input[son+1];
            cur = son+1;
        }else{
            input[cur] = input[son];
            cur = son;
        }
        son = 2*cur + 1;
        input[cur] = tmp;
    }
    //print info 
    for(int i = 0; i < k; i++){
        std::cout<< input[i] << ",";
    }
    std::cout<<std::endl;
    return;
}

//init into a max-heap 
void heapInit(vector<int> &input, int k){
    int son = 0;
    for(int i = (k-2)/2; i >= 0; i--){
        int cur = i;
        int son = 2*i+1;
        while(true){
            int tmp = input[cur];
            if(son >= k){
                break;
            }
            if((son < k && input[cur] >= input[son]) && ((son+1 < k && input[cur] >= input[son+1])||son+1>=k) ){
                break;
            }
            if(son+1 < k && input[son] < input[son+1] ){
                input[cur] = input[son+1];
                cur = son+1;
            }else{
                input[cur] = input[son];
                cur = son;
            }
            son = 2*cur + 1;
            input[cur] = tmp;
        }
    }
    //print info
    for(int i = 0; i < k; i++){
        std::cout<< input[i] << ",";
    }
    std::cout<<std::endl;
    return;
}

// based on max-heap, top k of input used as heap 
vector<int> solution2(vector<int> &input, int k){
    vector<int> res;
    if(k > input.size() || k <= 0){
        return res;
    }
    if(k == input.size()){
        return input;
    }
    //input[0] is always the largest one in the first input[0 ~ k-1]
    heapInit(input, k);

    for(int i = k; i < input.size(); i++){
        if(input[i] < input[0]){
            int tmp = input[0];
            input[0] = input[i];
            input[i] = tmp;
            heapAdapt(input, k);
        }
    }
    for(int i = 0; i < k; i++){
        res.push_back(input[i]);
    }
    return res;
}

 vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if(k == input.size()){
		return input;
	}
	vector<int> res ; // result   
	if(k > input.size()){
        return res;
    }	
	solution1(input, k, 0, input.size()-1, res);
	return res;
}


int main(){
    //int a[] = {1,2,3,4,5};
    int a[] = {4,5,1,6,2,7,3,8};
    vector<int> aa(&a[0], &a[8]);
    vector<int> res = solution2(aa, 4);
    for(int i = 0; i < 4; i++){
        std::cout<<res[i] << std::endl;
    }
}
