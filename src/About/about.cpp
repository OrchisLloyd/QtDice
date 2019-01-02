/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This file defines a messagebox to show up
 * when the user clicks the "About QtDice" action.
 */

#include "about.h"
#include "infotab.h"

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
{
    tabWidget->addTab(w_info.data(), tr("InfoTab"));
}

// void About::show()
// {
// 	QDialog::show();
// }
//
// void About::setName( QString name )
// {
// }
#include "moc_about.cpp"
// kate: indent-mode cstyle; replace-tabs on; 
