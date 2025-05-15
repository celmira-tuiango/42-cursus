/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:40:05 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/10 13:40:07 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
private:
    std::string name;
    std::string l_name;
    std::string n_name;
    std::string secret;
    std::string number;
public:
    void    setname(std::string first_name);
    void    setlname(std::string last_name);
    void    setnname(std::string nickname);
    void    setnumber(std::string new_number);
    void    setdarkest(std::string new_secret);
    std::string getname() const;
    std::string getlname() const;
    std::string getnname() const;
    std::string getnumber() const;
    std::string getdarkest() const;
};

#endif
