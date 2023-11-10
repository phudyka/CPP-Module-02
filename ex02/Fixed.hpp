/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:45 by phudyka           #+#    #+#             */
/*   Updated: 2023/11/10 10:34:55 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed
{
	private:
		int					raw;
		static const int	bit = 8;
	public:
		Fixed();
		Fixed(const int intNb);
		Fixed(const float floatNb);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;

		bool	operator>(const Fixed &other) const;
    	bool	operator<(const Fixed &other) const;
    	bool	operator>=(const Fixed &other) const;
    	bool	operator<=(const Fixed &other) const;
    	bool	operator==(const Fixed &other) const;
    	bool 	operator!=(const Fixed &other) const;

    	Fixed	operator+(const Fixed &other) const;
    	Fixed	operator-(const Fixed &other) const;
    	Fixed	operator*(const Fixed &other) const;
    	Fixed	operator/(const Fixed &other) const;

    	Fixed	&operator++();
    	Fixed	operator++(int);
    	Fixed	&operator--();
    	Fixed	operator--(int);

	    static Fixed &min(Fixed &a, Fixed &b);
	    static const Fixed &min(const Fixed &a, const Fixed &b);
	    static Fixed &max(Fixed &a, Fixed &b);
	    static const Fixed &max(const Fixed &a, const Fixed &b);

		friend	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif