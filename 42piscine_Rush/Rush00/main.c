/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:23:10 by chanheki, k       #+#    #+#             */
/*   Updated: 2022/05/21 21:51:38 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int n1, int n2);

int	str2int(char *str)
{
	int	result;
	int	puiss;

	result = 0;
	puiss = 1;
	if (*str == '-')
	{
		puiss = puiss * -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		result = (result * 10) + ((*str) - '0');
		str++;
	}
	return (result * puiss);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc == 3)
	{
		x = str2int(&*argv[1]);
		y = str2int(&*argv[2]);
		rush(x, y);
	}
	return (0);
}
