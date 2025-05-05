/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:32:38 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/02 14:32:40 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

class propaganda{
    private:

    public:

    void    inscrever(){
        cout << "Se increva no canal da prof Cel! \n";
    }

    void    curta(){
        cout << "Curta esse video e ative o sininho! \n";
    }
};

int main()
{
    propaganda canal;

    canal.inscrever();
    canal.curta();
}
