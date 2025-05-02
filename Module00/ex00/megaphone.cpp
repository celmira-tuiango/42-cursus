/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:39:55 by ctuiango          #+#    #+#             */
/*   Updated: 2025/05/01 11:40:00 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
using namespace std;

void    ft_uppercase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << (char)toupper(str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 1;
   if (ac > 1)
   {
        while (i < ac)
        {
            ft_uppercase(av[i]);
            i++;
        }
   }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    cout << "\n";
    return (0);
}

