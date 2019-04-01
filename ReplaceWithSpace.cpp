class Solution {
public:
	void replaceSpace(char *str,int length) {
        int n = 0;
        for(int i = 0; i < length; ++i){
            if(str[i] == ' '){
                n++;
            }
        }
        char *rstr = new char[length+n*2];
        int j = 0;
        for(int i = 0; i < length; ++i){
            if(str[i] == ' '){
                rstr[j++] = '%';
                rstr[j++] = '2';
                rstr[j++] = '0';
            }else{
                rstr[j++] = str[i];
            }
        }
        strcpy(str, rstr);
	}
};
