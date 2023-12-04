/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:37 by phudyka           #+#    #+#             */
/*   Updated: 2023/12/04 15:14:53 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "\nTESTS:\n";
	Fixed c = a;
	std::cout << Fixed::min(c, b) << std::endl;
	std::cout << b / Fixed(2) << std::endl;
	std::cout << b + Fixed(-3.14f) << std::endl;
	std::cout << b - Fixed(18) << std::endl;
	std::cout << (c != a) << std::endl;
	std::cout << (c == a) << std::endl;
	return 0;
}