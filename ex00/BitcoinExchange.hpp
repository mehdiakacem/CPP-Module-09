/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:13:01 by makacem           #+#    #+#             */
/*   Updated: 2023/08/19 15:01:58 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

int ft_return_bad_input(std::string line);
int ft_check_year(std::string str_year);
int ft_check_delimiter(std::string delimiter);
int ft_check_month(std::string str_month);
int ft_check_day(std::string str_day);
int ft_check_date_format(std::string date);
int ft_check_separator(std::string seprator);
int ft_check_value(std::string str_value, std::string line);
int ft_check_format(std::string line);

#endif