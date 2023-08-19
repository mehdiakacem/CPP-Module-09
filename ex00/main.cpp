/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:12:56 by makacem           #+#    #+#             */
/*   Updated: 2023/08/19 19:08:32 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }

    std::fstream DataFile;
    DataFile.open("data.csv", std::ios::in);
    if (!DataFile)
    {
        std::cout << "Error: could not open datafile.\n";
        return 1;
    }
    std::string line;
    std::map<std::string, float> map;
    std::getline(DataFile, line);
    std::string date;
    float exchange_rate;
    while (std::getline(DataFile, line))
    {
        date = line.substr(0, 10);
        exchange_rate = std::stof(line.substr(11));
        map[date] = exchange_rate;
    }
 
    std::fstream InputFile;
    InputFile.open(*(argv + 1), std::ios::in);
    if (!InputFile)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }

    std::map<std::string, float>::iterator it;
    std::getline(InputFile, line);
    float value;
    while (std::getline(InputFile, line))
    {
        if (ft_check_format(line) == 0)
        {
            date = line.substr(0, 10);
            value = std::stof(line.substr(13));
            it = map.find(date);
            if (it != map.end())
                std::cout << date << " => " << value << " = " << value * map.find(date)->second << std::endl;
            else
            {
                it = map.lower_bound(date);
                it--;
                std::cout<<"******"<< it->first <<std::endl;
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;
            }
        }
        
    }
    
    InputFile.close();
    DataFile.close();
    
    return 0;
}