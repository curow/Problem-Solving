python generate_test.py > huge_test.txt
cc wrong_solution_using_sort_but_dont_know_why.cc; ./a.out < huge_test.txt > debug.txt
cc solution.cc; ./a.out < huge_test.txt > correct.txt
diff correct.txt debug.txt > diff.txt
cat diff.txt
