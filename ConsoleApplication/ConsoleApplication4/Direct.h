#pragma once
class Direct
{
	int *cache, *add; bool *dirtBit;
	char RW;
	int memSize, cacheSize, blockSize;
	int blocksNum, linesNum;
	int wHitPol, wAllocPol;
	int hitSum=0, missSum=0;
	int l, w, s, r, t;
	int addBlock, addLine, addTag;
public:
	Direct(){}
	~Direct(){ delete[]cache; delete[]add; delete[]dirtBit; }
	void parametersIn();
	void parametersCalc();
	void writeMiss();
	void results();
	void addBits(int address,char RW);

};

