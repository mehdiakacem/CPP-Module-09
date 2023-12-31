/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:55:27 by makacem           #+#    #+#             */
/*   Updated: 2023/08/22 09:45:35 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

#define PMERGEME_HPP
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <chrono>
#include <list>

int ft_isnotnbr(std::string argument);
int ft_invalid_arguments(void);
void    ft_pring_vector(std::vector<int> vector);
void    merge(std::vector<int> leftVector, std::vector<int> rightVector, std::vector<int> &vector);
void mergeSort(std::vector<int> &vector);
void mergeSortList(std::list<int> &list);
void    ft_pring_list(std::list<int> list);
void    mergeList(std::list<int> leftList, std::list<int> rightList, std::list<int> &list);


#endif