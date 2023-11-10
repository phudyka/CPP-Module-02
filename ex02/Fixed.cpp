/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:26 by phudyka           #+#    #+#             */
/*   Updated: 2023/11/10 11:07:26 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : raw(0) {}

Fixed::Fixed(const Fixed &other) : raw(other.getRawBits()) {}

Fixed::Fixed(const int intNb) : raw(intNb << bit) {}

Fixed::Fixed(const float floatNb) : raw(roundf(floatNb * (1 << bit))) {}

Fixed::~Fixed() {}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
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

bool	Fixed::operator>(const Fixed &other) const
{
    return (this->raw > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
    return (this->raw < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
    return (this->raw >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
    return (this->raw <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
    return (this->raw == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
    return (this->raw != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
    ++raw;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++raw;
    return (temp);
}

Fixed &Fixed::operator--()
{
    --raw;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --raw;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}