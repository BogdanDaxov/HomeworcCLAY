#ifndef M3d
#define M3d

#include <cstddef>
#include <vector>
template <typename T>
class three_diagonaled_Matrix {
private:
 std::vector<T> a;//a[0]=0
 std::vector<T> b;
 std::vector<T> c;//c[n-1]=0
public:
 /*T operator()(size_t j) const {
 return std::vector<T>{a[j],b[j],c[j]};
 }*/
 three_diagonaled_Matrix(std::vector<T> a1,std::vector<T> b1,std::vector<T> c1){a=a1; b=b1; c=c1;}
 size_t size_ (three_diagonaled_Matrix M){
 return M.b.size();
 }
 std::vector<T> A(three_diagonaled_Matrix M){
 return M.a;
 }
  std::vector<T> B(three_diagonaled_Matrix M){
 return M.b;
 }
  std::vector<T> C(three_diagonaled_Matrix M){
 return M.c;
 }
 std::vector<T> solve(three_diagonaled_Matrix M, std::vector<T>d){
    std::vector<T> P(M.size_(M)-1);
    P[0]=-M.C(M)[0]/M.B(M)[0];
    std::vector<T> Q(M.size_(M)-1);
    Q[0]=d[0]/M.B(M)[0];
    std::vector<T> X(M.size_(M));
    for (size_t i=1;i<M.size_(M)-1;i++){
        P[i]=-M.C(M)[i]/(M.A(M)[i]*P[i-1]+M.B(M)[i]);
        Q[i]=(d[i]-M.A(M)[i]*Q[i-1])/(M.A(M)[i]*P[i-1]+M.B(M)[i]);
    }
    X[M.size_(M)-1]=(d[M.size_(M)-1]-M.A(M)[M.size_(M)-1]*Q[M.size_(M)-1-1])/(M.A(M)[M.size_(M)-1]*P[M.size_(M)-1-1]+M.B(M)[M.size_(M)-1]);
    for (size_t i=M.size_(M)-2;i>=1;i=i-1){
        X[i]=P[i]*X[i+1]+Q[i];
    }
    X[0]=P[0]*X[1]+Q[0];
    return X;
 }

};
#endif // M3d
