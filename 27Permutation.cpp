class Solution {
public:
    	char char_cnt[255] = {0};
	
	vector<char> sortStr(string str){
		vector<char> res;
		//TODO
		for(int i = 0; i < str.size(); i++){
			char_cnt[str[i]] += 1;
		}
		for(char i = 'A'; i <='Z'; i++){
			for(int j =0 ; j < char_cnt[i]; j++)
				res.push_back(i);
		}
		for(char i = 'a'; i <='z'; i++){
			for(int j =0 ; j < char_cnt[i]; j++)
				res.push_back(i);
		}
		return res;
	}
	
	//check is c can be append into r 
	bool check(char c, string r){
		//todo
		int c_cnt = 0;
		for(int i = 0; i < r.size(); i++){
			if(r[i] == c){
				c_cnt++;
			}
		}
		if(c_cnt >= char_cnt[c]){
			return false;
		}
		return true;
	}
	
	vector<string> PerImp(vector<char>& sChars, vector<string> &last){
		if(last.size() >0 && last[0].size() == sChars.size()){
			return last;
		}
		
		vector<string> newRes;
		for(auto r : last){
			for(auto c: sChars){
				if(check(c, r)){
					newRes.push_back(r + c);
				}
			}	
		}
		return PerImp(sChars, newRes);
	}
    vector<string> Permutation(string str) {
        //sort str to get sorted char list 
		vector<char> sChars = sortStr(str);
		vector<string> res;
		if(str.size() <= 0){
			return res;
		}
        for(auto c: sChars){
            string s;
            s.push_back(c);
            res.push_back(s);
        }

		res = PerImp(sChars, res);
		//uniq 
        vector<string> finalr;
        for(int i = 0; i < res.size(); i++){
            int flg = 0;
            for(int j = 0; j < finalr.size(); j++){
                if(finalr[j].compare(res[i]) == 0){
                    flg = 1;
                    break;
                }
            }
            if (flg == 0)
                finalr.push_back(res[i]);
        }
		return finalr;
    }
};
