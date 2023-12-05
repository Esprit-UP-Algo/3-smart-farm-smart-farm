
#ifndef arduino_H
#define arduino_H

#include <QObject>
#include <QSerialPort>
#include "ui_GestionRecolte.h"


class Arduino : public QObject
{
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);
    bool connectToArduino(const QString &portName);

signals:
    void arduinoDataReceived(const QByteArray &data);
    void distanceChanged(int distance);

private slots:
    void readArduinoData();

private:
    QSerialPort arduino;
    Ui::GestionRecolte *ui;


};

#endif // ARDUINO_H
