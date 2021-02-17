#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
	TPoro poros[] = {
			TPoro(10, 10, 2.55, "Blanco"),
			TPoro(10, 10, 2.55, "Blanco"),
			TPoro(10, 10, 2.55, "Blanco"),
			TPoro(10, 10, 2.55, "Blanco"),
			TPoro(10, 10, 2.55, "Blanco"),
			TPoro(10, 10, 2.55, "Blanco"),
			TPoro(10, 10, 2.55, "Azul")
	};

	TVectorPoro v;
	cout << v.Redimensionar(-3) << endl;
	cout << v.Redimensionar(0) << endl;

	for(int i = 1; i <= 7; i++){		
		cout << (v.Redimensionar(i) == 0 ? "MAL" : "BIEN") << " ==> ";
		v[i] = poros[i - 1];
		cout << i << ": " << endl;
		cout << v << endl;
	}
	cout << "---" << endl;
	cout << " ahora para abajo .. para abajo... " << endl;
	cout << "---" << endl;
	
	for(int i = 7; i >= 1; i--){
		cout << (v.Redimensionar(i)==0?"MAL":"BIEN") << " ==> ";
		cout << i << ": " << endl;
		cout << v << endl;
	}	
	
 	return 0;
}
