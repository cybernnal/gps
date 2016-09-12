/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:09:42 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 17:58:24 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <stdint.h>

/*
** int flag:
** # = FLAG_DI
** 0 = FLAG_ZE
** - = FLAG_NEG
** + = FLAG_POS
** j = FFLAG_J
** h = FLAG_H
** l = FLAG_L
** z = FLAG_Z
** hh = FLAG_HH
** ll = FLAG_LL
** L = FLAG_GL
** space = FLAG_SP
** precision = FLAG_PR
** couleur = FLAG_COLOR
*/

# define FLAG_DI	0x00000001
# define FLAG_ZE	0x00000002
# define FLAG_NEG	0x00000004
# define FLAG_POS	0x00000008
# define FLAG_J		0x00000010
# define FLAG_H		0x00000020
# define FLAG_L		0x00000040
# define FLAG_Z		0x00000080
# define FLAG_HH	0x00000100
# define FLAG_LL	0x00000200
# define FLAG_SP	0x00000400
# define FLAG_PR	0x00000800
# define FLAG_GL	0x00001000
# define FLAG_COLOR	0x00002000

# define MAX -9223372036854775807

/*
** COLOR:
** CL_0 = white
** CL_1 = black
** CL_2 = red
** CL_3 = green
** CL_4 = yellow
** CL_5 = blue
** CL_6 = purple
** CL_7 = cyan
** CL_8 = grey
*/

# define CL_0 "\x1b[0m"
# define CL_1 "\x1b[30m"
# define CL_2 "\x1b[31m"
# define CL_3 "\x1b[32m"
# define CL_4 "\x1b[33m"
# define CL_5 "\x1b[34m"
# define CL_6 "\x1b[35m"
# define CL_7 "\x1b[36m"
# define CL_8 "\x1b[37m"

typedef struct		s_var
{
	int				pwc;
	int				free1;
	int				free;
	int				neg;
	int				*index;
	int				ind;
	int				width;
	int				preci;
	unsigned int	flag;
	int				arg;
	int				ret;
	int				i;
	int				naze;
	char			spe;
	char			*str;
	char			*tmp;
	char			*form;
	char			*ptr;
	va_list			ap;
}					t_var;

typedef struct		s_ld
{
	long double		save;
	long double		nb;
	int				nbdiv;
	int				nbmult;
	int				i;
	int				preci;
	int				neg;
	char			*ret;
}					t_ld;

int					ft_printf(const char *restrict format, ...);
int					ft_sprintf(char *str, const char *restrict format, ...);
int					ft_snprintf(char *str, size_t size,
		const char *restrict format, ...);
void				ft_put_end(t_var *var);
void				intvar(t_var *var);
int					ft_pars_string(t_var *var);
int					ft_pars_mod(t_var *var);
void				ft_pars_nb(t_var *var);
void				ft_pars_nbw(t_var *var);
void				ft_tab_ft_init(int (**tab_ft)(t_var *));
int					ft_check_flag(t_var *var);
int					ft_check_modif(t_var *var);
int					ft_ver_flag(t_var *var);
void				ft_ver_flag2(t_var *var);
int					ft_pf_modulo(t_var *var);
int					ft_pf_char(t_var *var);
int					ft_pf_string(t_var *var);
int					ft_pf_nb(t_var *var);
int					ft_pf_unb(t_var *var);
int					ft_pf_oct(t_var *var);
int					ft_pf_hex(t_var *var);
int					ft_pf_hexup(t_var *var);
int					ft_pf_mem(t_var *var);
int					ft_pf_l(t_var *var);
int					ft_pf_wchar(t_var *var);
int					ft_pf_wcstr(t_var *var);
int					ft_pf_intn(t_var *var);
int					ft_pf_bin(t_var *var);
int					ft_pf_ubin(t_var *var);
int					ft_pf_ld(t_var *var);
int					ft_pf_eld(t_var *var);
int					ft_pf_gld(t_var *var);
int					cc(t_var *var, char c);
intmax_t			ft_get_int(t_var *var);
intmax_t			ft_get_uint(t_var *var);
char				*ft_ld(t_var *var);
char				*ft_exp(t_var *var, char *str, int p);
char				*ft_preci_nb(char *str, t_var *var);
char				*ft_preci_str(char *str, t_var *var);
char				*ft_space(char *str, t_var *var);
char				*ft_free_join(char *s1, char *s2);
char				*ft_free2_join(char *s1, char *s2);
char				*ft_free12_join(char *s1, char *s2);
char				*ft_add_char(char *str, char c, t_var *var);
char				*to_ubase(uintmax_t n, int b);
char				*to_base(intmax_t n, int b);
char				*to_ubaseup(uintmax_t n, int b);
char				*ft_itoamax(intmax_t n);
char				*ft_zero(t_var *var, int x);
int					ft_color(t_var *var);
void				ft_end_color(t_var *var);
char				*ft_getbit(uintmax_t n);
char				*ldtoa(t_var *var, long double ld, int preci);
void				norm(t_var *var, size_t size, char *str);
void				norm_gld(t_var *varm, char **tmp, char **ptr, int *i);
void				norm_sp(t_var *var);
int					norm_wch(t_var *var, wchar_t wc, char *tmp);
char				*norm_wcst(t_var *var, wchar_t *wc, char *tmp);
char				*wctost(wchar_t wc, t_var *var);
char				*norm_ld(char *tmp);
char				*norm_exp(t_var *var, char *tmp, int j);
int					norm_gl(t_var *var, char **tmp);
#endif
