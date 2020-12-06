/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dwayne_johnson.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levensta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:49:52 by levensta          #+#    #+#             */
/*   Updated: 2020/12/06 13:02:09 by levensta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DWAYNE_JOHNSON_H
# define DWAYNE_JOHNSON_H

# include <unistd.h>

typedef struct	s_ascii_image
{
	char		*s[54];
}				t_ascii_image;

size_t			ft_strlen(const char *str);
void			initialize_str1(t_ascii_image *dw);
void			print_dwayne(void);
void			print_text(void);
#endif
