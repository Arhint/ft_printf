/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:00:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/01/29 13:00:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int 	k;
	int 	m;
	char 		*s;
	unsigned short	d = 65535;

	
	setlocale(P_ALL, "en_US.UTF-8");
	s = "TESTTEST";
	
//	ft_printf("mine:{%-5d}\n", k);
//	printf("orig:{%-5d}\n", k);

//	ft_printf("mine:{%-10.5d}\n", k);
//	printf("orig:{%-10.5d}\n", k);
	
//	ft_printf("mine: {%5.d %5.0d}\n", 0, 0);
//	printf("orig: {%5.d %5.0d}\n", 0, 0);

//	ft_printf("mine:{%-5.2s}\n", s);
//	printf("orig:{%-5.2s}\n", s);
	
//	m = ft_printf("mine:{%.30S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	k =printf("orig:{%-15.4S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	
	m =ft_printf("{%30.4S}\n", L"我是一只猫。");
	k =   printf("{%30.4S}\n", L"我是一只猫。");
//
//	printf("k=%d\n", k);

//
	printf("m=%d\n", m);
	printf("k=%d\n", k);
	//ft_printf("%s", "test string");
	// printf("{%-20d}\n", 12);
	return (0);
}
