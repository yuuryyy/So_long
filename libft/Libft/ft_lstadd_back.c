/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:43:19 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/09 14:38:05 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
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
//	ft_lstadd_back(&lst,node1);
//	ft_lstadd_back(&lst,node2);
//	ft_lstadd_back(&lst,node3);

//	printf("%d \n",ft_lstsize(lst));
//	tmp = lst;
//	while (tmp)
//	{
//		printf("%s \n",tmp->content);
//		tmp = tmp->next;
//	}
//	return 0;
//}