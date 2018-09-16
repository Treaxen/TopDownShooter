#ifndef  UINTPACKER_H
#define UINTPACKER_H

#include <iostream>

class UIntPacker
{
private:
	unsigned int m_data = 0;
	unsigned int m_bitcount = 0; //to count how many bits are used

public:
	UIntPacker();
	//pack the "value" into m_data, it returns true if there are enough bits available
	//bitCount : the bit count of the "value"
	bool pack(unsigned int value, unsigned int bitCount);

	unsigned int extract(unsigned int bitCount);
};









#endif // ! UINTPACKER_H

