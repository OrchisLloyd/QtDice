#ifdef USER_MODE

#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <QWidget>

namespace Ui
{
class Challenge;
}

class Challenge : public QWidget
{
	Q_OBJECT

public:
	explicit Challenge(QSet<QString>* uniqueUserSet, QWidget* parent = nullptr);
	~Challenge();

private:
	Ui::Challenge* challenge_ui;
};

#endif // CHALLENGE_H

#endif //USER_MODE   
