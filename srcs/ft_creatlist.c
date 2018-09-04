/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:11:10 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/08 11:34:32 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_arg	*ft_creatvar(char *str, t_arg *back)
{
	t_arg		*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg) * 1)))
		return (NULL);
	new->curse = 0;
	new->select = 0;
	if (!(new->argu = ft_strdup(str)))
	{
		free(new);
		return (NULL);
	}
	new->back = back;
	new->next = NULL;
	new->end = 0;
	return (new);
}

static void		ft_dellist_ifail(t_arg *begin_list)
{
	t_arg		*tmp;

	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp->argu);
		free(tmp);
	}
}

t_arg			*ft_creatlist(char **argv)
{
	t_arg		*begin_list;
	t_arg		*tmp;
	int			i;

	i = 1;
	if (!(begin_list = ft_creatvar(argv[i++], NULL)))
		return (NULL);
	tmp = begin_list;
	while (argv[i])
	{
		if (!(tmp->next = ft_creatvar(argv[i], tmp)))
		{
			ft_dellist_ifail(begin_list);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	tmp->next = begin_list;
	tmp->end = 1;
	begin_list->back = tmp;
	begin_list->curse = 1;
	return (begin_list);
}
