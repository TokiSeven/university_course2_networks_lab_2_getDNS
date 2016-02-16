#include <QCoreApplication>
#include "my_dns_one.h"
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string s;
    my_dns_one dns;

    //read domain name
    cout << endl << "Please, write name of the domain: ";
    getline(cin, s);

    //set domain name and lookup this
    dns.setDomainName(QString::fromStdString(s));
    dns.start_lookup();

    return a.exec();
}
