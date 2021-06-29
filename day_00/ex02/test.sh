make re
./account_test | cut -f 2- -d ' ' > test_log.txt
cut -f 2- -d ' ' 1992*.log > original_log.txt
diff test_log.txt original_log.txt

