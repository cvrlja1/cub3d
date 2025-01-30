/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:04:53 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/01/30 13:40:41 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* --------> Includes <-------- */

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

/* --------> Structures <-------- */

typedef struct s_plr
{
	float	x;
	float	y;
	
} t_plr;

typedef struct s_data
{
	void	*mlx;
	void	*win;
} t_data;


/* --------> Functions <-------- */

void	print_error(char *msg);


#endif