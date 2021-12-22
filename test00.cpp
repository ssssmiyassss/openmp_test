#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include <chrono>

#define NUM 500000000

int main() {
  // 2019-09-05 18:16:18
  // for time measurement
  std::chrono::system_clock::time_point start, end;
  start = std::chrono::system_clock::now();

  // openmpi test
  std::vector<double> v1; v1.resize(NUM);
  std::vector<double> v2; v2.resize(NUM);
  double ans=0.0;
  // #pragma omp parallel
  // {
    // #pragma omp for
    for(int i=0;i<NUM;i++){
      // if(i%1000==0)fprintf(stderr,"i=%d\r",i);
      v1[i]=sqrt( (double)i );
      v2[i]=sqrt( (double)i );
    }
    // #pragma omp for reduction(+:ans)
    for(int i=0;i<NUM;i++){
      // if(i%1000==0)fprintf(stderr,"i=%d\r",i);
      ans += v1[i]*v2[i];
    }
  // }
  // 2019-09-05 18:16:18
  // for time measurement
  end = std::chrono::system_clock::now();
  double time = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
  fprintf(stderr,"process time %lf[sec]\n", time);
  printf("ans=%E",ans);
  return 0;
}