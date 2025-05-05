#include <iostream>
#include "carro.h"

using namespace std;

int main()
{
    carro   palio(200, 10000, 150000);

    palio.setano(2005);
    palio.setvalor(10000);
    palio.setkm(150000);
    cout << "palio: \n";
    cout << "Ano: " << palio.getano() << "\n";
    cout << "Valor: " << palio.getvalor() << "\n";
    cout << "Quilometragem: " << palio.getkm() << "\n";

    carro   celta(2000, 12000, 15000);

    //celta.setano(2000);
    //celta.setvalor(12000);
    //celta.setkm(15000);
    cout << "Celta: \n";
    cout << "Ano: " << celta.getano() << "\n";
    cout << "Valor: " << celta.getvalor() << "\n";
    cout << "Quilometragem: " << celta.getkm() << "\n";

    return(0);
}
