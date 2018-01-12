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

#include "FixedPoint.hpp"

FixedPoint::FixedPoint() : value(0) {}
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
