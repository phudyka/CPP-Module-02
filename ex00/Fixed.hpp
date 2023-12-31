/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:45 by phudyka           #+#    #+#             */
/*   Updated: 2023/11/09 11:04:32 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					raw;
		static const int	bit = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif