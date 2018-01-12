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
	FixedPoint(FixedPoint const& fxp);
	~FixedPoint();

	FixedPoint&			operator=(FixedPoint const& other);
	bool				operator==(FixedPoint const& rhs);
	bool				operator!=(FixedPoint const& rhs);
	bool				operator<(FixedPoint const& rhs);
	bool				operator>(FixedPoint const& rhs);
	bool				operator<=(FixedPoint const& rhs);
	bool				operator>=(FixedPoint const& rhs);
	FixedPoint			operator+(FixedPoint const& rhs);
	FixedPoint			operator-(FixedPoint const& rhs);
	FixedPoint			operator*(FixedPoint const& rhs);
	FixedPoint			operator/(FixedPoint const& rhs);
	FixedPoint&			operator++();
	FixedPoint&			operator--();
	FixedPoint			operator++(int);
	FixedPoint			operator--(int);

	int					getRawBits() const;
	void				setRawBits(int const raw);
	int					toInt() const;
	float				toFloat() const;

	static FixedPoint&				min(FixedPoint& lhs, FixedPoint& rhs);
	static FixedPoint&				max(FixedPoint& lhs, FixedPoint& rhs);
	static FixedPoint const&		min(FixedPoint const& lhs, FixedPoint const& rhs);
	static FixedPoint const&		max(FixedPoint const& lhs, FixedPoint const& rhs);
};

std::ostream&			operator<<(std::ostream& os, FixedPoint const& fxp);

#endif
