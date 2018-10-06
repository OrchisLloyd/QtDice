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
#include <memory>

class Dice		//makes use of Singleton and PIMPL idiom
{
private:
	int m_number;
	static Dice *m_pInstance;
	Dice( int num );
	Dice();
	~Dice();
	struct DiceImplementation;
	std::unique_ptr<DiceImplementation> d_dice;

public:
	static Dice *instance();

	int getNumber();
	void setNumber( int num );
	void roll();
	void show();
};
#endif /* dice_hpp */
// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
