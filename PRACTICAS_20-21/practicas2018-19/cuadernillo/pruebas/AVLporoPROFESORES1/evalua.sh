# bash evalua.sh
TADDIR="../../" #directorio

for FILE in tad*.cpp ; do
	echo " "
	echo " "
	echo "Evaluando $FILE"
	echo "--------------------------------------------"
	cp $FILE $TADDIR/src/tad.cpp
	pushd $TADDIR
	make
	popd
	$TADDIR/tad | sed -r 's/$/\r/' > $FILE.out
	diff $FILE.out $FILE.sal
done
