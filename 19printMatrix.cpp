class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
         vector<int> res;
        int n = matrix.size();
        if(n <= 0){
            return res;
        }
        int m = matrix[0].size();
        int lower = m > n ? n : m;
        for(int i = 0; i < lower/2 ; i++){
            int x, y;
            //left to right
            x = i;
            for(y = i; y < m-i; ++y ){
                //std::cout<<matrix[x][y] << std::endl;
                res.push_back(matrix[x][y]);
            }
            //up to down
            y = m-i-1;
            for(x = i+1; x < n-i; x++){
                
                //std::cout<<matrix[x][y] << std::endl;
                res.push_back(matrix[x][y]);
            }
            //left to right
            x = n-i-1;
            for(y = m-i-2; y >= i; y--){
                
                //std::cout<<matrix[x][y] << std::endl;
                res.push_back(matrix[x][y]);
            }
            //down to up
            y = i;
            for(x = n-i-2; x > i; x--){
                
                //std::cout<<matrix[x][y] << std::endl;
                res.push_back(matrix[x][y]);
            }
        }
        if(lower%2 == 1){
            int x, y ;
            if(m > n){
                x = lower/2;
                for(y = x; y < m-x; y++){
                    
                    //std::cout<<matrix[x][y] << std::endl;
                    res.push_back(matrix[x][y]);
                }
            }else{
                y = lower/2;
                for(x = y; x < n-y; x++){
                    
                    //std::cout<<matrix[x][y] << std::endl;
                    res.push_back(matrix[x][y]);
                }
            }
        }
        return res;
    }
};
