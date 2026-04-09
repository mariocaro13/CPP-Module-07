/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:32:35 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/04/09 13:32:42 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <iostream>

template <typename T>
void print(T const &x)
{
	std::cout << x << " ";
}

template <typename T>
void printConst(T const &x)
{
    std::cout << "[const] " << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	x++;
}

template <typename T>
void testNumericArray(T *array, size_t length)
{
	std::cout << "Original array: ";
	::iter(array, length, ::print<T>);
	std::cout << std::endl;

	std::cout << "Incrementing array..." << std::endl;
	::iter(array, length, ::increment<T>);

	std::cout << "Modified array: ";
	::iter(array, length, ::print<T>);
	std::cout << std::endl;

	std::cout << std::endl;
}
