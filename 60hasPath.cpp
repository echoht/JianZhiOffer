#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
    bool hasPathImp(char* matrix, int rows, int cols, char* str, int str_sz, 
		int cr, int cc, vector< vector<int> > isVisited, int str_idx){
        std::cout << "row:" << cr << ", col:"<< cc << ", str_idx:" << str_idx <<std::endl;
		int ncr = cr, ncc = cc-1;
		if(str_idx == str_sz-1){
			return true;
		}
		//left
        std::cout << ncr << ", " << ncc << std::endl;
		if (ncc >= 0 && isVisited[ncr][ncc] == 0 && matrix[ncr*cols+ncc] == str[str_idx+1]){
			isVisited[ncr][ncc] = 1;
			bool ret = hasPathImp(matrix, rows, cols, str, str_sz, ncr, ncc, isVisited, str_idx+1);
			if(ret == false){
				isVisited[ncr][ncc] = 0;
			}else{
				return true;
			}
		}
		//down
		ncr = cr + 1, ncc = cc;
        std::cout << ncr << ", " << ncc << "isVisited:"  << std::endl;
		if (ncr < rows && isVisited[ncr][ncc] == 0 && matrix[ncr*cols+ncc] == str[str_idx+1]){
			isVisited[ncr][ncc] = 1;
			bool ret = hasPathImp(matrix, rows, cols, str, str_sz, ncr, ncc, isVisited, str_idx+1);
			if(ret == false){
				isVisited[ncr][ncc] = 0;
			}else{
				return true;
			}
		}
		
		//right
		ncr = cr , ncc = cc + 1;
        std::cout << ncr << ", " << ncc << std::endl;
		if (ncc < cols && isVisited[ncr][ncc] == 0 && matrix[ncr*cols+ncc] == str[str_idx+1]){
			isVisited[ncr][ncc] = 1;
			bool ret = hasPathImp(matrix, rows, cols, str, str_sz, ncr, ncc, isVisited, str_idx+1);
			if(ret == false){
				isVisited[ncr][ncc] = 0;
			}else{
				return true;
			}
		}
		//up
		ncr = cr-1 , ncc = cc ;
        std::cout << ncr << ", " << ncc << std::endl;
		if (ncr >= 0 && isVisited[ncr][ncc] == 0 && matrix[ncr*cols+ncc] == str[str_idx+1]){
			isVisited[ncr][ncc] = 1;
			bool ret = hasPathImp(matrix, rows, cols, str, str_sz, ncr, ncc, isVisited, str_idx+1);
			if(ret == false){
				isVisited[ncr][ncc] = 0;
			}else{
				return true;
			}
		}
		return false;
	}
	
	bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		int str_sz = 0; // str sz 
		while(str[str_sz] != '\0'){
			str_sz++;
		}
		if(str_sz <= 0 || rows<=0 || cols<=0){
			return false;
		}

		for(int i = 0; i < rows; i ++){
			for(int j = 0; j < cols; j ++){
				if(matrix[i*cols + j] == str[0]){
					//isVisited 
					vector< vector<int> > isVisited;
					for(int k =0 ; k <rows; k++){
						vector<int> c(cols);
						isVisited.push_back(c);
					}
                    std::cout << "start:" << i << ", end:"<< j <<"str_sz:"<< str_sz << std::endl;
                    isVisited[i][j] = 1;
                    bool res = hasPathImp(matrix, rows, cols, str, str_sz, i, j, isVisited, 0);
					if(res){
						return true;
					}
				}
			}
		}
		return false;
    }
	
int main(){
    char *x = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";//[] = {'a', 'b', 'c', 's', 'f', 'c', 'a', 'd', 'e'};
    char *str = "SGGFIECVAASABCEHJIGQEMS";
    std::cout <<hasPath(x, 5, 8, str) << ",";
}
