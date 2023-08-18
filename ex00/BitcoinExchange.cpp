/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:13:04 by makacem           #+#    #+#             */
/*   Updated: 2023/08/18 19:29:37 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int ft_check_year(std::string str_year)
{
    try
    {
        int year = std::stoi(str_year);
        if (year < 2009)
            return 1;
    }
    catch(const std::exception& e)
    {
        return 1;
    }
    
    return 0;
}

int ft_return_bad_input(std::string line)
{
    std::cout << "Eroor: bad input => " << line << std::endl;
    return 1;
}
