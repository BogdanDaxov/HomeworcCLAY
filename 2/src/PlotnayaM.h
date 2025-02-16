#ifndef PLOTNAYAM_H_INCLUDED
#define PLOTNAYAM_H_INCLUDED

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
};


#endif // PLOTNAYAM_H_INCLUDED
