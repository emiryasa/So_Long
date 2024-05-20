/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:39:37 by eyasa             #+#    #+#             */
/*   Updated: 2023/12/11 18:47:13 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	if (!*lst)
		return ;
	while (*lst)
	{
		last = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = last;
	}
	*lst = NULL;
}
