/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:55:23 by makacem           #+#    #+#             */
/*   Updated: 2023/08/21 18:04:26 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    ft_pring_vector(std::vector<int> vector)
{
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    merge(std::vector<int> leftVector, std::vector<int> rightVector, std::vector<int> &vector)
{
    std::vector<int>::iterator it_right = rightVector.begin();


    while (it_right != rightVector.end())
    {
        int nbr = *it_right;
        std::vector<int>::iterator low = std::lower_bound(leftVector.begin(), leftVector.end(), nbr);

        leftVector.insert(low, nbr);
        
        it_right++;
    }
    std::vector<int>::iterator it_vector = vector.begin();
    std::vector<int>::iterator it_left = leftVector.begin();

    while (it_left != leftVector.end())
    {
        *it_vector = *it_left;
        it_left++;
        it_vector++;
    }

}


void mergeSort(std::vector<int> &vector)
{
    int length = vector.size();
    if (length <= 1)
        return ;
        
    int middle = length / 2;
    std::vector<int> leftVector(middle);
    std::vector<int> rightVector(length - middle);

    int i = 0;//left
    int j = 0;//right

    for(; i <length; i++)
    {
        if (i < middle)
            leftVector[i] = vector[i];
        else
        {
            rightVector[j] = vector[i];
            j++;
        }
    }

    mergeSort(rightVector);
    mergeSort(leftVector);
    
    merge(leftVector, rightVector, vector);

}

int ft_isnotnbr(std::string argument)
{
    std::string::iterator it = argument.begin();

    while (it != argument.end())
    {
        if (!isdigit(*it))
            return 1;
        it++;
    }
    return 0;
}

int ft_invalid_arguments(void)
{
    std::cout << "Invalid Arguments\n";
    return 1;
}