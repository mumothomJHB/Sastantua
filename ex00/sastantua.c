/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumothom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:18:48 by mumothom          #+#    #+#             */
/*   Updated: 2020/07/17 12:21:39 by mumothom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int g_rows = 0;
int g_n = 0;
int g_n_uneven = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_calc_rows(int n)

	{
	int o;

	o = 0;
	g_rows = n * 3;
	while (o < n)
	{
		g_rows += o;
		o++;
	}
}

int		ft_row_width(int n, int row)
{
	int row_width;

	row_width = 3 + (row - 1) * 2;

	int add;
	int step;
	int step_init;

	int c = 1;
	int added = 0;
	add = 4;
	step = 3;
	step_init = 3;

	while (c <= row)
	{
		if (c == step + 1)
		{
			if (added != 0 && added % 2 == 0)
				add += 2;
			row_width += add;
			step += step_init + 1;
			step_init++;
			added++;
		}
		c++;
	}
	return (row_width);
}

void	row_with_door(int n, int cr, int o)
{
	int door_width = n;
	if (door_width % 2 == 0)
		door_width--;

	while (o < (ft_row_width(n, cr) / 2) - door_width)
	{
		ft_putchar('*');
		o++;
	}
	o = 0;
	while (o < door_width)
	{
		ft_putchar('|');
		o++;
	}
	o = 0;
	while (o < (ft_row_width(n, cr) / 2) - door_width)
	{
		ft_putchar('*');
		o++;
	}
}

void	ft_print(int cr, int spaces, int o, int n)
{
	int init_spaces = ft_row_width(n, g_rows) - ft_row_width(n, g_rows) / 2;
	while (cr <= g_rows)
	{
		o = 0;
		spaces = init_spaces - ((ft_row_width(n, cr) - ft_row_width(n, 1)) / 2) - 1;
		while (o < spaces)
		{
			ft_putchar(' ');
			o++;
		}
		ft_putchar('/');
		o = 0;
		if (cr == g_rows || spaces < g_n_uneven)
			row_with_door(n, cr, 0);
		else
			while (o < ft_row_width(n, cr) - 2)
			{
				ft_putchar('*');
				o++;
			}
		ft_putchar('\\');
		ft_putchar('\n');
		cr++;
	}
}

void	ft_sastantua(int n)
{
	g_n = n;
	if (g_n == 0)
		return ;

	if (g_n % 2 == 1)
		g_n_uneven = g_n + 1;
	else
		g_n_uneven = g_n;
	ft_calc_rows(n);
	ft_print(1,0,0,n);
}

int		main(void)
{
	ft_sastantua(2);
	return (0);
}


