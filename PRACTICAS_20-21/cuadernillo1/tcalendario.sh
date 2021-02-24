#! /bin/bash

rm -d -f -r Salida/tclanedario
mkdir -p Salida/tcalendario

make tcalendario

let tads=9
for ((i=1; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="

    echo "==========VALGRIND TAD=============="
    valgrind --track-origins=yes Salida/tcalendario/./tad0$i
    echo "==========DIFF=============="
    diff src/tcalendario/tad0$i.cpp.sal Salida/tcalendario/./tad0$i
done
echo "=========================================="
echo "||             TEST#10                ||"
echo "=========================================="
echo "==========VALGRIND TAD=============="
valgrind Salida/tcalendario/./tad10

echo "==========DIFF=============="

diff src/tcalendario/tad10.cpp.sal Salida/tcalendario/./tad10


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
    valgrind --track-origins=yes Salida/tcalendario/./tad$i
    echo "==========DIFF=============="
    diff src/tcalendario/tad$i.cpp.sal Salida/tcalendario/./tad$i
done