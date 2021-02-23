/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:29:34 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/22 12:13:40 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int a;
	int nb;
	int nega;

	a = 0;
	nb = 0;
	nega = 1;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v' ||
			str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			nega *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		nb = nb * 10 + str[a] - '0';
		a++;
	}
	return (nb * nega);
}
