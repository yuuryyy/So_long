/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:22:24 by ychagri           #+#    #+#             */
/*   Updated: 2023/11/10 18:28:27 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlst;

	newlst = NULL;
	while (lst != NULL && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			break ;
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	if (lst != NULL)
		ft_lstclear(&newlst, del);
	return (newlst);
}

//void	*toup(void *c)
//{
//	char *str;

//	str = ft_strdup((char *)c);
//	int	i = 0;

//	while(str[i])
//	{
//		str[i] = ft_toupper(str[i]);
//		i++;
//	}
//	return ((void *)str);
//}
//void	del(void *content)
//{
//	content = NULL;
//}

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
//	tmp = ft_lstmap(lst, toup, del);
//	while (tmp)
//	{
//		printf("%s \n",tmp->content);
//		tmp = tmp->next;
//	}
//	return 0;
//}
