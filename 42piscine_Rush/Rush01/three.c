/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:09:43 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/29 23:34:47 by yewpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		make_arr_init(char *cond);
int		rush(void);
void	func_error_printer(void);

int	func_check_error_argv_two(char **argv)
{
	int		i;
	int		v[5];

	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[4] = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '1')
			v[1]++;
		else if (argv[1][i] == '2')
			v[2]++;
		else if (argv[1][i] == '3')
			v[3]++;
		else if (argv[1][i] == '4')
			v[4]++;
		i++;
		if (v[1] > 4 || v[2] > 8 || v[3] > 8 || v[4] > 4)
		{
			func_error_printer();
			return (0);
		}
	}
	return (1);
}

int	func_check_error_argv_three(char *argv, int i)
{
	int		cnt;

	cnt = 0;
	while (cnt < i)
	{
		if ((cnt % 2 == 0) && !(argv[cnt] == '1' || argv[cnt] == '2' \
			|| argv[cnt] == '3' || argv[cnt] == '4'))
		{
			func_error_printer();
			return (0);
		}
		else if ((cnt % 2 == 1) && (argv[cnt] != ' '))
		{
			func_error_printer();
			return (0);
		}
		cnt++;
	}
	return (1);
}

int	func_check_error_argv_one(char **argv)
{
	int		i;
	int		cnt;

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (i != 31)
	{
		func_error_printer();
		return (0);
	}
	if (func_check_error_argv_three(argv[1], i) != 0)
		func_error_printer();
	if (func_check_error_argv_two(argv) == 1)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "Error\n", 6);
	if (func_check_error_argv_one(argv) != 1)
		return (0);
	make_arr_init(argv[1]);
	rush();
	return (0);
}
