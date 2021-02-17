#! /bin/bash

rm -d -f -r Salida/tabbporo
mkdir Salida/tabbporo

make tabbporo

let tads=1
for ((i=1; i<=$tads; i++))
do
    echo "=========================================="
    echo "||             TEST#$i                  ||"
    echo "=========================================="
    echo "==========VALGRIND TAD=============="
    valgrind --leak-check=full Salida/tabbporo/./TABBPoro0$i
    echo "==========DIFF=============="
    diff src/tabbporo/TABBPoro-0$i.cpp.sal Salida/tabbporo/./TABBPoro0$i
done

#let tads2=12
#for ((i=10; i<=$tads2; i++))
#do
#    echo "=========================================="
#    echo "||             TEST#$i                  ||"
#    echo "=========================================="
#
#    echo "==========VALGRIND TAD=============="
#    valgrind --track-origins=yes Salida/tabbporo/./TABBPoro$i
#    #echo "==========DIFF=============="
#    #diff src/tabbporo/TABBPoro-$i.cpp.sal Salida/tabbporo/./TABBPoro$i
#done   
