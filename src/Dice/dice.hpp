/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef dice_hpp
#define dice_hpp

#include <random>
#include <iostream>

class Dice
{
private:
	int m_number;

public:
	Dice(int num);
	Dice();
	int get_number();
	void set_number(int num);
	void roll();
	void show();
};
#endif /* dice_hpp */
