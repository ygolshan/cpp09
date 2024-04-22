/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:14 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 10:27:52 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


std::vector<int>	insertionSortVector( std::vector<int> vec);
std::deque<int>	    insertionSortDeque( std::deque<int> deq);

bool    PmergeMe( char **argv );
void	Vector( std::vector<int> vec ) ;
void	Deque( std::deque<int> deq );

#endif