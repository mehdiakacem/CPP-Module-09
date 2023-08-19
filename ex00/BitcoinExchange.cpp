/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:13:04 by makacem           #+#    #+#             */
/*   Updated: 2023/08/19 11:46:28 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int ft_check_format(std::string line)
{
    std::string date;
    std::string separator;
    std::string value;

    if (line.size() == 0)
        return 0;
    if (line.size() > 13)
    {
        date = line.substr(0, 10);
        separator = line.substr(10, 3);
        if (ft_check_date_format(date)== 0 && ft_check_separator(separator) == 0)
        {
            value = line.substr(13);
            if (ft_check_value(value, line) != 0)
                return(1);
        }
        else
            return(ft_return_bad_input(line));
    }
    else
        return(ft_return_bad_input(line));
    
    return 0;
}

int ft_check_value(std::string str_value, std::string line)
{
    if (str_value[0] == '-')
    {
        std::cout << "Error: not a positive number.\n";
        return 1;
    }

    std::size_t found;
    unsigned long i = 0;
    found = str_value.find('.');
    if (found != std::string::npos)
    {
        while (i < found)
        {
            if(!isdigit(str_value[i]))
                return (ft_return_bad_input(line));
            i++;
        }
        i = found + 1;
        while (i < str_value.length())
        {
            if(!isdigit(str_value[i]))
                return (ft_return_bad_input(line));
            i++;
        }
        if (found > 3)
        {
            std::cout << "Error: too large a number.\n";
            return 1;
        }
        std::stof(str_value);
    }
    else
    {
        while (i < str_value.length())
        {
            if(!isdigit(str_value[i]))
                return (ft_return_bad_input(line));
            i++;
        }
        if (str_value.length() >= 4 && str_value.compare("1000") != 0)
        {
            std::cout << "Error: too large a number.\n";
            return 1;
        }
    }
    return 0;
}

int ft_check_separator(std::string seprator)
{
    if (seprator.compare(" | ")!= 0)
        return 1;
    return 0;
}

int ft_check_date_format(std::string date)
{
    std::string year = date.substr(0, 4);
    std::string fdelimiter = date.substr (4, 1); 
    std::string month = date.substr(5, 2);
    std::string sdelimiter = date.substr (7, 1);    
    std::string day = date.substr(8);

    if (ft_check_year(year) == 1)
        return 1;
    if (ft_check_delimiter(fdelimiter) == 1)
        return 1;
    if (ft_check_month(month) == 1)
        return 1;
    if (ft_check_delimiter(sdelimiter) == 1)
        return 1;
    if (ft_check_day(day) == 1)
        return 1;

    return 0;
}

int ft_check_day(std::string str_day)
{
    if (isdigit(str_day[0]) == 0 || isdigit(str_day[1]) == 0)
        return 1;

    int day = std::stoi(str_day);
    if (day <= 0 || day > 31)
        return 1;
    return 0;
}

int ft_check_month(std::string str_month)
{
    if (isdigit(str_month[0]) == 0 || isdigit(str_month[1]) == 0)
        return 1;

    int month = std::stoi(str_month);
    if (month <= 0 || month > 12)
        return 1;
    return 0;
}

int ft_check_delimiter(std::string delimiter)
{
    if (delimiter.compare("-") != 0)
        return 1;
    return 0;
}

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
