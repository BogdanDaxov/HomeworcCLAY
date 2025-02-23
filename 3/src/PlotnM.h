#ifndef PLOTNM_H_INCLUDED
#define PLOTNM_H_INCLUDED

#include <iostream>
#include "addfunc.h"
#include <vector>
template <typename T>
class plotMatrics{
private:
    size_t nx_;
    size_t ny_;
    std::vector<T> m_;
public:
    size_t nx_r (plotMatrics M){
 return M.nx_;
 }
 size_t ny_r (plotMatrics M){
 return M.ny_;
 }
 std::vector<T> m_r(plotMatrics M){
 return M.m_;
 }
    plotMatrics(size_t nx_1,size_t ny_1,std::vector<T> m_1):nx_(nx_1),ny_(ny_1),m_(m_1){}
    T operator()(size_t i, size_t j) const {
        return m_[i * ny_ + j];
    }
std::vector<T> stolbec(plotMatrics A, size_t i, size_t k){//нумерация с нуля т.е. i от 0 до n-1
    std::vector<T> x={};
    for (size_t j = k;j<A.ny_r(A);j++){
        x.push_back(A(j,i));
    }
    return x;
}
std::vector<T> stroca(plotMatrics A, size_t i,size_t k){//нумерация с нуля т.е. i от 0 до n-1
    std::vector<T> x={};
    for (size_t j = k;j<A.nx_r(A);j++){
        x.push_back(A(i,j));
    }
    return x;
}
plotMatrics R(plotMatrics A){
    plotMatrics<T> R(A.nx_r(A),A.ny_r(A),A.m_r(A));
    for (size_t i=0;i<A.nx_r(A)-1;i++){
        std::vector<T> b=R.stolbec(R,i,i);
        for (size_t j=i;j<A.nx_r(A);j++){
            std::vector<T> c=po(b,R.stolbec(R,j,i));
            for (size_t g=i; g<A.ny_r(A);g++){
                R.m_[g*R.ny_r(R)+j]=c[g-i];
                //std::cout<<R.m_r(R)[g,j]<<std::endl;
            }
        }
    }
    return R;
}
plotMatrics Q(plotMatrics A){
    plotMatrics<T> M(A.nx_r(A),A.ny_r(A),A.m_r(A));
    plotMatrics<T> Q(A.nx_r(A),A.ny_r(A),std::vector<T>(A.m_r(A).size()));
    for (size_t i=0;i<A.nx_r(A);i++){
        Q.m_[i*A.nx_r(A)+i]=1;
    }
    for (size_t i=0;i<A.nx_r(A)-1;i++){
        std::vector<T> b=M.stolbec(M,i,i);
        for (size_t j=0;j<A.nx_r(A);j++){
            std::vector<T> q=po(b,Q.stroca(Q,j,i));
            std::vector<T> m=po(b,M.stolbec(M,j,i));
            for (size_t g = i; g<A.ny_r(A);g++){
                M.m_[g*A.ny_r(A)+j]=m[g-i];
                Q.m_[j*A.ny_r(A)+g]=q[g-i];
            }
        }
    }
    return Q;
}
};

#endif // PLOTNM_H_INCLUDED
