/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:56:11 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/12 09:26:34 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "FixedPoint.hpp"
#include "ft_eval_expr.hpp"

FixedPoint		eval_expr(char *str)
{
	char	*head;
	char	*stripped;
	FixedPoint		eval;

	stripped = strip_non_symbols(str);
	head = stripped;
	eval = parse_sums(&stripped);
	return (eval);
}

FixedPoint		parse_subexpr(char **expr)
{
	FixedPoint		num;

	if ('(' == **expr)
		*expr += 1;
	num = parse_sums(expr);
	return (num);
}

FixedPoint		parse_num(char **expr)
{
	FixedPoint		num;
	char	symbol;

	symbol = **expr;
	if (!ISDIGIT(symbol) && '-' != symbol && '+' != symbol)
		return (parse_subexpr(expr));
	num = atoi(*expr);
	*expr = next_symbol(*expr);
	return (num);
}

FixedPoint		parse_factors(char **expr)
{
	FixedPoint		num1;
	FixedPoint		num2;
	char	symbol;

	num1 = parse_num(expr);
	while ((symbol = **expr))
	{
		if (!ISOP_FACTOR(symbol))
			return (num1);
		*expr += 1;
		num2 = parse_num(expr);
		if (symbol == '/')
			num1 = num1 / num2;
		else if (symbol == '*')
			num1 = num1 * num2;
	}
	return (num1);
}

FixedPoint		parse_sums(char **expr)
{
	FixedPoint		num1;
	FixedPoint		num2;
	char	symbol;

	num1 = parse_factors(expr);
	while ((symbol = **expr))
	{
		if (!ISOP_SUM(symbol))
		{
			if (')' == symbol)
				*expr += 1;
			return (num1);
		}
		*expr += 1;
		num2 = parse_factors(expr);
		if (symbol == '-')
			num1 = num1 - num2;
		else
			num1 = num1 + num2;
	}
	return (num1);
}

char	*next_symbol(char *str)
{
	char	cc;

	if (str == NULL)
		return (NULL);
	str += *str != '\0';
	while ((cc = *str) && ISDIGIT(cc))
		str++;
	return (str);
}

char	*strip_non_symbols(char *str)
{
	int		symbol_count;

	if (str == NULL)
		return (NULL);
	symbol_count = str_count_if(str, is_symbol);
	return (str_cpy_if(str, str, is_symbol));
}

char	*str_cpy_if(char *dst, char *src, int (*ff)(char))
{
	char	cc;
	char	*head;

	if (dst == NULL || src == NULL || ff == NULL)
		return (NULL);
	head = dst;
	while ((cc = *src++))
		if (ff(cc))
			*dst++ = cc;
	*dst = '\0';
	return (head);
}

int		str_count_if(char *str, int (*ff)(char))
{
	char	cc;
	int		count;

	if (str == NULL)
		return (0);
	count = 0;
	while ((cc = *str++))
		count += ff(cc);
	return (count);
}

int		is_symbol(char cc)
{
	return (ISSYMBOL(cc));
}
