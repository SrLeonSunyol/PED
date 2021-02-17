#! /bin/bash

rm -d -f -r Salida/tlistaporo
mkdir Salida/tlistaporo

make tlistaporo

let tads=9
for ((i=1; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="
    echo "==========VALGRIND TAD=============="
    valgrind --leak-check=full Salida/tlistaporo/./tad0$i
    echo "==========DIFF=============="
    diff src/tlistaporo/tad0$i.cpp.sal Salida/tlistaporo/./tad0$i
done

let tads2=18
for ((i=10; i<=$tads2; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind Salida/tlistaporo/./tad$i
    echo "==========DIFF=============="
    diff src/tlistaporo/tad$i.cpp.sal Salida/tlistaporo/./tad$i
done

