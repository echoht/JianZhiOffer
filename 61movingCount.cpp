#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
	bool isOkPos( int the, int r, int c){
		int res = 0;
		while(r > 0){
			res += r % 10;
			r = r/10;
		}
		
		while(c > 0){
			res += c % 10;
			c = c/10;
		}
        //std::cout << "r:" << r << ", c:" << c << ", res:" << res << std::endl;
        return res <= the;
	}
    // not a real dfs 
    // 看起来是求相连的最大区域
    int movingCountImp2(int the, int rows, int cols, vector< vector<int> > &isVisited, int r, int c){
        if(r >= 0 && r < rows && c >= 0 && c < cols && isVisited[r][c] == 0 && isOkPos(the, r, c)){
            isVisited[r][c] = 1;
            return 1 + movingCountImp2(the, rows, cols, isVisited, r+1, c) 
                + movingCountImp2(the, rows, cols, isVisited, r-1, c)
                + movingCountImp2(the, rows, cols, isVisited, r, c+1)
                + movingCountImp2(the, rows, cols, isVisited, r, c-1);
                
        }
        return 0;
    }    
	int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows < 1 || cols < 1){
            return 0;
        }
        //isVisited 
		vector< vector<int> > isVisited;
		for(int k =0 ; k <rows; k++){
			vector<int> c(cols);
			isVisited.push_back(c);
		}
		return movingCountImp2(threshold, rows, cols, isVisited, 0, 0);
    }
    
int main(){
    for(int th = 0; th <= 10; th ++){
        for(int i = 1; i <= 1; i ++){
            for(int j = 1; j <= 100; j++){
                movingCount(th, i , j);
                std::cout << th << "," << i << "," << j << " mc1: " << movingCount(th, i , j)  << std::endl;
            }
        }
    }
}
