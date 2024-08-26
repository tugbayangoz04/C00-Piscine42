/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyangoz <tyangoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:43:28 by tyangoz           #+#    #+#             */
/*   Updated: 2024/08/20 19:46:47 by tyangoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_nums(int *nums, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(nums[i] + '0');
		i++;
	}
}

void	ft_update_nums(int *nums, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		if (nums[i] < 9 - (n - 1 - i))
		{
			nums[i]++;
			i++;
			while (i < n)
			{
				nums[i] = nums[i - 1] + 1;
				i++;
			}
			return ;
		}
		i--;
	}
}

void	ft_print_combn(int n)
{
	int	nums[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		nums[i] = i;
		i++;
	}
	while (1)
	{
		ft_print_nums(nums, n);
		if (nums[0] == 10 - n)
			break ;
		write(1, ", ", 2);
		ft_update_nums(nums, n);
	}
}
