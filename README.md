# openmpi_test
2021-12-22
openmpi_test
# [test00.cpp](./test00.cpp)(w/o openmp), [test01.cpp](./test01.cpp)(with openmp) result
2021-12-22 13:35:43
```
B:\prg\test\openmp_test>test00.exe
process time 15.000000[sec]
ans=1.250000E+17

B:\prg\test\openmp_test>test01.exe
process time 4.000000[sec]
ans=1.250000E+17
```

# [test02.cpp](./test02.cpp) result
```
B:\prg\test\openmp_test>test02
maximum number of threads : 8
thread = 0, i =  0
thread = 0, i =  1
thread = 1, i =  2
thread = 1, i =  3
thread = 2, i =  4
thread = 2, i =  5
thread = 4, i =  8
thread = 4, i =  9
thread = 5, i = 10
thread = 5, i = 11
thread = 3, i =  6
thread = 3, i =  7
thread = 6, i = 12
thread = 6, i = 13
thread = 7, i = 14
thread = 7, i = 15

maximum number of threads : 8
thread = 0, i =  0, j =  0
thread = 0, i =  0, j =  1
thread = 0, i =  0, j =  2
thread = 0, i =  0, j =  3
thread = 0, i =  0, j =  4
thread = 0, i =  0, j =  5
thread = 0, i =  0, j =  6
thread = 0, i =  0, j =  7
...
thread = 2, i =  5, j = 13
thread = 2, i =  5, j = 14
thread = 2, i =  5, j = 15

thread = 2 task0
thread = 6 task1
...
thread = 4 task6
thread = 1 task7

Hello World 0
Hello World 1
Hello World 0
Hello World 1
process time 231.0[msec]
```

