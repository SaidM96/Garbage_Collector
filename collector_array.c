/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:49:45 by smia              #+#    #+#             */
/*   Updated: 2022/06/23 20:01:08 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collector.h"

int	lst_size(void **lst)    
{
	int		i;

	i = 0;
	if (!lst)
		return (i);
	while (*lst && ++i)
		lst++;
	return (i);
}

void	lst_free(void **lst)
{
	int	size;
	int	i;

	if (!lst)
		return ;
	size = lst_size(lst);
	i = -1;
	while (++i < size)
		free(lst[i]);
	free(lst);
}

void	append_array(void ***list, void *adr)
{
	void	**new;
	void	**lst;
	int		size;
	int		i;

	lst = *list;
	size = lst_size(lst);
	i = -1;
	new = malloc((size + 2) * sizeof(void *));
	while (++i < size)
		new[i] = lst[i];
	new[size] = adr;
	new[size + 1] = NULL;
	free(lst);
	*list = new;
}

void	*ft_malloc_array(void	***lst, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	else
		return (append_array(lst, ret), ret);
}