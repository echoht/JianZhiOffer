#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<math.h>
using namespace std;
//小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
//但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
//没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
//现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
// echo 枚举可能的情况
vector<vector<int> > FindContinuousSequence(int sum) {
    int n = 0;
	double tmp = 0;
	vector<vector<int> > res;
	for(int i = 1; i < sum; i++){
		tmp = (sqrt((2*i-1)*(2*i-1) + 8*sum) + 1-2*i ) / 2;
		if(tmp < 2){
            continue;
        }
        n = int(tmp);
		if(tmp - n == 0){
            //std::cout << i << " : " << n << " : " <<tmp<< std::endl;	
			vector<int> a ;
			for(int x = i; x < i+n; x++){
                a.push_back(x);
			}
			res.push_back(a);
		}
	}
	return res;
}
//参考讨论区做法
vector<vector<int> > FindContinuousSequence2(int sum) {
	int plow = 1, phigh = 2;
	int cur = plow+phigh;
	vector<vector<int> > res;
	while(phigh > plow){
		if(cur < sum){
			phigh ++;
			cur += phigh;
		}
		else if(cur == sum){
			vector<int> a ;
			for(int i = plow; i <= phigh; i++){
				a.push_back(i);
			}
			res.push_back(a);
			cur -= plow;
			plow ++;
		}else{
			cur -= plow;
			plow ++;
		}
	}
	return res;
}

int main(){
    int n = 3;
    vector<vector<int> > a;
    a = FindContinuousSequence2(100);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            std::cout<<a[i][j] << ",";
        }
        std::cout<<std::endl;
    }
}
