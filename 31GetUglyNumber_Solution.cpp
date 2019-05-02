class Solution {
public:
    int min(int a, int b, int c){
        int x = a<b? a:b;
        return x<c? x: c;
    }
    int GetUglyNumber_Solution(int index) {
        vector<int> arr;
        int p2=0, p3=0, p5=0;
        int tmp = 0;
        arr.push_back(1); // the first ugly num
        for(int i = 0; i < index; i++){
            tmp = min(arr[p2]*2, arr[p3]*3, arr[p5]*5);
            if(arr[p2]*2 == tmp) p2++;
            if(arr[p3]*3 == tmp) p3++;
            if(arr[p5]*5 == tmp) p5++;
            arr.push_back(tmp);
        }
        return arr[index-1];
    }
};
