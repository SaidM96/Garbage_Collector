/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:46:09 by smia              #+#    #+#             */
/*   Updated: 2022/06/23 19:51:17 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collector.h"

t_collector	*new_node(void *adr)
{
	t_collector	*node;

	node = malloc(sizeof(t_collector));
	if (!node)
		return (NULL);
	node->adr = adr;
	node->next = NULL;
	return (node);
}

t_collector	**append_adr(t_collector **root, void *adr)
{
	t_collector	*node;
	t_collector	*tmp;

	node = new_node(adr);
	if (!*root)
		return (*root = node, root);
	tmp = *root;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (root);
}

void	*my_malloc(t_collector **root, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	else
		return (append_adr(root, ptr), ptr);
}

void	ft_collect(t_collector **root, t_collector *node)
{
	if (!node)
		return ;
	ft_collect(root, node->next);
	free(node->adr);
	free(node);
}
