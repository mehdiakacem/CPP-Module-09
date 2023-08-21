/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:55:17 by makacem           #+#    #+#             */
/*   Updated: 2023/08/21 22:26:17 by makacem          ###   ########.fr       */
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
    std::cout << "Before:\t";
    ft_pring_vector(arguments);
    
    std::vector<int>::iterator it_arguments = arguments.begin();
    int last;
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
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
    }
    std::vector<int> first_vector;
    std::vector<int> second_vetor;

    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
    {
        first_vector.push_back(it->first);
        second_vetor.push_back(it->second);
    }
    mergeSort(second_vetor);
    for(std::vector<int>::iterator it_first = first_vector.begin(); it_first != first_vector.end(); it_first++)
    {
        int nbr = *it_first;
        std::vector<int>::iterator low = std::lower_bound(second_vetor.begin(), second_vetor.end(), nbr);
        second_vetor.insert(low, nbr);
    }
    if (arguments.size() % 2 == 1)
    {
        std::vector<int>::iterator it_last = arguments.end();
        it_last--;
        int last = *it_last;
        std::vector<int>::iterator low = std::lower_bound(second_vetor.begin(), second_vetor.end(), last);
        second_vetor.insert(low, last);
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::cout << "After:\t";
    ft_pring_vector(second_vetor);
    std::chrono::microseconds durationMicro = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time to process a range of "<< arguments.size() << " elements with std::vector:  " << durationMicro.count() << " us\n";
    
    //using a list//

    std::list<int> arguments_list;
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
            arguments_list.push_back(std::stoi(arg));
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: ";
        std::cerr << e.what() << '\n';
        return 1;
    }
    std::list<std::pair<int, int> > pairList;
    // Finish converting to list;
    std::list<int>::iterator it_argumentsList = arguments_list.begin();
    int last_inList;
    std::chrono::high_resolution_clock::time_point startinList = std::chrono::high_resolution_clock::now();
    while (it_argumentsList != arguments_list.end())
    {
        if (it_argumentsList + 1 != arguments_list.end())
        {
            int first = *it_argumentsList;
            int second = *(it_argumentsList + 1);
            pairVector.push_back(std::make_pair(first, second));
            it_argumentsList = it_argumentsList + 2;
        }
        else
        {
            last = *it_argumentsList;
            it_argumentsList++;            
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
    }
    std::vector<int> first_vector;
    std::vector<int> second_vetor;

    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
    {
        first_vector.push_back(it->first);
        second_vetor.push_back(it->second);
    }
    mergeSort(second_vetor);
    for(std::vector<int>::iterator it_first = first_vector.begin(); it_first != first_vector.end(); it_first++)
    {
        int nbr = *it_first;
        std::vector<int>::iterator low = std::lower_bound(second_vetor.begin(), second_vetor.end(), nbr);
        second_vetor.insert(low, nbr);
    }
    if (arguments.size() % 2 == 1)
    {
        std::vector<int>::iterator it_last = arguments.end();
        it_last--;
        int last = *it_last;
        std::vector<int>::iterator low = std::lower_bound(second_vetor.begin(), second_vetor.end(), last);
        second_vetor.insert(low, last);
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::cout << "After:\t";
    ft_pring_vector(second_vetor);
    std::chrono::microseconds durationMicro = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time to process a range of "<< arguments.size() << " elements with std::vector:  " << durationMicro.count() << " us\n";

    return 0;
}
