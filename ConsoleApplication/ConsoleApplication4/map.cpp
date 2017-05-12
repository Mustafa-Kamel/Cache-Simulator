#include <iostream>
using namespace std;

void dirCall();

void map(){//calls the suitable method for the replacement algorithm number selected by the user
	int m;
	cout << "Select the number of the intended mapping function"<<endl;
	cout << " 1- Direct\n 2- Associative\n 3- Set-Associative" << endl;
	cin >> m;
	switch (m){
	case 1:
		dirCall();
		break;
	case 2:
		//assocCall();
		break;
	case 3:
		//setAssocCall();
		break;
	default:
		cout << "undefined mapping function"<<endl;
		exit(0);
	}
}