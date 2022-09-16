/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0ne.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:07:56 by yewpark           #+#    #+#             */
/*   Updated: 2022/05/29 23:38:14 by yewpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			g_arr_result[5][5];
extern int	g_arr_check_row[5][5];
extern int	g_arr_check_col[5][5];
extern int	g_arr_rule_num[16];
extern int	*g_start_ptr[4];

int		func_check_rule(void);
int		func_push_value(int r, int c);
void	func_writer(char c);

void	print_board(void)
{
	int	r;
	int	c;

	r = 0;
	while (++r < 5)
	{
		c = 0;
		while (++c < 4)
		{
			func_writer('0' + g_arr_result[r][c]);
			func_writer(' ');
		}
		func_writer('0' + g_arr_result[r][c]);
		func_writer('\n');
	}
}

int	func_push_check(int i, int j)
{
	int	the_num;

	the_num = 0;
	while (++the_num < 5)
	{
		if (g_arr_check_row[i][the_num] != 0
			|| g_arr_check_col[j][the_num] != 0)
			continue ;
		g_arr_check_row[i][the_num] = 1;
		g_arr_check_col[j][the_num] = 1;
		g_arr_result[i][j] = the_num;
		if (func_push_value(i, j + 1))
			return (1);
		g_arr_check_row[i][the_num] = 0;
		g_arr_check_col[j][the_num] = 0;
	}
	return (0);
}

int	func_push_value(int i, int j)
{
	if (i == 5)
	{
		if (func_check_rule())
		{
			print_board();
			return (1);
		}
		return (0);
	}
	if (j == 5)
		return (func_push_value(i + 1, 1));
	else
		return (func_push_check(i, j));
}

void	func_make_arr(void)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			g_arr_check_row[i][j] = 0;
			g_arr_check_col[i][j] = 0;
		}
	}
	g_start_ptr[0] = &g_arr_result[1][1];
	g_start_ptr[1] = &g_arr_result[4][1];
	g_start_ptr[2] = &g_arr_result[1][1];
	g_start_ptr[3] = &g_arr_result[1][4];
}

int	rush(void)
{
	func_make_arr();
	return (func_push_value(1, 1));
}
