/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:36:03 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/11 20:40:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

#include <iostream>

class	FixedPoint
{
	int					value;
	static const int	binary_point = 8;
public:
	FixedPoint();
	FixedPoint(int const value);
	FixedPoint(double const value);
	FixedPoint(FixedPoint const& fx);
	~FixedPoint();

	FixedPoint&			operator=(FixedPoint const& other);
	int					getRawBits() const;
	void				setRawBits(int const raw);
	int					toInt() const;
	float				toFloat() const;
};

std::ostream&			operator<<(std::ostream& os, FixedPoint const& fxp);

#endif
