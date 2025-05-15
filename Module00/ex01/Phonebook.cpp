/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:26 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:28 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    this->current = 0;
    this->total = 0;
}

void Phonebook::add()
{
    std::string  input;

    do {
        std::cout << "First Name: ";
        getline(std::cin, input);
    } while (input.empty());
    contacts[current].setname(input);
    
    do {
        std::cout << "LAST NAME: ";
        getline(std::cin, input);
    } while (input.empty());
    contacts[current].setlname(input);
    
    do {
        std::cout << "NICKNAME: ";
        getline(std::cin, input);
    } while (input.empty());
    contacts[current].setnname(input);

    do {
        std::cout << "PHONE NUMBER: ";
        getline(std::cin, input);
    } while (input.empty());
    contacts[current].setnumber(input);

    do {
        std::cout << "DARKEST SECRET: ";
        getline(std::cin, input);
    } while (input.empty());
    contacts[current].setdarkest(input);

    if (total < 8)
        total++;
    current = (current + 1) % 8;
    return ;
}


std::string Phonebook::subString(const std::string& str)
{
    if (str.length() > 10)
        return (str.substr(0, 9)) + ".";
    return (str);
}

void    Phonebook::print_list()
{
    std::cout << std::right << std::setw(10) << "Index"
    << "|" << std::right << std::setw(10) << "First Name"
    << "|" << std::right << std::setw(10) << "Last Name"
    << "|"  << std::right << std::setw(10) << "Nickname\n";

    int i = 0;
    while (i < total)
    {
        std::cout << std::setw(10) << i
        << "|" << std::right << std::setw(10) << subString(contacts[i].getname())
        << "|" << std::right << std::setw(10) << subString(contacts[i].getlname())
        << "|" << std::right << std::setw(10) << subString(contacts[i].getnname()) << "\n";
        i++;
    }
}

void    Phonebook::search()
{
    std::string input;

    print_list();
    if (!this->total)
    {
        std::cout << "Preencha os campos\n";
        return ;
    }
    std::getline(std::cin, input);
    if (input.length() && std::isdigit(input[0]))    
    {
        int index = input[0] - '0';    
        if (index >= 0 &&  index < this->total)
        {
            std::cout << "-------------------Contact Details-------------------\n";
            std::cout << index << "-";
            std::cout << "Name: " << contacts[index].getname() << "\n";
            std::cout << "Last Name: " << contacts[index].getlname() << "\n";
            std::cout << "Nickname: " << contacts[index].getnname() << "\n";
            std::cout << "Number: " << contacts[index].getnumber() << "\n";
            std::cout << "Darkest Secret: " << contacts[index].getdarkest() << "\n";
            std::cout << "---------------------------------------------------\n";
        }
    }
}
