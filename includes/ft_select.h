/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:07:13 by msukhare          #+#    #+#             */
/*   Updated: 2018/03/09 14:49:36 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <curses.h>
# include <termios.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "../libft/include/libft.h"
# define RIGHT 1
# define LEFT 2

typedef struct termios	t_termo;
typedef struct winsize	t_term_size;
typedef struct			s_arg
{
	char				*argu;
	int					curse;
	int					select;
	int					end;
	struct s_arg		*next;
	struct s_arg		*back;
}						t_arg;
typedef	struct			s_term
{
	t_termo				termi;
	t_arg				*begin_list;
}						t_term;
t_term					g_term;
t_arg					*ft_creatlist(char **argv);
void					ft_dellist(void);
void					ft_readcmd(void);
void					ft_escape(char *error, int refresh);
void					ft_refresh(int *x, int *y, int put);
void					ft_putlist(void);
void					ft_putcurse(int *x, int *y);
void					ft_return(void);
void					ft_mv_curse(char *buff, int *x, int *y);
void					ft_select(int *x, int *y);
void					ft_dellink(int *x, int *y);
void					ft_getallsignal(void);
void					ft_mv_left_right(t_arg *tmp, int *x, int *y,\
	int side);
void					ft_inv_curs(void);
void					ft_vis_curs(void);
int						ft_push(t_termo *old_termo);
void					ft_catch_ctrz(int n);
void					ft_getsize(int size);
void					ft_redimterm(int n);
void					ft_backto_fct(int n);
#endif
