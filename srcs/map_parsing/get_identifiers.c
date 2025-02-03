/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightcore <nightcore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:37 by nightcore         #+#    #+#             */
/*   Updated: 2025/02/03 18:49:21 by nightcore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_valid_id_info(t_id_info *info)
{
	if (info->id == NO_ID)
		return (false);
	if (info->ptr_ref == NULL)
		return (false);
	return (true);
}

static bool try_get_id_pointer_ref(t_textures *t, t_id_info *info)
{
	if (info->id == NO)
	{
	printf("no_path: \'%p\'\n", t->no_path);
	printf("is the no_path NULL? %s\n", t->no_path == NULL ? "true" : "false");
		info->ptr_ref = (void *) &t->no_path;
	}
	else if (info->id == EA)
		info->ptr_ref = (void *) &t->ea_path;
	else if (info->id == SO)
		info->ptr_ref = (void *) &t->so_path;
	else if (info->id == WE)
		info->ptr_ref = (void *) &t->we_path;
	else
	{
		if (info->id == C)
			info->ptr_ref = (void *) &t->ceil_clr;
		else if (info->id == F)
			info->ptr_ref = (void *) &t->flr_clr;
		if (*(int *) info->ptr_ref != -1)
			return (print_error(UPPER_ID_ERR), false);
		return (true);
	}
	printf("ptr_ref: \'%p\'\n", *(char **) info->ptr_ref);
	printf("ptr_ref: \'%p\'\n", info->ptr_ref);
	printf("ptr_ref: \'%p\'\n", (char **) info->ptr_ref);
	printf("is the ptr_ref NULL? %s\n", *((char **) info->ptr_ref) == NULL ? "true" : "false");
	if (*((char **) info->ptr_ref) != NULL)
		return (print_error(UPPER_ID_ERR), false);
	return (true);
}

static t_id_info	get_identifier_infos(t_textures *t, char *key)
{
	t_id_info	id_info;

	if (strcmp(key, NO_IDENTIFIER) == 0)
		id_info.id = NO;
	else if (strcmp(key, EA_IDENTIFIER) == 0)
		id_info.id = EA;
	else if (strcmp(key, SO_IDENTIFIER) == 0)
		id_info.id = SO;
	else if (strcmp(key, WE_IDENTIFIER) == 0)
		id_info.id = WE;
	else if (strcmp(key, C_IDENTIFIER) == 0)
		id_info.id = C;
	else if (strcmp(key, F_IDENTIFIER) == 0)
		id_info.id = F;
	else
		return (print_error(INVALID_ID_ERR), (t_id_info){.id = NO_ID, .ptr_ref = NULL});
	if (!try_get_id_pointer_ref(t, &id_info))
		return ((t_id_info){.id = NO_ID, .ptr_ref = NULL});
	return (id_info);
}

t_id_info	find_id_info(t_textures *t, char *buf, int fd, int *bytes_read)
{
	t_id_info	id_info;
	char		identifier[3];

	identifier[0] = *buf;
	identifier[1] = '\0';
	identifier[2] = '\0';
	*bytes_read += read(fd, buf, 1);
	if (!is_whitespace(*buf))
	{
		identifier[1] = *buf;
		*bytes_read += read(fd, buf, 1);
	}
	id_info = get_identifier_infos(t, identifier);
	if (!is_valid_id_info(&id_info))
		return ((t_id_info){.id = NO_ID, .ptr_ref = NULL});
	return (id_info);
}
