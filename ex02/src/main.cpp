/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:28:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/04/15 15:58:45 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

#include "Array.hpp"

void testNewDelete()
{
	std::cout << "=== New and delete ===" << std::endl;
	Array<int> *arr = new Array<int>(10);
	for (unsigned int i = 0; i < arr->size(); ++i)
		(*arr)[i] = i;
	
	std::cout << "Array size: " << arr->size() << std::endl;
	std::cout << "Array contents: ";
	for (unsigned int i = 0; i < arr->size(); ++i)
		std::cout << (*arr)[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Deleting array..." << std::endl;
	delete arr;
	std::cout << std::endl;
}

void testEmptyArray()
{
	std::cout << "=== Empty array ===" << std::endl;
	Array<int> arr;
	std::cout << "Array size: " << arr.size() << std::endl;
}

void testArrayOfSize5()
{
	std::cout << "\n=== Array of size 5 ===" << std::endl;
	Array<int> arr5(5);
	std::cout << "Array size: " << arr5.size() << std::endl;
	for (unsigned int i = 0; i < arr5.size(); ++i)
		arr5[i] = i + 1;
	std::cout << "Array contents: ";
	for (unsigned int i = 0; i < arr5.size(); ++i)
		std::cout << arr5[i] << " ";
	std::cout << std::endl;
}

void testCopyConstructor()
{
	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> arr5(5);
	for (unsigned int i = 0; i < arr5.size(); ++i)
		arr5[i] = i + 1;

	Array<int> arrCopy(arr5);
	std::cout << "Copied array contents: ";
	for (unsigned int i = 0; i < arrCopy.size(); ++i)
		std::cout << arrCopy[i] << " ";
	std::cout << std::endl;

	int newValue = 999;
	arrCopy[0] = newValue;
	std::cout << "Original array after modifying copy: " << arr5[0] << " (should be 1)" << std::endl;
	std::cout << "Modified copy first element: " << arrCopy[0] << " (should NOT be " << newValue << ")";
	std::cout << std::endl;
}

void testCopyConstructorEdgeCases()
{
	std::cout << "\n=== Copy constructor edge cases ===" << std::endl;
	Array<int> emptyArr;
	Array<int> emptyArrCopy(emptyArr);
	std::cout << "Empty array copy size: " << emptyArrCopy.size() << std::endl;

	Array<int> arr5(5);
	for (unsigned int i = 0; i < arr5.size(); ++i)
		arr5[i] = i + 1;

	Array<int> selfCopy(arr5);
	std::cout << "Self copy array contents: ";
	for (unsigned int i = 0; i < selfCopy.size(); ++i)
		std::cout << selfCopy[i] << " ";
	std::cout << std::endl;

	selfCopy[0] = -1;
	selfCopy[2] = 42;
	selfCopy[3] = std::numeric_limits<int>::max();
	selfCopy[4] = std::numeric_limits<int>::min();

	std::cout << "Modified self copy contents: ";
	for (unsigned int i = 0; i < selfCopy.size(); ++i)
		std::cout << selfCopy[i] << " ";
	std::cout << std::endl;
}

void testAssignmentOperator()
{
	std::cout << "\n=== Assignment operator ===" << std::endl;
	Array<int> arr5(5);
	for (unsigned int i = 0; i < arr5.size(); ++i)
		arr5[i] = i + 1;

	Array<int> arrAssign;
	arrAssign = arr5;
	std::cout << "Assigned array contents: ";
	for (unsigned int i = 0; i < arrAssign.size(); ++i)
		std::cout << arrAssign[i] << " ";
	std::cout << std::endl;

	int newValue = 777;
	arrAssign[0] = newValue;
	std::cout << "Original array after modifying assigned array: " << arr5[0] << " (should be 1)" << std::endl;
	std::cout << "Modified assigned array first element: " << arrAssign[0] << " (should be " << newValue << ")";
	std::cout << std::endl;
}

void testOutOfRange()
{
	std::cout << "\n=== Out of range access ===" << std::endl;
	Array<int> arr5(5);
	try
	{
		std::cout << "Accessing index 10: ";
		std::cout << arr5[10] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testStringArray()
{
	std::cout << "\n=== Array of strings ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "!";

	std::cout << "String array contents: ";
	for (unsigned int i = 0; i < strArr.size(); ++i)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;
}

void testConstArray()
{
	std::cout << "\n=== Const array ===" << std::endl;
	Array<int> arr5(5);
	for (unsigned int i = 0; i < arr5.size(); ++i)
		arr5[i] = i + 1;

	const Array<int> constArr(arr5);
	std::cout << "Const array contents: ";
	for (unsigned int i = 0; i < constArr.size(); ++i)
		std::cout << constArr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	testNewDelete();
	testEmptyArray();
	testArrayOfSize5();
	testCopyConstructor();
	testCopyConstructorEdgeCases();
	testAssignmentOperator();
	testOutOfRange();
	testStringArray();
	testConstArray();
	
	return (0);
}
