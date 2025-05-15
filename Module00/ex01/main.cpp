/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:57:10 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/08 10:57:13 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "Phonebook.hpp"
#include <csignal>

void    sig(int signal)
{
    std::exit(signal);
}

int main()
{
    std::signal(SIGQUIT, sig);
    std::string  input;
    Phonebook   phone;

    while (1)
    {
        std::cout << "Phone:";
        if (!std::getline(std::cin, input))
            return (1);
        if (input == "ADD")
            phone.add();
        if (input == "SEARCH")
            phone.search();
        if (input == "EXIT")
        {
            std::cout << "Você digitou " << input << "\n";
            exit(0);
        }
    }
    return (0);
}