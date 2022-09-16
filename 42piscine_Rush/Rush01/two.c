/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseuka <minseuka@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:07:14 by minseuka          #+#    #+#             */
/*   Updated: 2022/05/29 23:12:26 by minseuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_board[5][5];
int			g_arr_check_row[5][5];
int			g_arr_check_col[5][5];
int			g_arr_rule_num[16];
int			*g_start_ptr[4];

int	func_next_num(int i)
{
	if (i == 0)
		return (5);
	else if (i == 1)
		return (-5);
	else if (i == 2)
		return (1);
	else if (i == 3)
		return (-1);
	return (0);
}

int	func_number(int i)
{
	if (i == 0 || i == 1)
		return (1);
	else if (i == 2 || i == 3)
		return (5);
	else
		return (0);
}

int	func_check_height(int *ptr, int k, int con)
{
	int	i;
	int	cnt;
	int	max_val;
	int	the_next;

	the_next = func_next_num(k);
	i = 0;
	cnt = 0;
	max_val = 0;
	while (++i < 5)
	{
		if (*ptr > max_val)
		{
			max_val = *ptr;
			++cnt;
		}
		ptr += the_next;
	}
	return (cnt == con);
}

int	func_check_rule(void)
{
	int	con;
	int	i;
	int	j;
	int	*ptr;

	con = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		ptr = g_start_ptr[i];
		while (j < 4)
		{
			if (!func_check_height(ptr, i, g_arr_rule_num[con++]))
				return (0);
			ptr += func_number(i);
			++j;
		}
		++i;
	}
	return (1);
}

void	make_arr_init(char *argv)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < 16)
	{
		g_arr_rule_num[k++] = argv[i] - '0';
		i += 2;
	}
}
