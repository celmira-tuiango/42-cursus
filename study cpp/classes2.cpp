/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:43:19 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/02 15:58:43 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

class carro{
    private :
    int ano;
    float   valor, km;
    public:

    //construtor
    carro(int a=0, float v=-1, float k=-1)
    {
        ano = a;
        valor = v;
        km = k;
    }

    //ano
    void    setano(int a)
    {
        ano = a;
    }

    int getano()
    {
        return (ano);
    }

    //valor
    void    setvalor(float v)
    {
        valor = v;
    }

    float   getvalor()
    {
        return (valor);
    }

    //km
    void    setkm(float k)
    {
        km = k;
    }

    float   getkm()
    {
        return (km);
    }

};

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


    return (0);
}
