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

#include "ft_eval_expr.hpp"
#include "FixedPoint.hpp"

int			main(int ac, char **av)
{
	if (2 == ac)
		std::cout << eval_expr(av[1]).toFloat() << std::endl;
	return (0);
}
