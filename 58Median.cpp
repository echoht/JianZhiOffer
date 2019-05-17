#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
class solution{
    public:
    solution(){
		  sz = 0;
    }
    priority_queue<int, vector<int>, greater<int> > minp;
	  priority_queue<int> maxp;
	  int sz ;
    void Insert(int num)
    {
		//最小堆的所有值要大于最大堆
		//奇数时放到minq
		sz++;
		if(sz & 1 == 1){
			if(!maxp.empty() && maxp.top() > num ){
				maxp.push(num);
				num = maxp.top();
				maxp.pop();
			}
			minp.push(num);
		}else{
			
			if(!minp.empty() && minp.top() < num ){
				minp.push(num);
				num = minp.top();
				minp.pop();
			}
			maxp.push(num);
		}
    }

    double GetMedian()
    { 
		if(sz & 1 == 1){
			return minp.top();
		}
		return (minp.top() + maxp.top())/2.0;
    }
};

int main(){
    solution s;
    s.Insert(1);
    s.Insert(2);
    s.Insert(3);
    s.Insert(4);

    std::cout<<s.GetMedian();
}
