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
FixedPoint::FixedPoint(FixedPoint const& fxp) : value(fxp.value) {}
FixedPoint::~FixedPoint() {}

FixedPoint&		FixedPoint::operator=(FixedPoint const& other)
{
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

bool			FixedPoint::operator==(FixedPoint const& rhs)
{
	return (this->value == rhs.value);
}

bool			FixedPoint::operator!=(FixedPoint const& rhs)
{
	return (!(*this == rhs));
}

bool			FixedPoint::operator>(FixedPoint const& rhs)
{
	return (this->value > rhs.value);
}

bool			FixedPoint::operator<(FixedPoint const& rhs)
{
	return (this->value < rhs.value);
}

bool			FixedPoint::operator>=(FixedPoint const& rhs)
{
	return (this->value >= rhs.value);
}

bool			FixedPoint::operator<=(FixedPoint const& rhs)
{
	return (this->value >= rhs.value);
}

FixedPoint		FixedPoint::operator+(FixedPoint const& rhs)
{
	return (FixedPoint(this->value + rhs.value));
}

FixedPoint		FixedPoint::operator-(FixedPoint const& rhs)
{
	return (FixedPoint(this->value - rhs.value));
}

FixedPoint		FixedPoint::operator*(FixedPoint const& rhs)
{
	FixedPoint	ret;

	ret = FixedPoint();
	ret.setRawBits((this->value * rhs.value) >> binary_point);
	return (ret);
}

FixedPoint		FixedPoint::operator/(FixedPoint const& rhs)
{
	FixedPoint	ret;

	ret = FixedPoint();
	ret.setRawBits(this->value / rhs.value);
	return (ret);
}

FixedPoint&		FixedPoint::operator++()
{
	this->value++;
	return (*this);
}

FixedPoint&		FixedPoint::operator--()
{
	this->value--;
	return (*this);
}

FixedPoint		FixedPoint::operator++(int)
{
	FixedPoint	ret;

	this->value++;
	ret.setRawBits(this->value);
	return (ret);
}

FixedPoint		FixedPoint::operator--(int)
{
	FixedPoint	ret;

	this->value--;
	ret.setRawBits(this->value);
	return (ret);
}

FixedPoint const&	FixedPoint::min(FixedPoint const& lhs, FixedPoint const& rhs)
{
	return (lhs.value < rhs.value ? lhs : rhs);
}

FixedPoint const&	FixedPoint::max(FixedPoint const& lhs, FixedPoint const& rhs)
{
	return (lhs.value > rhs.value ? lhs : rhs);
}

FixedPoint&	FixedPoint::min(FixedPoint& lhs, FixedPoint& rhs)
{
	return (lhs.value < rhs.value ? lhs : rhs);
}

FixedPoint&	FixedPoint::max(FixedPoint& lhs, FixedPoint& rhs)
{
	return (lhs.value > rhs.value ? lhs : rhs);
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
