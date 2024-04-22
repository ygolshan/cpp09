/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:45 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 10:57:54 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void	Vector( std::vector<int> vec ) 
{
	std::vector<int>::iterator 	it;
	int	i = 0;
	
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if (i++ > 4)
			break ;
		std::cout << *it << " ";
	}
	if (it != vec.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

std::vector<int>	insertionSortVector( std::vector<int> vec) 
{
	int y;
	int j;
	for (size_t i = 1; i < vec.size(); i++)
	{
		y = vec[i];
		j = i - 1;
		while (j >= 0 && vec[j] > y)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = y;
	}
	return (vec);
}

std::deque<int>	insertionSortDeque( std::deque<int> deq)
{
	int y;
	int j;
	for (size_t i = 1; i < deq.size(); i++)
	{
		y = deq[i];
		j = i - 1;
		while (j >= 0 && deq[j] > y)
		{
			deq[j + 1] = deq[j];
			j--;
		}
		deq[j + 1] = y;
	}
	return (deq);
}

void	Deque( std::deque<int> deq ) 
{
	std::deque<int>::iterator 	it;
	int							i = 0;
	for (it = deq.begin(); it != deq.end(); it++)
	{
		if (i++ > 4)
			break ;
		std::cout << *it << " ";
	}
	if (it != deq.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

int main(int argc, char **argv) 
{
    if (argc == 1) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        bool success = PmergeMe(argv);
        if (!success) {
            std::cerr << "Error occurred in PmergeMe function" << std::endl;
            return 1;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}