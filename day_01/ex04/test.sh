#!/bin/bash

printf "Source file: title 'example.txt'\n\n"
cat example.txt
printf "\n\n"
printf "./replace example.txt happy sad"
./replace example.txt happy sad
printf "\n\n"
printf "ls\n"
ls 
printf "\n\n"
printf "Output file: title 'EXAMPLE.TXT.replace'\n\n"
cat EXAMPLE.TXT.replace
printf "\n\n"
diff example.txt EXAMPLE.TXT.replace
printf "\n\n"
printf "Now let's test for error management\n\n"
printf "./replace \"\" happy sad\n"
./replace "" happy sad
printf "\n"
printf "./replace example.txt \"\" sad\n"
./replace example.txt "" sad
printf "\n"
printf "./replace example.txt happy \"\"\n"
./replace example.txt happy ""
printf "\n\n"
printf "./replace FILE_NOT_EXIST happy sad\n"
./replace FILE_NOT_EXIST happy sad
printf "\n\n"
printf "chmod 000 example.txt"
chmod 000 example.txt
printf "./replace example.txt happy sad\n"
./replace example.txt happy sad
chmod 644 example.txt
