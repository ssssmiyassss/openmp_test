// http://www.sanko-shoko.net/note.php?id=9twp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main() {
  // 2019-09-05 18:16:18
  // for time measurement
  std::chrono::system_clock::time_point start, end;
  start = std::chrono::system_clock::now();

  // openmpi test
  printf("maximum number of threads : %d\n", omp_get_max_threads());

  #pragma omp parallel for
  for (int i = 0; i < 16; i++) {
    // 検証用の表示
    printf("thread = %d, i = %2d\n", omp_get_thread_num(), i);
  }

  // 多重ループの場合
  printf("maximum number of threads : %d\n", omp_get_max_threads());
  #pragma omp parallel for
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      // 検証用の表示
      printf("thread = %d, i = %2d, j = %2d\n", omp_get_thread_num(), i,j);
    }
  }

  // 並列タスクの割り当て 2021-12-22 15:06:48
  #pragma omp parallel sections num_threads(8)
  {
    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task0\n", omp_get_thread_num());
    }

    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task1\n", omp_get_thread_num());
    }

    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task2\n", omp_get_thread_num());
    }
    
    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task3\n", omp_get_thread_num());
    }

    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task4\n", omp_get_thread_num());
    }

    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task5\n", omp_get_thread_num());
    }

    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task6\n", omp_get_thread_num());
    }

    #pragma omp section
    {
      // （何かの処理）
      printf("thread = %d task7\n", omp_get_thread_num());
    }


  }

  // 2021-12-22 15:18:58
  #pragma omp parallel num_threads(2)
  { 
    printf("Hello World %d\n",omp_get_thread_num());
  }  

  // 2021-12-22 15:19:26
  #pragma omp parallel num_threads(2)
  { 
    #pragma omp critical
    {
      printf("Hello World %d\n",omp_get_thread_num());
    }
  }

  // 2019-09-05 18:16:18
  // for time measurement
  end = std::chrono::system_clock::now();
  double time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
  fprintf(stderr,"process time %.1lf[msec]\n", time);
  return 0;
}