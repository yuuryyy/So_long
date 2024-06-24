/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:16:59 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/09 14:36:48 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

//int main()
//{
//	t_list	*lst;
//	t_list	*tmp;
//	t_list	*node1;
//	t_list	*node2;
//	t_list	*node3;

//	node1 = ft_lstnew("youssra");
//	node2 = ft_lstnew("chagri");
//	node3 = ft_lstnew("ychagri");
//	lst = NULL;
//	ft_lstadd_front(&lst,node1);
//	ft_lstadd_front(&lst,node2);
//	ft_lstadd_front(&lst,node3);

//	tmp = lst;
//	while (tmp)
//	{
//		printf("%s \n",tmp->content);
//		tmp = tmp->next;
//	}
//	return 0;
//}
