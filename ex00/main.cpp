/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:12:56 by makacem           #+#    #+#             */
/*   Updated: 2023/08/18 19:33:32 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int ft_check_delimiter(std::string delimiter)
{
    if (delimiter.compare("-") != 0)
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


    
    return 0;
}

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
        if (ft_check_date_format(date)== 0)
        {
            value = line.substr(13);
        }
        else
            return(ft_return_bad_input(line));
    }
    else
        return(ft_return_bad_input(line));
    
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }

    std::fstream InputFile;
    InputFile.open(*(argv + 1), std::ios::in);
    if (!InputFile)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    
    std::string line;
    std::getline(InputFile, line);
    while (std::getline(InputFile, line))
    {
        if (ft_check_format(line) == 0)
        {
            std::cout << line << std::endl;
        }
        
    }
    
    InputFile.close();
    
    return 0;
}