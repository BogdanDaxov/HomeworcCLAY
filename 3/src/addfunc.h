#ifndef ADDFUNC_H_INCLUDED
#define ADDFUNC_H_INCLUDED

#include <cmath>
#include <vector>
#include"PlotnM.h"
template <typename T>
std::vector<T> operator+(std::vector<T> a,std::vector<T> b){
    std::vector<T> c = {};
    for (size_t i=0;i<a.size();i++){
        c.push_back(a[i]+b[i]);
    }
    return c;
}
template <typename T>
T operator*(std::vector<T> a,std::vector<T> b){
    T r=0;
    for (size_t i=0;i<a.size();i++){
        r=r+a[i]*b[i];
    }
    return r;
}
template <typename T>
std::vector<T> operator*(std::vector<T> a,T b){
    std::vector<T> r={};
    for (size_t i=0;i<a.size();i++){
        r.push_back(b*a[i]);
    }
    return r;
}

template <typename T>
std::vector<T> po(std::vector<T> xv,std::vector<T> x){
    std::vector <T> e1={1};
    for (size_t i = 0; i<xv.size()-1;i++){
        e1.push_back(0);
    }
    std::vector <T> v = xv + e1*sqrt(xv*xv);
    return (x+v*(-2*((v*x)/(v*v))));
}

#endif // ADDFUNC_H_INCLUDED
