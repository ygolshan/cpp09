/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:20:26 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/28 10:28:46 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange 
{
private:

    std::map<std::string, float> bitcoinDatabase;
    
public:

    void loadBitcoinDatabase(const std::string &fileName);
    float evaluate(const std::string &date, float value);

	BitcoinExchange(const BitcoinExchange &s_BitcoinExchange);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &s_BitcoinExchange);
    BitcoinExchange(const std::string &fileName);
	


};

#endif
