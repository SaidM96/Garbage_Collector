/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:44:18 by smia              #+#    #+#             */
/*   Updated: 2022/06/23 19:52:42 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTOR_H
# define COLLECTOR_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct collector
{
	void				*adr;
	struct collector	*next;
}	t_collector;

t_collector	*new_node(void *adr);
t_collector	**append_adr(t_collector **root, void *adr);
void		*my_malloc(t_collector **root, size_t size);
void		ft_collect(t_collector **root, t_collector *node);

#endif