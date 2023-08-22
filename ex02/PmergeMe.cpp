/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:55:23 by makacem           #+#    #+#             */
/*   Updated: 2023/08/22 09:45:21 by makacem          ###   ########.fr       */
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

void    ft_pring_list(std::list<int> list)
{
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
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

void mergeSortList(std::list<int> &list)
{
    int length = list.size();
    if (length <= 1)
        return ;
        
    int middle = length / 2;
    std::list<int> leftList;
    std::list<int> rightList;

    int i = 0;//left

    std::list<int>::iterator it= list.begin();
    while(i < middle)
    {

        leftList.push_back(*it);
        it++;
        i++;
    }
    while (i < length)
    {
        rightList.push_back(*it);
        it++;
        i++;
    }
    mergeSortList(rightList);
    mergeSortList(leftList);
    
    mergeList(leftList, rightList, list);

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

void    mergeList(std::list<int> leftList, std::list<int> rightList, std::list<int> &list)
{
    std::list<int>::iterator it_right = rightList.begin();


    while (it_right != rightList.end())
    {
        int nbr = *it_right;
        std::list<int>::iterator low = std::lower_bound(leftList.begin(), leftList.end(), nbr);

        leftList.insert(low, nbr);
        
        it_right++;
    }
    std::list<int>::iterator it_list = list.begin();
    std::list<int>::iterator it_left = leftList.begin();

    while (it_left != leftList.end())
    {
        *it_list = *it_left;
        it_left++;
        it_list++;
    }

}