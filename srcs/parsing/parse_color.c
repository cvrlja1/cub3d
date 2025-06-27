/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluegham <tluegham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:34:54 by nightcore         #+#    #+#             */
/*   Updated: 2025/06/27 16:43:03 by tluegham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_rgb_nbr(int fd, char *buf, int *bytes_read)
{
	char	nbr[4];
	int		j;
	int		rgb_nbr;

	j = 0;
	ft_memset((void *) nbr, 0, 4 * sizeof(char));
	while (j < 3)
	{
		if (j != 0 && (*buf == ',' || is_whitespace(*buf)))
			break ;
		if (!ft_isdigit(*buf))
			return (print_error(CLR_RANGE_ERR), -1);
		nbr[j] = *buf;
		*bytes_read += read(fd, buf, 1);
		j++;
	}
	rgb_nbr = ft_atoi(nbr);
	if (rgb_nbr > 255 || rgb_nbr < 0)
		return (print_error(CLR_RANGE_ERR), -1);
	return (rgb_nbr);
}

static bool	try_between_read(int fd, char *buf, int *bytes_read)
{
	int	read_amount;

	while (is_whitespace(*buf))
	{
		read_amount = read(fd, buf, 1);
		if (read_amount < 0)
			return (false);
		*bytes_read += read_amount;
	}
	if (*buf != ',')
		return (print_error(CLR_COMMA_ERR), false);
	read_amount = read(fd, buf, 1);
	if (read_amount < 0)
		return (false);
	*bytes_read += read_amount;
	while (is_whitespace(*buf))
	{
		read_amount = read(fd, buf, 1);
		if (read_amount < 0)
			return (false);
		*bytes_read += read_amount;
	}
	return (true);
}

bool	try_parse_color(t_id_info *info, int fd, char *buf, int *bytes_read)
{
	int	i;
	int	rgb_value;

	i = 0;
	*(int *) info->ptr_ref = 0;
	while (i < 3)
	{
		rgb_value = get_rgb_nbr(fd, buf, bytes_read);
		if (rgb_value < 0)
			return (false);
		*(int *) info->ptr_ref |= rgb_value << ((2 - i) * 8);
		if (i == 2)
			return (true);
		if (!try_between_read(fd, buf, bytes_read))
			return (false);
		i++;
	}
	return (true);
}
