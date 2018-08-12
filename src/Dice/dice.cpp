/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#include "dice.hpp"

Dice::Dice(int num) : m_number(num) {};

Dice::Dice()
{
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_int_distribution<int> dis(1, 6);
	m_number = dis(e2);
}

int Dice::getNumber()
{
	if ((this->m_number < 0) && (this->m_number < 6))
	{
		std::cerr << "Abort" << std::endl;
		exit(-1);
	}
	else
	{
		return this->m_number;
	}
}

void Dice::setNumber(int num)
{
	this->m_number = num;
}

void Dice::roll()
{
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_int_distribution<int> dis(1, 6);
	m_number = dis(e2);
}





// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
