#ifndef ADDFUNCTIONS_H_INCLUDED
#define ADDFUNCTIONS_H_INCLUDED

#include <vector>
#include"PlotnayaM.h"
#include"CSRMatrics.h"
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
std::vector<T> operator*(plotMatrics<T> a,std::vector<T> b){
    std::vector<T> r(a.ny_r(a),0);
    for (size_t i=0;i<a.ny_r(a);i++){
    T s=0;
        for (size_t g=0;g<a.nx_r(a);g++){
            s=s+a(i,g)*b[g];
        }
    r[i]=s;
    }
    return r;
}
template <typename T>
std::vector<T> operator*(CSRMatrics<T> a,std::vector<T> b){
    std::vector<T> r(a.ny_r(a),0);
    for (size_t i=0;i<a.ny_r(a).size();i++){
        for (size_t g=a.NY_r(a)[i]; g<a.NY_r(a)[i+1];g++){
            r[i]=r[i]+a.a_r(a)[g]*b[g];
        }
    }
    return r;
}

#endif // ADDFUNCTIONS_H_INCLUDED
