#include <iostream>
#include "Direct.h"

using namespace std;

void dirCall(){
	char RW; int address;
	Direct dir;
	dir.parametersIn();
	dir.parametersCalc();
	do{
		cout << "\n\nEnter operation & adddress e.g(R 145 / W 320  or \"stop\" to exit\n";
		cin >> RW >> address;
		if (RW == 's')
			break;
		dir.addBits(address,RW);
		/*if (RW == 'R')
			dir.read(address);
		else if (RW == 'W')
			dir.write();
		else {
			cout << "undefined operation\n";
			return;
		}*/
	} while (RW != 's');
	dir.results();
}