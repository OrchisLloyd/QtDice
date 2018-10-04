/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */
#include "dice.hpp"

struct Dice::DiceImplementation
{
		int m_num;
		DiceImplementation( int num ) : m_num( num ) {}
		DiceImplementation()
		{
				std::random_device rd;
				std::mt19937 e2( rd() );
				std::uniform_int_distribution<int> dis( 1, 6 );
				m_num = dis( e2 );
		}
};

Dice *Dice::m_pInstance = nullptr;

Dice *Dice::instance()
{
		if ( !m_pInstance )
		{
				m_pInstance = new Dice;
		}
		return m_pInstance;
}

Dice::Dice( int num ) : d_dice( new DiceImplementation( num ) ) {}

Dice::Dice() { d_dice.reset( new DiceImplementation ); }

Dice::~Dice() = default;

int Dice::getNumber()
{
		if ( ( d_dice->m_num < 0 ) && ( d_dice->m_num < 6 ) )
		{
				std::cerr << "Abort" << std::endl;
				exit( -1 );
		}
		else
		{
				return d_dice->m_num;
		}
}

void Dice::setNumber( int num )
{
		d_dice->m_num = num;
}

void Dice::roll()
{
		std::random_device rd;
		std::mt19937 e2( rd() );
		std::uniform_int_distribution<int> dis( 1, 6 );
		d_dice->m_num = dis( e2 );
}

// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
