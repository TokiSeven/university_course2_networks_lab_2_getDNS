#ifndef MY_DNS_ONE_H
#define MY_DNS_ONE_H

#include <QObject>
#include <QtNetwork/QDnsLookup>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QDnsHostAddressRecord>
#include <QtNetwork/QDnsDomainNameRecord>
#include <iostream>

class my_dns_one : public QObject
{
    Q_OBJECT
public:
    explicit my_dns_one(QObject *parent = 0);
    explicit my_dns_one(QString domain, QObject *parent = 0);

    void setDomainName(QString);//set the domain name

    void start_lookup();//start lookup

private slots:
    void handleServers();//where ip was been got

private:
    void lookupServers();
    QDnsLookup *dns;
    QString domain;
};

#endif // MY_DNS_ONE_H
