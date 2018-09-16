#include "UIntPacker.h"

UIntPacker::UIntPacker()
{
	m_data = 0x0;
	m_bitcount = 0;
}

bool UIntPacker::pack(unsigned int value, unsigned int bitCount)
{
	if (31 - m_bitcount - bitCount < 0)
	{
		std::cout << "Not enough space, requested : " << bitCount << std::endl;
		return false;
	}
	else
	{
		m_data = m_data | (value << m_bitcount);
		m_bitcount += bitCount;
		return true;
	}
}

unsigned int UIntPacker::extract(unsigned int bitCount)
{
	unsigned int val;
	unsigned int mask;
	mask = (1 << bitCount) - 1;
	val = m_data & mask;
	m_data = m_data >> bitCount;

	return val;
}
