#include"PlotnM.h"
#include"addfunc.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
int main(){
    plotMatrics<double> X(2,2,{1,2,3,4});
    std::vector<double> a{1,1};
    std::vector<double> b{1,1};
    std::vector<double> c{1,1,1,1};

    if ((po(a,b)+std::vector<double>{-1*sqrt(2)*-1,0})[0]<=0.0001){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if (X.stolbec(X,0,1)[0]==3){
        std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if ((X.R(X).m_r(X.R(X))+std::vector<double>{-sqrt(10),-14/sqrt(10),0,-2/sqrt(10)}*double(-1))[0]<=0.0001 and
        (X.R(X).m_r(X.R(X))+std::vector<double>{-sqrt(10),-14/sqrt(10),0,-2/sqrt(10)}*double(-1))[1]<=0.0001 and
        (X.R(X).m_r(X.R(X))+std::vector<double>{-sqrt(10),-14/sqrt(10),0,-2/sqrt(10)}*double(-1))[2]<=0.0001 and
        (X.R(X).m_r(X.R(X))+std::vector<double>{-sqrt(10),-14/sqrt(10),0,-2/sqrt(10)}*double(-1))[3]<=0.0001){
                std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        return 1;
    }
    if ((X.Q(X).m_r(X.Q(X))+std::vector<double>{-1/sqrt(10),-3/sqrt(10),-3/sqrt(10),1/sqrt(10)}*double(-1))[0]<=0.0001 and
        (X.Q(X).m_r(X.Q(X))+std::vector<double>{-1/sqrt(10),-3/sqrt(10),-3/sqrt(10),1/sqrt(10)}*double(-1))[1]<=0.0001 and
        (X.Q(X).m_r(X.Q(X))+std::vector<double>{-1/sqrt(10),-3/sqrt(10),-3/sqrt(10),1/sqrt(10)}*double(-1))[2]<=0.0001 and
        (X.Q(X).m_r(X.Q(X))+std::vector<double>{-1/sqrt(10),-3/sqrt(10),-3/sqrt(10),1/sqrt(10)}*double(-1))[3]<=0.0001){
            std::cout<<"Success"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
        for (int i=0;i<4;i++){
            std::cout<<X.Q(X).m_r(X.Q(X))[i]<<std::endl;
        }
        return 1;
    }
}
