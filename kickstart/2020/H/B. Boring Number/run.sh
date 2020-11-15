g++ --std=c++14 faster.cc && ./a.out < input.txt > output1.txt
g++ --std=c++14 solution.cc && ./a.out < input.txt > output2.txt
diff output1.txt output2.txt
