#ifndef MESSAGINGSYSTEM_H
#define MESSAGINGSYSTEM_H

#include <QObject>
#include <QSqlDatabase>

class MessagingSystem : public QObject {
    Q_OBJECT
public:
    explicit MessagingSystem(QObject *parent = nullptr);
    bool sendMessage(int senderId, int receiverId, const QString &message);

private:
    QSqlDatabase m_database;
};

#endif // MESSAGINGSYSTEM_H
