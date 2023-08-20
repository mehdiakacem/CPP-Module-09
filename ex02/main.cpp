/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:55:17 by makacem           #+#    #+#             */
/*   Updated: 2023/08/20 20:13:07 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    std::vector<int> arguments;
    std::string arg;

    try
    {
        if (argc < 2)
            return (ft_invalid_arguments());
        for (int i = 1; i < argc; i++)
        {
            arg = *(argv + i);
            if (ft_isnotnbr(arg))
                return (ft_invalid_arguments());
            arguments.push_back(std::stoi(arg));
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: ";
        std::cerr << e.what() << '\n';
        return 1;
    }
    std::vector<std::pair<int, int> > pairVector;

    std::vector<int>::iterator it_arguments = arguments.begin();
    int last;
    
    while (it_arguments != arguments.end())
    {
        if (it_arguments + 1 != arguments.end())
        {
            int first = *it_arguments;
            int second = *(it_arguments + 1);

            pairVector.push_back(std::make_pair(first, second));

            it_arguments = it_arguments + 2;
        }
        else
        {
            last = *it_arguments;
            it_arguments++;            
        }
    }
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
    {
        if (it->first > it->second)
        {
            int temp;
            temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
        std::cout << it->first << " " << it->second << std::endl;
    }
    std::cout << std::endl;
    std::vector<int> first_vector;
    std::vector<int> second_vetor;

    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
    {
        first_vector.push_back(it->first);
        second_vetor.push_back(it->second);
    }
    std::sort(first_vector.begin(), first_vector.end());
    std::sort(second_vetor.begin(), second_vetor.end());
    for (std::vector<int>::iterator it = first_vector.begin(); it != first_vector.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (std::vector<int>::iterator it = second_vetor.begin(); it != second_vetor.end(); it++)
    {
        std::cout << *it << " ";
    }
    
    return 0;
}
