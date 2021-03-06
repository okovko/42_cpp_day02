/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:42:57 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/11 20:42:57 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>

#include <iostream>

#include "FixedPoint.hpp"

FixedPoint::FixedPoint() : value(0) {}
FixedPoint::FixedPoint(int const value) : value(value << binary_point) {}
FixedPoint::FixedPoint(double const value) : value(value * (1 << binary_point)) {}
FixedPoint::FixedPoint(FixedPoint const& fx) : value(fx.value) {}
FixedPoint::~FixedPoint() {}

FixedPoint&		FixedPoint::operator=(FixedPoint const& other)
{
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

int				FixedPoint::getRawBits() const
{
	return (this->value);
}

void			FixedPoint::setRawBits(int const raw)
{
	this->value = raw;
}

int				FixedPoint::toInt() const
{
	return (value >> 8);
}

float			FixedPoint::toFloat() const
{
	return ((float)value / (1 << binary_point));
}

std::ostream&	operator<<(std::ostream& os, FixedPoint const& fxp)
{
	os << fxp.toFloat();
	return (os);
}
