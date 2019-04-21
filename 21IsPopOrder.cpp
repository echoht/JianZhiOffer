class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()){
            return false;
        }
        vector<int> sk; //辅助
        int ipush = 0;
        int ipop = 0;
        int isk = 0;
        for(ipop; ipop < popV.size(); ipop++){
            //check is in sk top 
            if(sk.size() > 0 && sk[sk.size()-1] == popV[ipop]){
                sk.pop_back();
                continue;
            }
            //read more data until met popV[ipop]
            while(ipush < pushV.size() && pushV[ipush] != popV[ipop]){
                sk.push_back(pushV[ipush++]);
            }
            if(ipush >= pushV.size()){
                return false;
            }
            if(pushV[ipush] == popV[ipop]){
                ipush++;
                continue;
            }
        }
        return true;
    }
};
