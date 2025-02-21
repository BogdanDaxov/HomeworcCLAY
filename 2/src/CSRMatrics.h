#ifndef CSRMATRICS_H_INCLUDED
#define CSRMATRICS_H_INCLUDED

#include <map>
#include <vector>
template <typename T>
class CSRMatrics{
private:
    size_t nx_;
    size_t ny_;
    std::vector<T> a_;
    std::vector<T> nX_;
    std::vector<T> NY_;
public:
    size_t nx_r (CSRMatrics M){
 return M.nx_;
 }
 size_t ny_r (CSRMatrics M){
 return M.ny_;
 }
 std::vector<T> a_r(CSRMatrics M){
 return M.a_;
 }
  std::vector<T> nX_r(CSRMatrics M){
 return M.nX_;
 }
  std::vector<T> NY_r(CSRMatrics M){
 return M.NY_;
 }
    CSRMatrics(std::map<int,std::array<int,3>> m, size_t nx_1, size_t ny_1){nx_=nx_1;//array<str, stolbec, znachenie>
        ny_=ny_1;
        a_.resize(m.size());
        nX_.resize(m.size());
        NY_.resize(ny_1+1);
        for (int t=0;t<ny_1;t++){
            NY_[t]=0;
        }
        for (int i=0;i<m.size();i++){
            a_[i]=std::get<2>(m.at(i));
            nX_[i]=std::get<1>(m.at(i));
            for (int g=ny_1;g>std::get<0>(m.at(i));g=g-1){
                NY_[g]++;
            }
        }
    }
};


#endif // CSRMATRICS_H_INCLUDED
