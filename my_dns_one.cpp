#include "my_dns_one.h"

my_dns_one::my_dns_one(QObject *parent) : QObject(parent)
{
    // Create a DNS lookup.
    dns = new QDnsLookup(this);
    connect(dns, SIGNAL(finished()), this, SLOT(handleServers()));

    this->domain = "localhost";
}

my_dns_one::my_dns_one(QString domain, QObject *parent) : QObject(parent)
{
    // Create a DNS lookup.
    dns = new QDnsLookup(this);
    connect(dns, SIGNAL(finished()), this, SLOT(handleServers()));

    this->domain = domain;
}

void my_dns_one::start_lookup()
{
    this->lookupServers();
}

void my_dns_one::setDomainName(QString s)
{
    this->domain = s;
}

void my_dns_one::lookupServers()
{
    // Find the servers for domain
    dns->setType(QDnsLookup::ANY);
    dns->setName(this->domain);
    dns->lookup();
}

void my_dns_one::handleServers()
{
    // Check the lookup succeeded.
    if (dns->error() != QDnsLookup::NoError)
    {
        qWarning("DNS lookup failed");
        dns->deleteLater();
        return;
    }

    for (int i = 0; i < dns->hostAddressRecords().size(); i++)
    {
        QDnsHostAddressRecord rec = dns->hostAddressRecords()[i];
        std::cout << rec.name().toStdString() << ": " << rec.value().toString().toStdString() << std::endl;
    }

    dns->deleteLater();
}
