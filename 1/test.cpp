#include "Matrics3d.h"
#include <iostream>
#include <vector>
int main(){
    three_diagonaled_Matrix<float> M({0,1,1},{2,2,2},{1,1,0});
    std::vector<float>d = {3,4,3};
    if (M.A(M)== std::vector<float>{0,1,1}){
            std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (M.B(M)==std::vector<float>{2,2,2}){
            std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }if (M.C(M)==std::vector<float>{1,1,0}){
            std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (M.size_(M)==M.B(M).size()){
            std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (abs(M.solve(M,d)[0]-1)<0.0001 and abs(M.solve(M,d)[1]-1)<0.0001 and abs(M.solve(M,d)[2]-1)<0.0001){
            std::cout<<"Success"<<std::endl;
            return 0;
    }
    else{
        std::cout<<"Fail "<<M.solve(M,d)[2]<<std::endl;
        return 1;
    }
}
