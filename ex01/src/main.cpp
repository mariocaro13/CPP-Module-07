/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:28:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/04/09 13:42:04 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "main.hpp"

int main()
{
	int arr[] = {0, 1, 2, 3, 4, INT_MAX};
	testNumericArray(arr, 10);

	unsigned int unsignedArr[] = {0, 1, 2, 3, 4, UINT_MAX};
	testNumericArray(unsignedArr, 6);

	std::string strArr[] = {"Hello", "World", "!"};
	::iter(strArr, 3, ::print<std::string>);
	std::cout << std::endl << std::endl;

	const int constArr[] = {10, 20, 30, 40, 50};
	::iter(constArr, 5, ::printConst<int>);
	std::cout << std::endl;

	return (0);
}
