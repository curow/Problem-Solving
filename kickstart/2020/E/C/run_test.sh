python generate_test.py > huge_test.txt
cc large_case.cc; ./a.out < huge_test.txt > debug.txt
cc solution.cc; ./a.out < huge_test.txt > correct.txt
diff correct.txt debug.txt > diff.txt
cat diff.txt
