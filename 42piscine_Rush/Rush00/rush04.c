/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:50:26 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/22 16:30:53 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char *chr);

void	func_f(int n1)
{
	int		the_garol;

	the_garol = 0;
	while (the_garol < n1)
	{
		if (the_garol == 0)
			ft_putchar("A");
		else if (the_garol == n1 - 1)
			ft_putchar("C");
		else
			ft_putchar("B");
		the_garol++;
	}
	ft_putchar("\n");
}

void	func_l(int n1)
{
	int	the_garol;

	the_garol = 0;
	while (the_garol < n1)
	{
		if (the_garol == 0)
			ft_putchar("C");
		else if (the_garol == n1 - 1)
			ft_putchar("A");
		else
			ft_putchar("B");
		the_garol++;
	}
	ft_putchar("\n");
}

void	func_mid(int the_garol)
{
	int		the_n;

	the_n = 0;
	while (the_n < the_garol)
	{
		if (the_n == 0 || the_n == the_garol - 1)
			ft_putchar("B");
		else
			ft_putchar(" ");
		the_n++;
	}
	ft_putchar("\n");
}

void	rush(int n1, int n2)
{
	int		the_hang;

	the_hang = 0;
	if (n1 <= 0 || n2 <= 0)
	{
		return ;
	}
	while (the_hang < n2)
	{
		if (the_hang == 0)
			func_f(n1);
		else if (the_hang == n2 - 1)
			func_l(n1);
		else
			func_mid(n1);
		the_hang++;
	}
}
