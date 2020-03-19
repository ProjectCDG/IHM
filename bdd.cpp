#include "bdd.h"

Bdd::Bdd()
{

}

bool Bdd::Initialise(){
    QSqlDatabase base = QSqlDatabase::addDatabase("projet_local");
    base.setHostName("localhost");
    base.setUserName("root");
    base.setPassword("");
    base.setDatabaseName("projet_local");

    bool etat = base.open();

    return etat;
}
