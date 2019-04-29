/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:54:43 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/24 16:11:44 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				push(t_map **head, int *data)
{
	t_map			*tmp;

	if (!(tmp = (t_map*)malloc(sizeof(t_map))))
		return ;
	tmp->x = data[0];
	tmp->y = data[1];
	tmp->z = data[2];
	tmp->collor = data[3];
	tmp->next = (*head);
	(*head) = tmp;
}


int					*pop(t_map **head)
{
	t_map			*prev;
	int				data[4];

	prev = NULL;
	if (head == NULL)
		return (NULL);

	prev = (*head);
	data[0] = prev->x;
	data[1] = prev->y;
	data[2] = prev->z;
	data[3] = prev->collor;
	(*head) = (*head)->next;
	free(prev);
	prev = NULL;
	return (data);
}

t_map				*getNth(t_map* head, int n)
{
	int				i;

	i = 0;
	while (i < n && head)
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_map				*getLast(t_map *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void				pushBack(t_map *head, int *data)
{
	t_map			*last;
	t_map			*tmp;

	last = getLast(head);
	tmp = (t_map*)malloc(sizeof(t_map));
	tmp->x = data[0];
	tmp->y = data[1];
	tmp->z = data[2];
	tmp->collor = data[3];
	tmp->next = NULL;
	last->next = tmp;
}

t_map				*getLastButOne(t_map *head)
{
	if (head == NULL)
		return(-1);
	if (head->next == NULL)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

int					*popBack(t_map **head)
{
	t_map			*curr;
	t_map			*prev;
	int				data[4];

	if (!head)
		return (NULL);
	if (!(*head))
		return (NULL);

	curr = *head; 
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		data[0] = curr->x;
		data[1] = curr->y;
		data[2] = curr->z;
		data[3] = curr->collor;
		free(curr->next);
		prev->next = NULL;
	}
	return (data);
}

void				insert(t_map *head, unsigned int n, int *data)
{
	unsigned int	i;
	t_map			*tmp;

	i = 0;
	tmp = NULL;
	while (i++ < n && head->next)
		head = head->next;
	tmp = (t_map*)malloc(sizeof(t_map));
	tmp->x = data[0];
	tmp->y = data[1];
	tmp->z = data[2];
	tmp->collor = data[3];
	if (head->next)
		tmp->next = head->next;
	else
		tmp->next = NULL;
	head->next = tmp;
}

int					*popNth(t_map **head, int n)
{
	t_map			*prev;
	t_map			*elm;
	int				*data;

	if (n == 0)
		return pop(head);
	else
	{
		prev = getNth(*head, n-1);
		elm  = prev->next;
		data[0] = elm->x;
		data[1] = elm->y;
		data[2] = elm->z;
		data[3] = elm->collor;
		prev->next = elm->next;
		free(elm);
		return (data);
	}
}

void				deleteList(t_map **head)
{
	t_map			*prev;

	prev = NULL;
	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

// void				fromArray(t_map **head, int *arr, size_t size)
// {
// 	size_t			i;

// 	i = size - 1;
// 	if (arr == NULL || size == 0)
// 		return ;
// 	while(i--!=0)
// 		push(head, arr[i]);
// }

size_t				length(const t_map *head)
{
	size_t			i;
	t_map			*curr;

	i = 0;
	while (curr->next && i++)
		curr = curr->next;
	return (i);
}

// int					*toArray(const t_map *head)
// {
// 	size_t			leng;
// 	int				*values;

// 	leng = length(head);
// 	values = (int*) malloc(leng*sizeof(int));
// 	while (head)
// 	{
// 		values[--leng] = head->value;
// 		head = head->next;
// 	}
// 	return values;
// }

// void printLinkedList(const t_map *head) {
//     while (head) {
//         printf("%d ", head->value);
//         head = head->next;
//     }
//     printf("\n");
// }
