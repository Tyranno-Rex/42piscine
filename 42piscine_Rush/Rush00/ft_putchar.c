/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:23:07 by chanheki, kangjkim, eunjeong             */
/*   Updated: 2022/05/21 01:23:07 by chanheki, kangjkim, eunjeong             */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *chr)
{
	write(1, chr, 1);
}
