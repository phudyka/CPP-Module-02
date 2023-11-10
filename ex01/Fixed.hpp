/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:45 by phudyka           #+#    #+#             */
/*   Updated: 2023/11/10 11:17:03 by phudyka          ###   ########.fr       */
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

		friend	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif