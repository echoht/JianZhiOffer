#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
//打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
//则打印出这三个数字能排成的最小数字为321323。

//solution1 permutation + sort
void swap(vector<int> &n, int i, int j){
	int tmp = n[i];
	n[i] = n[j];
	n[j] = tmp;
	return;
}

string getStrFromVec(vector<int> &n){
	stringstream p;
	for(int i = 0; i < n.size(); i++){
		p<<n[i]; 
	}
	return p.str();
}
void permutation(vector<int> &n, int idx, vector<string > &res){
	if(idx == n.size()-1){
		string p = getStrFromVec(n);
		res.push_back(p);
		return;
	}
	
	for(int i = idx; i < n.size(); i++){
		swap(n, idx, i);
		permutation(n, idx+1, res);
		swap(n, idx, i);
	}
	return;
}
bool sortfn(string a, string b){
	for(int i = 0; i < a.size(); i++){
		if(a[i]-b[i] < 0){
            return true;
		}
        if(a[i]-b[i] > 0){
            return false;
        }
	}
	return false;
}
string PrintMinNumber(vector<int> numbers) {
     vector<string> res;
	 permutation(numbers, 0, res);
	 //print info 
	 for(int i = 0; i < res.size(); i++){
		 std::cout<<res[i]<<" ";
	 }
	 std::cout<<std::endl;
	 //sort string vector
	 //sort(res.begin(), res.end(), sortfn);
	 sort(res.begin(), res.end());
	 //print info 
	 for(int i = 0; i < res.size(); i++){
		 std::cout<<res[i]<<" ";
	 }
	 std::cout<<std::endl;
	 return res[0];
}
//solution2  参考评论中做法，一旦数组按照某种规则排好序后，拼在一起的字符串将会是最小的
bool sortfn2(string a, string b){
    stringstream A, B;
    A<<a<<b;
    B<<b<<a;
    if(A.str() > B.str()){
        return false;
    }
    return true;
}
string PrintMinNumber2(vector<int> numbers) {
    vector<string> numStrs;
    for(int i = 0; i < numbers.size(); i++){
        stringstream p ;
        p << numbers[i];
        numStrs.push_back(p.str());
    }
    sort(numStrs.begin(), numStrs.end(), sortfn2);
    stringstream p;
    for(int i = 0; i < numStrs.size(); i++){
        std::cout<< numStrs[i] << std::endl;
        p << numStrs[i];
    }
    return p.str();
}	

    int main(){
       int a[] = {3,32,321};
	   vector<int> aa(&a[0], &a[3]);
	   std::cout<<PrintMinNumber2(aa);
    }
