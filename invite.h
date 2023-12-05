#ifndef INVITE_H
#define INVITE_H

#include <QDialog>

namespace Ui {
class Invite;
}

class Invite : public QDialog
{
    Q_OBJECT

public:
    explicit Invite(QWidget *parent = nullptr);
    ~Invite();

private:
    Ui::Invite *ui;
};

#endif // INVITE_H
