// Arduino.cpp

#include "arduino.h"
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent), arduino() {
    connect(&arduino, &QSerialPort::readyRead, this, &Arduino::readArduinoData);
}

bool Arduino::connectToArduino(const QString &portName) {
    arduino.setPortName(portName);
    arduino.setBaudRate(QSerialPort::Baud9600);
    arduino.setDataBits(QSerialPort::Data8);
    arduino.setParity(QSerialPort::NoParity);
    arduino.setStopBits(QSerialPort::OneStop);
    arduino.setFlowControl(QSerialPort::NoFlowControl);

    return arduino.open(QIODevice::ReadWrite);
}

void Arduino::readArduinoData() {
    QByteArray data = arduino.readAll();

    // Process the received data from Arduino as needed
    qDebug() << "Received data: " << data;

    // Extract distance from the data (assuming data format is "D:123")
    if (data.startsWith("D:")) {
        QString distanceStr = data.mid(2); // Extract the distance part of the data
        bool conversionOK;
        int distance = distanceStr.toInt(&conversionOK);

        if (conversionOK) {
            // Emit the distanceChanged signal
            emit distanceChanged(distance);
        } else {
            qDebug() << "Error converting distance to integer";
        }
    } else {
        qDebug() << "Invalid data format from Arduino";
    }
}
