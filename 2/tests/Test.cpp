#include"PlotnayaM.h"
#include"CSRMatrics.h"
#include"addfunctions.h"
#include <iostream>
#include <vector>
#include <map>
int main(){
    plotMatrics<int> X(2,2,{1,2,3,4});
    if (X(1,1) ==4){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }

    std::map<int,std::array<int,3>> m;
    m[0] = {0,3,1};
    CSRMatrics<int> Y(m,4,4);

    if ((Y.a_r(Y)==std::vector<int>{1})and(Y.nX_r(Y)==std::vector<int>{3})and(Y.NY_r(Y)==std::vector<int>{0,1,1,1,1})){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }

    std::vector<int> a{1,1};
    std::vector<int> b{1,1};
    std::vector<int> c{1,1,1,1};

    if (a+b==std::vector{2,2}){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (a*b==2){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (a*2==std::vector{2,2}){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (X*a==std::vector{3,7}){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (Y*c==std::vector{1,0,0,0}){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
}
