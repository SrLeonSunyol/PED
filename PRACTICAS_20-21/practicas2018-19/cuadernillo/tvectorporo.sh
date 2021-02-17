#! /bin/bash

rm -d -f -r Salida/tvectorporo
mkdir Salida/tvectorporo

make tvectorporo

let tads=9
for ((i=1; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind Salida/tvectorporo/./tad0$i
    echo "==========DIFF=============="
    diff src/tvectorporo/tad0$i.cpp.sal Salida/tvectorporo/./tad0$i
done

let tads=22
for ((i=10; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind Salida/tvectorporo/./tad$i
    echo "==========DIFF=============="
    diff src/tvectorporo/tad$i.cpp.sal Salida/tvectorporo/./tad$i
done
