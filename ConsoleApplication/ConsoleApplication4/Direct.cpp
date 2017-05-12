#include "Direct.h"
#include <iostream>
#include <math.h>
using namespace std;

void Direct::results(){
	cout << "#Cache Hit = " << hitSum << endl;
	cout << "#Cache Miss = " << missSum << endl;
	int memRef = hitSum + missSum;
	if (memRef != 0){
		float hitRat = (static_cast<double>(hitSum) / static_cast<double>(memRef));
		cout << "Hit ratio = " << hitRat << endl;
	}
}

void Direct::addBits(int address,char RW){
	if (address >= memSize){
		cout << "out of range. address can't be larger than size of Memory" << endl;
		return;
	}

	//calculate address
	add = new int[l];
	for (int i = 0; i < l; i++){
		add[i] = address % 2;
		address = address / 2;
	}
	//creating array of dirty bits=lines number and reset them
	if (wHitPol = 2)
		dirtBit = new bool[linesNum];
	for (int i = 0; i < linesNum; i++)
		dirtBit[i] = 0;

	//view address
	for (int i = 1; i <= l; i++)
		cout << add[l - i];
	cout << endl;

	//calculate address parameters
	int x = 0, y = 0;
	addBlock = 0, addLine = 0, addTag = 0;
	for (int i = w; i < l; i++){
		addBlock += (add[i] * pow(2 , x++));
		if (i >= r+w)
			addTag += (add[i] * pow(2 , y++));
	}
	addLine = addBlock % linesNum;
	cout << "Block #" << addBlock << endl;
	cout << "Line #" << addLine << endl;
	cout << "Tag #" << addTag << endl;
	
	//write hit & miss policies
		if (addBlock == cache[addLine]){	//read hit
			hitSum++;
			cout << "Cache Hit\n";
			if (RW == 'W'){		//write hit
				if (wHitPol == 2)
					dirtBit[addLine] = 1;
			}
			cout << "No Line-Allocation\nNo Write-Back\n";
		}
		else{
			missSum++;
			cout << "Cache Miss\n";
			if (RW == 'R'){		//read miss
				cache[addLine] = addBlock;
				cout << "Line-Allocation\n";
				if (dirtBit[addLine]){
					cout << "Write-Back\n";
					dirtBit[addLine] = 0;
				}
				else cout << "No Write-Back\n";
			}
			else writeMiss();		//write miss
		}

}

void Direct::parametersIn(){/*set memory and cache parameters according to user input
							(size of MM,cache,block & write hit & miss policies */
	cout << "Enter MM size:\n" ;
	cin >> memSize;
	cout << "Enter Cache memory size:\n";
	cin >> cacheSize;
	cout << "Enter block size:\n";
	cin >> blockSize;
	cout << "Select write Hit policy:\n";
	cout << " 1- write through\n 2- write back\n";
	cin >> wHitPol;
	if (wHitPol != 1 && wHitPol != 2){
		cout << "undefined\n";
		exit(0);
	}
	cout << "Select write Miss policy:\n 0- no write allocate\n 1- write allocate\n";
	cin >> wAllocPol;

	if (wAllocPol != 1 && wAllocPol != 0){
		cout << "undefined\n";
		exit(0);
	}
}

void Direct::parametersCalc (){//calculates #blocks,#lines & length of address bits (w,s,r,t)
	blocksNum = memSize / blockSize;
	linesNum = cacheSize / blockSize;
	cache = new int[linesNum];
	l = log2(memSize);
	w = log2(blockSize);
	s = log2(blocksNum);
	r = log2(linesNum);
	t = s - r;
}

void Direct::writeMiss(){
	if (wAllocPol){
		cache[addLine] = addBlock;
		cout << "Line-Allocation\n";
		if (dirtBit[addLine] && wHitPol == 2){
			cout << "Write-Back\n";
			dirtBit[addLine] = 0;
		}
		else cout << "No Write-Back";
		if(wHitPol==2)
			dirtBit[addLine] = 1;
	}
	else{
		cout << "No Line-Allocation\n";
		cout << "No Write-Back\n";
	}
}

