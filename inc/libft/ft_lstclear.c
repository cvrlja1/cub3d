/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:47:09 by nicvrlja          #+#    #+#             */
/*   Updated: 2024/04/17 17:12:01 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	temp = NULL;
	while (*lst)
	{
		temp = (*lst);
		*lst = (*lst)->next;
		(*del)(temp->content);
		free(temp);
	}
	*lst = NULL;
}
