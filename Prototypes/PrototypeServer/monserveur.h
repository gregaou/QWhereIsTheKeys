#ifndef MONSERVEUR_H
#define MONSERVEUR_H

#include <QTcpServer>
#include <QDebug>
#include "monthread.h"

class MonServeur : public QTcpServer
{
    Q_OBJECT
public:
    explicit MonServeur(QObject *parent = 0);
    void startServer();

signals:
    
protected:
    void incomingConnection(int sDescriptor);

public slots:
    
};

#endif // MONSERVEUR_H
