/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:16 by josfelip          #+#    #+#             */
/*   Updated: 2023/10/19 12:23:08 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10) || 4 == ac && !ft_strncmp(av[1], "julia", 5))//TODO
	{
		//Prompt correct, kick off the application
	}
	else
	{
		putrstr_fd(ERROR_MESSAGE, STDERR_FILENO); //TODO
		exit(EXIT_FAILURE);
	}
	return (0);
}