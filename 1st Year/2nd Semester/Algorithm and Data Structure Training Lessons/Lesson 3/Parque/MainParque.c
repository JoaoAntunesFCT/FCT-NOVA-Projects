#include <stdio.h>
#include <ctype.h>

#include "Parque.h"
#include "Parqueticket.h"

int main()
{
    _estacionamento repouso;
    repouso = GerarParque(MAXSIZE_SEATS);
    MainMenu(repouso);
    DestroiParqueTicket(repouso);

    return 0;
}