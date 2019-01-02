#ifndef ANIMATION_H
#define ANIMATION_H

#include "../Dice/dice.hpp"
#include <QtCore/QEvent>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QScopedPointer>
#include <QtWidgets/QMenu>
#include <QMovie>
#include <QMessageBox>
#include <QPixmap>

class Animation : public QLabel
{
    Q_OBJECT
public:
    Animation ( QWidget *parent );
    ~Animation();

    void reload();
    void createActions();
    void setupConnectionsOfReload();
    void setupConnectionsOfAnimation();
    void Animation::imageUpdate ( int imageNumber );

public slots:
    void stopLastQMovieFrame ( QMovie *movie );

signals:
    void qmovieFrameChanged ( QMovie *movie );

protected:
    void contextMenuEvent ( QContextMenuEvent *event ) override;

private:
    QScopedPointer<QLabel>	label;
    QScopedPointer<QAction>	reloadAct;
    QScopedPointer<QMovie>	movie;
    QScopedPointer<QPixmap>	image;
    Dice	*pDice;

};
#endif
