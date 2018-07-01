/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef QTHEADERS_H
#define QTHEADERS_H

# ifdef USER_MODE
#   include "userwidget.h"
#   include <QCheckBox>
# endif
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QGridLayout>
#include <QSpinBox>
#include <QString>
#include <QImage>
#include <QDir>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QSpacerItem>
#include <QFile>
#include <QMovie>
#include <QTranslator>
#include <QtGlobal>
#include <QSettings>

#ifdef ENABLE_SOUND
# include <QtMultimedia/QSound>
# include <QtMultimedia/QMediaPlayer>
# include <QUrl>
# include <QtMultimedia/QSoundEffect>
#endif

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include <QIcon>
#include <QInputDialog>

#endif   //QTHEADERS_H
