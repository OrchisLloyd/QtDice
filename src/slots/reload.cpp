/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This files declares the overloaded public slot reload
 *
 * reload() constructs a Dice object that generates a random
 * integer value (=image_number) that essentially is what
 * a user would expect from a real dice. It then calls image_update
 * to select and show a dice image with the respective number
 *
 * reload(int) on the other hand doesn't generate a random Dice
 * number but accepts directly (from spinBox only as of 28/2/18)
 * an integer for image_update to show. Thus, when it's called
 * QtDice prints a message about cheating, because...well that's
 * not luck
 */

#include "../qtdice.h"

void QtDice::reload()
{
	animate_dice();

	Dice qtdice;
	qtdice.roll();
	image_update(qtdice.get_number());
	emit reloaded_without_spinbox();
}

void QtDice::reload(int number)
{
	animate_dice();
	Dice qtdice {number};
	image_update(qtdice.get_number());
}
