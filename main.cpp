#include "GestionRecolte.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Apply a style sheet to the application
    QFile styleSheetFile("C:/Users/EXTRA/Documents/gestionInvite/Fibers.qss");
    if (styleSheetFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
        styleSheetFile.close();
    } else {
        // Handle style sheet loading failure if necessary
        qDebug() << "Failed to load style sheet";
    }

    // Create the main window
    GestionRecolte   w;

    // Create a database connection
    Connection c;
    bool test = c.createconnect();

    // Check the database connection status
    if (test) {
        // If the connection is successful, show the main window
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful."),
                                 QMessageBox::Ok);
    } else {
        // If the connection fails, show an error message
        QMessageBox::critical(nullptr, QObject::tr("Database Connection Error"),
                              QObject::tr("Connection failed."),
                              QMessageBox::Cancel);
    }

    return a.exec();
}
