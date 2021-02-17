#! /bin/bash

rm -d -f -r Salida/tporo
mkdir Salida/tporo

make tporo

let tads=9
for ((i=1; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind --track-origins=yes Salida/tporo/./tad0$i
    echo "==========DIFF=============="
    diff src/tporo/tad0$i.cpp.sal Salida/tporo/./tad0$i
done
echo "=========================================="
echo "||             TEST#10                ||"
echo "=========================================="
echo "==========VALGRIND TAD=============="
valgrind Salida/tporo/./tad10

echo "==========DIFF=============="

diff src/tporo/tad10.cpp.sal Salida/tporo/./tad10


echo "=========================================="
echo "           test de correccion"
echo "=========================================="

let tads=22
for ((i=11; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind --track-origins=yes Salida/tporo/./tad$i
    echo "==========DIFF=============="
    diff src/tporo/tad$i.cpp.sal Salida/tporo/./tad$i
done