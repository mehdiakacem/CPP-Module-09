/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:07:24 by makacem           #+#    #+#             */
/*   Updated: 2023/08/20 11:18:07 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Invalid arguments\n";
        return 1;
    }

    std::string expression = *(argv + 1);
    std::stack<int> stack;
    for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
    {
        char c = *it;
        if (isdigit(c))
        {
            stack.push(c - 48);
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error\n";
                return 1;
            }
            int second_element = stack.top();
            stack.pop();
            int first_element = stack.top();
            stack.pop();
            if (c == '+')
                stack.push(first_element + second_element);
            else if (c == '-')
                stack.push(first_element - second_element);
            else if (c == '/')
                stack.push(first_element / second_element);
            else if (c == '*')
                stack.push(first_element * second_element);
        }
        else if (c == ' ')
            continue;
        else
        {
            std::cout << "Error\n";
            return 1;
        }
    }
    if (stack.size() > 1)
    {
        std::cout << "Error\n";
        return 1;
    }
    
    std::cout << stack.top() << std::endl;

    return 0;
}