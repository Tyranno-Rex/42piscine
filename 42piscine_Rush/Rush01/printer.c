/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseuka <minseuka@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:22:11 by minseuka          #+#    #+#             */
/*   Updated: 2022/05/29 23:23:25 by minseuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	func_writer(char c)
{
	write(1, &c, 1);
}

void	func_error_printer(void)
{
	write(1, "error\n", 6);
}
