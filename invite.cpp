#include "invite.h"
#include "ui_invite.h"

Invite::Invite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invite)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/EXTRA/Desktop/thxxx.png");

}

Invite::~Invite()
{
    delete ui;
}
