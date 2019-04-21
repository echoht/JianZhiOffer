class Solution {
public:
    //后续遍历则最后一个val是root的val
    //二叉查找树left < root < right
    bool VerifySquenceOfBSTImp(vector<int> &seq, int left, int right){
        if(left == right || left > right) {
            return true;
        }
        int root_val = seq[right];
        int left_last = left;
        while(seq[left_last] < root_val && left_last < right){
            left_last++;
        }
        // from left_last to right-1, must larger then root_val 
        for(int i = left_last; i < right; i++){
            if(seq[i] < root_val){
                return false;
            }
        }
        return VerifySquenceOfBSTImp(seq, left, left_last-1) && 
            VerifySquenceOfBSTImp(seq, left_last, right-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() <= 0){
            return false;
        }
        return VerifySquenceOfBSTImp(sequence, 0 , sequence.size()-1);
    }
};
