

1 sur 261
(aucun objet)
Boîte de réception

Malek Chairat
Pièces jointes
10:15 (il y a 4 minutes)
À moi


Traduire le message
Désactiver pour : anglais

 16 pièces jointes
  • Analyse effectuée par Gmail
#include "arduino.h"

Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;

}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino()
{

    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id)
            {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();

            }
        }
    }

    qDebug() << "arduino_port_name is : " << arduino_port_name;

    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return  0;
        }
        return 1;
    }

    return -1;
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}

/*QSerialPort* Arduino::getserial()
{
    return serial;
}*/
 QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
        serial->waitForReadyRead(20);
         data=serial->readAll(); //récupérer les données reçues
         qDebug() << "data === "+data;
         return data;
    }
 }

int Arduino::write_to_arduino(QByteArray d)
{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }

}

QByteArray Arduino::getdata()
{
    return data;
}
QString Arduino::chercher(QString code){

    QSqlDatabase bd = QSqlDatabase::database();
QString nom;
        QSqlQuery query;
        query.prepare("SELECT NOM,ID_E FROM EMPLOYEE WHERE ID_E =:code");
 query.bindValue(":code", code);

        query.exec();
        if (query.next())
        {

            nom=query.value(0).toString();

             return nom;
        }
        else {
            return "";
      }
    }
