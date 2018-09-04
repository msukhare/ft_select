/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:59:04 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 17:25:35 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			ft_getsize(int size)
{
	t_term_size	term_s;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if ((ioctl(0, TIOCGWINSZ, &term_s)) < 0)
		ft_escape("ioctl fail\n", 1);
	while (size > term_s.ws_col)
	{
		size -= term_s.ws_col;
		y++;
	}
	x = size;
	ft_refresh(&x, &y, 1);
}

void			ft_catch_ctrz(int n)
{
	char		tmp[2];

	n = 0;
	ft_refresh(0, 0, 0);
	ft_vis_curs();
	tmp[0] = g_term.termi.c_cc[VSUSP];
	tmp[1] = '\0';
	if ((ioctl(0, TIOCSTI, tmp)) < 0)
		ft_escape("ioctl fail\n", 1);
	if ((tcsetattr(0, TCSANOW, &g_term.termi)) < 0)
		ft_escape("tcsetattr fail\n", 1);
	signal(SIGTSTP, SIG_DFL);
}

void			ft_redimterm(int n)
{
	t_arg		*tmp;
	int			size;

	size = 0;
	tmp = g_term.begin_list;
	n = 0;
	while (tmp->curse != 1)
	{
		size += (ft_strlen(tmp->argu) + 1);
		tmp = tmp->next;
	}
	ft_getsize(size);
}

void			ft_backto_fct(int n)
{
	t_termo		term;
	t_arg		*tmp;
	int			size;

	size = 0;
	n = 0;
	if ((tcgetattr(0, &term)) < 0)
		ft_escape("tcgetattr fail\n", 1);
	if ((ft_push(&term)) < 0)
		ft_escape("tcsetattr fail\n", 1);
	tmp = g_term.begin_list;
	while (tmp->curse != 1)
	{
		size += (ft_strlen(tmp->argu) + 1);
		tmp = tmp->next;
	}
	ft_getsize(size);
	signal(SIGTSTP, ft_catch_ctrz);
	ft_inv_curs();
}
