/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:30 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 10:58:10 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe(char **argv) {
    std::vector<int> vec;
    std::vector<int> sorted_vec;
    std::deque<int> deq;
    std::deque<int> sorted_deq;
    std::string str;
    long number;
    clock_t start_vec, end_vec;
    clock_t start_deq, end_deq;

    for (int j = 1; argv[j] != NULL; j++) 
	{
        for (int i = 0; argv[j][i] != '\0'; i++) 
		{
            if (!isdigit(argv[j][i])) 
			{
                if (argv[j][i] == '-')
                    return (std::cout << "Error" << std::endl, false);
                return (std::cout << "Error" << std::endl, false);
            }
        }
        number = strtol(argv[j], NULL, 10);
        str = argv[j];
        if (number > 2147483647 || str.size() > 10)
            return (std::cout << "Error" << std::endl, false);
        vec.push_back(static_cast<int>(number));
        deq.push_back(static_cast<int>(number));
    }
    std::cout << "Before:  ";
    Vector(vec);

    start_vec = clock();
    sorted_vec = insertionSortVector(vec);
    end_vec = clock();
    long micro_vec = ((double)end_vec - (double)start_vec) / CLOCKS_PER_SEC * 1000000;
    std::cout << "After:   ";
    Vector(sorted_vec);

    start_deq = clock();
    sorted_deq = insertionSortDeque(deq);
    end_deq = clock();
    long micro_deq = ((double)end_deq - (double)start_deq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of   " << vec.size()
        << " elements with std::vector : " << micro_vec << "µs" << std::endl;
    std::cout << "Time to process a range of   " << deq.size()
        << " elements with std::deque  : " << micro_deq << "µs" << std::endl;
    return true;
}
