/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:55:23 by makacem           #+#    #+#             */
/*   Updated: 2023/08/20 14:45:49 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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