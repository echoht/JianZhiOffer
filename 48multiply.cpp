#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
// 构建乘积数组
//一个前向 一个后向 
vector<int> multiply(const vector<int>& A) {
    vector<int> res;
    if(A.size() <= 0){
        return res;
    }
    res.push_back(1);
    for(int i = 1; i < A.size(); i++){
        res.push_back(res[i-1]*A[i-1]);
    }
    int tmp = 1;
    for(int i = A.size()-1; i >= 0; i--){
        res[i] = res[i]*tmp;
        tmp *= A[i];
    } 
    return res;   
}
int main(){
    int n = 4;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(&a[0], &a[9]);
    std::cout<<maxSubArray2(nums)<<std::endl;
}
