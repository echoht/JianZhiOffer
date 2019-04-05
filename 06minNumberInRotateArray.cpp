class Solution {
public:
int minNumberImp(vector<int> &array, int left, int right){
    if(left > right){ //try not to be this situation
        return 0;
    }
    if(left == right){
        return array[left];
    }
    if(left == right - 1){
        return array[left] <= array[right] ? array[left]:array[right];
    }
    int mid = (left + right)/2;
    int A = array[left];
    int B = array[mid];
    int C = array[right];
    // A == B == C的时候并不知道最小值是在前一个区间还是后面一个区间
    if(A==B && B==C){
        return min(minNumberImp(array, left, mid), minNumberImp(array, mid, right));
    }
    if(A <= B ){
        return minNumberImp(array, mid, right);
    }
    return minNumberImp(array, left, mid);
}
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() <= 0){
        return 0;
    }
    return minNumberImp(rotateArray, 0, rotateArray.size()-1);
}
};
