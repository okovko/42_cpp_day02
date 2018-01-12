/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:51:39 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/11 20:51:39 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "FixedPoint.hpp"

int			main()
{
	FixedPoint		aa;
	FixedPoint		bb(FixedPoint(5.05f) * FixedPoint(2));

	std::cout << aa << std::endl;
	std::cout << ++aa << std::endl;
	std::cout << aa << std::endl;
	std::cout << aa++ << std::endl;
	std::cout << aa << std::endl;

	std::cout << bb << std::endl;

	std::cout << FixedPoint::max(aa, bb) << std::endl;

	return (0);
}
