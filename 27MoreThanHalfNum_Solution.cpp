
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次
//，超过数组长度的一半，因此输出2。如果不存在则输出0。
class Solution {
public:
	//空间复杂度O(n) 不是最优
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> uniq_num_cnt;
		for(int i = 0; i < numbers.size(); i++){
			if (uniq_num_cnt.find(numbers[i]) == uniq_num_cnt.end()){
				uniq_num_cnt[numbers[i]] =0;
			}
			uniq_num_cnt[numbers[i]] ++;
		}
		int half = numbers.size()/2;
		for(auto item: uniq_num_cnt){
			if(item.second > half){
				return item.first;
			}
		}
		return 0;
    }
	//参考讨论区代码和思想
	//若存在一个数 出现次数是大于数组大小一半，则该数出现的次数大于所有其它数的次数
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if(numbers.size() <= 0) return 0;
		int time = 1;
		int result = numbers[0];
		for(int i = 1; i < numbers.size(); i ++){
			if(time == 0){
				result = numbers[i];
				time = 1;
			}else if(numbers[i] == result){
				time++;
			}else{
				time--;
			}
		}
		time = 0;
		//在便利确定是否result的次数大于1/2 * numbers.size()
		for(int i = 0; i < numbers.size(); i++){
			if(numbers[i] == result)
				time++;
		}
		if(time>numbers.size()/2)
			return result;
		return 0;
		
	}
};
