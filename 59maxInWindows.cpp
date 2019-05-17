class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
         int wsi=-1, wei=-1, wmi=-1;
		vector<int> res;
		if(size <= 0 || num.size() <= 0 || size > num.size()){
			return res;
		}
		//first window ? 
		wsi = 0;
		wmi = 0;
		wei = size-1;
		if(0 == size-1){
            res.push_back(num[wmi]);
        }
		for(int i = 1; i < num.size(); i++){
			if(i < size ){
				if(num[i] >= num[wmi]){
					wmi = i;
				}
				if(i == size-1){
					res.push_back(num[wmi]);
				}
			}else{
				wsi++;
				wei++;
				if(wmi < wsi) { // last window's max value has out of the current window 
					if(num[wei] >= num[wmi]){
						wmi = wei;
						res.push_back(num[wmi]);
					}else{ // travel current window to get the largest num
						wmi = wsi;
						for(int j = wsi+1; j <= wei; j++){
							if(num[j] >= num[wmi]){
								wmi = j;
							}
						}
						res.push_back(num[wmi]);
					}
				}else{
					if(num[wei] >= num[wmi]){
						wmi = wei;
						res.push_back(num[wmi]);
					}else{
						res.push_back(num[wmi]);
					}
				}
			}
		}
		if(num.size() < size){
			res.push_back(num[wmi]);
		}
		return res;
    }
};
