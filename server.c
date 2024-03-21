/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:01:31 by sozdamar          #+#    #+#             */
/*   Updated: 2024/03/22 15:01:33 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int signal)
{
	static char c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

//consider void main!!
int main(void)
{
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	ft_printf("Server pid: %d\n", getpid());
	while (1)
		pause();
}