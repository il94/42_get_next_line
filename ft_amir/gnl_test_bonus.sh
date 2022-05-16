#!/bin/bash

mkdir Result

clang -Wall -Werror -Wextra main_exemple_multi.c

./a.out 41_no_nl 42_with_nl alternate_line_nl_no_nl big_line_with_nl multiple_line_with_nl 41_with_nl 43_no_nl alternate_line_nl_with_nl empty multiple_nlx5 42_no_nl 43_with_nl big_line_no_nl multiple_line_no_nl nl > Result/file_test_exemple.txt

clang -Wall -Werror -Wextra -D BUFFER_SIZE=1 ../Get_next_line/get_next_line_bonus.c ../Get_next_line/get_next_line_utils_bonus.c main_other_multi.c

./a.out 41_no_nl 42_with_nl alternate_line_nl_no_nl big_line_with_nl multiple_line_with_nl 41_with_nl 43_no_nl alternate_line_nl_with_nl empty multiple_nlx5 42_no_nl 43_with_nl big_line_no_nl multiple_line_no_nl nl > Result/file_test_other_1.txt

diff -u Result/file_test_exemple.txt Result/file_test_other_1.txt > Result/test_final_buf_1.txt

echo ""
echo "	Test Bonus"

if [ -s Result/test_final_buf_1 ]
then
	echo ""
	echo "BUFFER_SIZE 1 ==> Diff KO =C"
else
	echo ""
	echo "BUFFER_SIZE 1 ==> Diff OK =D"
	rm -rf Result/file_test_other_1.txt Result/test_final_buf_1.txt
fi

clang -Wall -Werror -Wextra -D BUFFER_SIZE=42 ../Get_next_line/get_next_line_bonus.c ../Get_next_line/get_next_line_utils_bonus.c main_other_multi.c

./a.out 41_no_nl 42_with_nl alternate_line_nl_no_nl big_line_with_nl multiple_line_with_nl 41_with_nl 43_no_nl alternate_line_nl_with_nl empty multiple_nlx5 42_no_nl 43_with_nl big_line_no_nl multiple_line_no_nl nl > Result/file_test_other_42.txt

diff -u Result/file_test_exemple.txt Result/file_test_other_42.txt > Result/test_final_buf_42.txt

if [ -s Result/test_final_buf_42 ]
then
	echo ""
	echo "BUFFER_SIZE 42 ==> Diff KO =C"
else
	echo ""
	echo "BUFFER_SIZE 42 ==> Diff OK =D"
	rm -rf Result/file_test_other_42.txt Result/test_final_buf_42.txt
fi

clang -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 ../Get_next_line/get_next_line_bonus.c ../Get_next_line/get_next_line_utils_bonus.c main_other_multi.c

./a.out 41_no_nl 42_with_nl alternate_line_nl_no_nl big_line_with_nl multiple_line_with_nl 41_with_nl 43_no_nl alternate_line_nl_with_nl empty multiple_nlx5 42_no_nl 43_with_nl big_line_no_nl multiple_line_no_nl nl > Result/file_test_other_10000000.txt

diff -u Result/file_test_exemple.txt Result/file_test_other_10000000.txt > Result/test_final_buf_10000000.txt

if [ -s Result/test_final_buf_10000000 ]
then
	echo ""
	echo "BUFFER_SIZE 10000000 ==> Diff KO =C"
else
	echo ""
	echo "BUFFER_SIZE 10000000 ==> Diff OK =D"
	rm -rf Result/file_test_exemple.txt Result/file_test_other_10000000.txt Result/test_final_buf_10000000.txt
fi

echo ""

rm -rf Result
