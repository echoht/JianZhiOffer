class Solution {
public:
    
//需要注意inverseNum会超过int范围，需要设成long或者mod10000007
    //need to sort into a asc array
void merge(vector<int> &data, int left, int center, int right, long &inverseNum){
    //first cnt the inverseNum
    int i = left;
    int j = center+1;
    while(i<=center &&  j <= right){
        if(data[i] > data[j]){
            inverseNum += 1 + center-i;
            j++;
        }else{
            i++;
        }
    }
    //sort
    vector<int> tmp ;
    i = left;
    j = center+1;
    while(i <=center && j <= right){
        while(i<=center && data[i] <= data[j]){
            tmp.push_back(data[i]);
            i++;
        }
        while(j <= right && data[j] <= data[i]){
            tmp.push_back(data[j]);
            j++;
        }
    }
    while(i<=center){
        tmp.push_back(data[i++]);
    }
    
    while(j<=right){
        tmp.push_back(data[j++]);
    }
    //copy back
    for(int k = left; k<=right;k++){
        data[k] = tmp[k-left];
    }
    return;
}
void swap(vector<int> &data, int a, int b){
    int tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}
void msort(vector<int> &data, int left, int right, long &inverseNum){
    if(left >= right){
        return;
    }
    
    if(right - left == 1){
        if(data[left] > data[right]){
            swap(data, left, right);
            inverseNum ++;
        }
        return ;
    }
    
    int center = left + (right-left)/2;
    msort(data, left, center, inverseNum);
    msort(data, center+1, right, inverseNum);
    merge(data, left, center, right, inverseNum);
    return;
}
int InversePairs(vector<int> data) {
    if(data.size() <= 1){
        return 0;
    }
    long inverseNum = 0;
    msort(data, 0, data.size()-1, inverseNum);
    if(inverseNum < 1000000007){
        return inverseNum;
    }
    return inverseNum%1000000007;
}
};
