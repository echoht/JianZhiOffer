class Solution {
public:
    bool FindImp(int target, vector< vector<int> >& array, 
                int left_y, int left_x, int right_y, int right_x) {
        //base situation
        if(left_y > right_y || left_x > right_x){
            return false;
        }
        if(left_y == right_y && left_x == right_x){
            if(array[left_y][left_x] == target){
                return true;
            }else{
                return false;
            }
        }
        //sub task and recursive here
        int mid_y, mid_x;
        mid_y = (left_y + right_y)/2;
        mid_x = (left_x + right_x)/2;
        if(array[mid_y][mid_x] == target){
            return true;
        }
        if(array[mid_y][mid_x] > target){
            return FindImp(target, array, left_y, left_x, mid_y, mid_x);
        }
        else{
            //right up : (left_y, mid_x+1), (mid_y, right_x)
            //right down :(mid_y+1, mid_x+1),(right_y, right_x)
            //left down: (mid_y+1, left_x), (right_y, mid_x)
            
            return FindImp(target, array, left_y, mid_x+1, mid_y, right_x) || 
                FindImp(target, array, mid_y+1, mid_x+1, right_y, right_x) ||
                FindImp(target, array, mid_y+1, left_x, right_y, mid_x);
        }
    }
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() <= 0){
            return false;
        }
        return FindImp(target, array, 0, 0, array.size()-1, array[0].size()-1);
    }
};
