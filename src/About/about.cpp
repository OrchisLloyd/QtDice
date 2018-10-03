/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This file defines a messagebox to show up
 * when the user clicks the "About QtDice" action.
 */

#include "../headers/about.h"

About::About( QWidget *parent )
	: QDialog( parent ),
	  m_name( new QString ),
	  pushButton( new QPushButton( tr( "&Close" ), this ) ),
	  tabWidget( new QTabWidget( this ) ),
	  gridLayout( new QGridLayout( this ) ),
	  w_info( new QWidget( this ) ),
	  w_contributions( new QWidget( this ) ),
	  w_license( new QWidget( this ) ),
	  w_thanks( new QWidget( this ) )
{}

// void About::show()
// {
// 	QDialog::show();
// }
//
// void About::setName( QString name )
// {
// }
//#include "../headers/moc_about.cpp"
// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
<<<<<<< HEAD

=======
>>>>>>> e41dfcdaaf016b941a30ef18f6b678029e96ba79
