/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:04:53 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 10:58:44 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


void read_RPN(std::string input)
{
    std::stack<int> nbrs;
    std::string ops = "+-*/";
    int op = 0, num = 0;
    
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            if (input[i + 1] && (input[i + 1] != ' '))
                throw std::invalid_argument("Invalid Input");
            num++;
            nbrs.push(input[i] - '0');
        }
        else if (nbrs.empty())
        {
            break;
        }
        else if (ops.find(input[i]) != std::string::npos)
        {
            if (num < 2 || (input[i + 1] && (input[i + 1] != ' ')))
                throw std::invalid_argument("Invalid Input");
            op++;
            int n2 = nbrs.top();
            nbrs.pop();
            if (!nbrs.empty()) {
                int n1 = nbrs.top();
                nbrs.pop();
                nbrs.push(operation(n1, n2, input[i]));
            }
        }
        else if (input[i] != ' ')
            throw std::invalid_argument("Invalid Input");
    }
    if (num != (op + 1))
        throw std::invalid_argument("Error");
    std::cout << nbrs.top() << std::endl;
}