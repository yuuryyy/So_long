/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:58:12 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/09 14:39:50 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (!lst || !f)
		return ;
	node = lst;
	while (node != NULL)
	{
		f(node->content);
		node = node->next;
	}
}

//void	toup(void *c)
//{
//	char *str;

//	str = (char *)c;
//	int	i = 0;

//	while(str[i])
//	{
//		str[i]= ft_toupper(str[i]);
//		i++;
//	}
//	//c = str;
//}

//int main()
//{
//	t_list	*lst;
//	t_list	*tmp;
//	t_list	*node1;
//	t_list	*node2;
//	t_list	*node3;
//	int	a[] = {5};
//	int	b[] = {13};
//	int c[] = {37};

//	node1 = ft_lstnew(a);
//	node2 = ft_lstnew(b);
//	node3 = ft_lstnew(c);
//	lst = NULL;
//	ft_lstadd_front(&lst,node1);
//	ft_lstadd_front(&lst,node2);
//	ft_lstadd_front(&lst,node3);
//	//ft_lstiter(lst, &toup);
//	tmp = lst;
//	while (tmp)
//	{
//		printf("%d \n",(int)tmp->content[0]);
//		tmp = tmp->next;
//	}
//	return 0;
//}