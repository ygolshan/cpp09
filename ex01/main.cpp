/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:03:39 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 11:19:20 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>


int operation(int n1, int n2, char o)
{
    int result = 0;
    if (o == '+')
        result = n1 + n2;
    else if (o == '-')
        result = n1 - n2;
    else if (o == '*')
        result = n1 * n2;
    else if (o == '/') {
        if (n2 == 0)
            throw std::invalid_argument("impossible.");
        result = n1 / n2;
    }
    return result;
}


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    try
    {
        read_RPN(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}



