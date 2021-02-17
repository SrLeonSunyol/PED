#include <iostream>
#include "tvectorporo.h"

int main(){
	TVectorPoro v;
	
	v.Redimensionar(5);
	
	cout << v[0] << endl;
	cout << v[1] << endl;

	v[1] = TPoro(0, 3, 3, "POYA");	
	cout << v << endl;

	for(int i = 2; i <= 5; i++){
		v[i] = TPoro(i, i, i, "putij");
	}

	cout << v << endl;

	v.Redimensionar(3);

	cout << v << endl;


	v.Redimensionar(10);
	cout << v << endl;
	return 0;

}
