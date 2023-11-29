#ifndef ARDUINO_H
#define ARDUINO_H

#include <QByteArray>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QSqlQuery>

class Arduino

        {
        public:
            Arduino();
            int connect_arduino();
            int close_arduino();
            int write_to_arduino(QByteArray);
            QByteArray read_from_arduino();
            QSerialPort* getserial();
            QString getarduino_port_name(){return arduino_port_name;};
            //void write_to_arduino2(QString  d);
            //QByteArray read_from_arduino2();
            //int write_to_arduino(QByteArray d);


            QSerialPort* serial;
            static const quint16 arduino_uno_vendor_id=9025;
            static const quint16 arduino_uno_producy_id=67;
            QString arduino_port_name;
            bool arduino_is_available;
            QByteArray data;
            //QByteArray serialData;
            //QString serialBuffer;
            QString chercher(QString code);
            QByteArray getdata();

           private:
        };

#endif // ARDUINO_H
