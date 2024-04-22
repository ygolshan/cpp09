/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:20:15 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 11:17:19 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const BitcoinExchange &s_BitcoinExchange)
{
    this->bitcoinDatabase = s_BitcoinExchange.bitcoinDatabase;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &s_BitcoinExchange) 
{
    if (this != &s_BitcoinExchange) 
    {
        this->bitcoinDatabase = s_BitcoinExchange.bitcoinDatabase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const std::string &fileName) 
{
    loadBitcoinDatabase(fileName);
}

void BitcoinExchange::loadBitcoinDatabase(const std::string &fileName) 
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open()) 
    {
        throw std::runtime_error("Could not open file " + fileName);
    }
    std::string line;
	while (std::getline(file, line)) 
    {
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, ',');
		std::string priceStr;
		std::getline(ss, priceStr);
		std::stringstream ssPrice(priceStr);
		float price;
		ssPrice >> price;

		bitcoinDatabase[date] = price;
	}

}

float BitcoinExchange::evaluate(const std::string &date, float value) 
{
    std::map<std::string, float>::iterator it = bitcoinDatabase.lower_bound(date);
    if (it == bitcoinDatabase.end() || it->first != date) {
        if (it == bitcoinDatabase.begin()) {
            throw std::runtime_error("No date in database is earlier than: " + date);
        }
        --it;
    }

    float bitcoinPrice = it->second;
    return value * bitcoinPrice;
}
