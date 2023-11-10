/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:26 by phudyka           #+#    #+#             */
/*   Updated: 2023/11/10 11:15:47 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

Fixed::Fixed(const int intNb)
{
	std::cout << "Int constructor called" << std::endl;
	raw = intNb << bit;
}

Fixed::Fixed(const float floatNb)
{
	std::cout << "Float constructor called" << std::endl;
	raw = roundf(floatNb * (1 << bit));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	return (this->raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

int	Fixed::toInt() const
{
	return (raw >> bit);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(raw) / (1 << bit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
