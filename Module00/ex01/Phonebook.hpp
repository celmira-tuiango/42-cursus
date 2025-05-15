/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:43:41 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/09 17:43:44 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class Phonebook
{
private:
    Contact contacts[8];
    int current;
    int total;
public:
    Phonebook();
    void    add();
    void    search();
    void    print_list();
    std::string subString(const std::string& str);
};

#endif
