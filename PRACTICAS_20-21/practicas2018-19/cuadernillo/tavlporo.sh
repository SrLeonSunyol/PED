#! /bin/bash

rm -d -f -r Salida/tavlporo
mkdir Salida/tavlporo

make tavlporo

let tads=1
for ((i=1; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind  Salida/tavlporo/./tad0$i 
    echo "==========DIFF=============="
    diff src/tavlporo/tad0$i.cpp.sal Salida/tavlporo/./tad0$i
    #--leak-check=full #para depurar valgrind
done

#let tads=11
#for ((i=10; i<=$tads; i++))
#do
#    echo "=========================================="
#    echo "||             TEST#$i                  ||"
#    echo "=========================================="
#
#    echo "==========VALGRIND TAD=============="
#    valgrind Salida/tavlporo/./tad$i
#    echo "==========DIFF=============="
#    diff src/tavlporo/tad$i.cpp.sal Salida/tavlporo/./tad$i
#done
