/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:58:02 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/02 11:58:04 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void  Contact::setname(std::string first_name)
{
    this->name = first_name;    
}

void  Contact::setlname(std::string last_name)
{
    this->l_name = last_name;    
}

void  Contact::setnname(std::string nickname)
{
    this->n_name = nickname;    
}

void  Contact::setnumber(std::string new_number)
{
    this->number = new_number;
}
void  Contact::setdarkest(std::string new_secret)
{
    this->secret = new_secret;    
}

std::string Contact::getname() const
{
    return (this->name);
}

std::string Contact::getlname() const
{
    return (this->l_name);
}

std::string Contact::getnname() const
{
    return (this->n_name);
}

std::string Contact::getnumber() const
{
    return (this->number);
}

std::string Contact::getdarkest() const
{
    return (this->secret);

}
