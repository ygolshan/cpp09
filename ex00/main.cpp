/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:21:30 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 10:55:39 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "BitcoinExchange.hpp"


bool checkDateValidity(const std::string& date) 
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) return false;

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }

    if (month == 2) {
        if (day > 29) return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) return false;
    }

    return true;
}


int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    BitcoinExchange btc("data.csv"); 
    std::ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." + std::string(argv[1]) + "\n";
        return 1;
    }

    std::string line;
    std::getline(inputFile, line);

	while (std::getline(inputFile, line))
     {
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, '|');
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());

        std::string valueStr;
        std::getline(ss, valueStr);
        char *end;
        float value = std::strtof(valueStr.c_str(), &end);
        if (!checkDateValidity(date)) {
            std::cerr << "Error: bad input => " << date << "\n";
            continue;
        }
        if (end == valueStr.c_str()) {
            std::cerr << "Invalid float format" << "\n";
            continue;
        }
		if (value < 0) {
			std::cerr << "Error: not a positive number." << "\n";
			continue;
		}
        if (value > 1000) {
            std::cerr << "Error: too large a number." << "\n";
            continue;
        }
        float result = btc.evaluate(date, value);
        std::cout << date << " => " << value << " = " << result << "\n";
    }

    return 0;
}
