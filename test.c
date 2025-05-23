/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:07:02 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/21 12:51:32 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}


void	ft_pa(t_stack **a, t_stack **b)
{
		t_stack	*first;
		int		temp;

		if (!b || !*b)
			return ;
		first = *b;
		*b = (*b)->next;
		first->next = *a;
		*a = first;
		write (1, "pa\n", 3);
}

void	ft_sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write (1, "sb\n", 3);
}

void push_to_stack(t_stack **stack, int value)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
void	ft_ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write (1, "ra\n", 3);
}
void	ft_rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;


	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write (1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	if (b && *b && (*b)->next)
		first = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
		write (1, "rr\n", 3);
}
void	ft_rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write (1, "rra\n", 4);
}
void	ft_rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (a && *a && (*a)->next)
	{
		prev = *a;
		while (prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (b && *b && (*b)->next)
	{
		prev = *b;
		while (prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
	write (1, "rrr\n", 4);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*joined;
	char	*tmp;

	joined = ft_strdup("");
	while (i < argc)
	{
		tmp =ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (joined);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	totlen;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	totlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(totlen * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

static size_t	count_words(char const *s, char limit)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != limit && (i == 0 || s[i - 1] == limit))
			words++;
		i++;
	}
	return (words);
}

static size_t	count_letters(char const *s, char limit, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != limit)
		len++;
	return (len);
}

static void	free_split(char **res, size_t j)
{
	while (j--)
		free(res[j]);
	free(res);
}

static char	**fill_split(char const *s, char limit, char **res)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == limit)
			i++;
		if (s[i])
		{
			len = count_letters(s, limit, i);
			res[j] = malloc((len + 1) * sizeof(char));
			if (!res[j])
				return (free_split(res, j), NULL);
			k = 0;
			while (k < len)
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char limit)
{
	size_t	words;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, limit);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill_split(s, limit, res));
}

char	**split_args(int argc, char **argv)
{
	char	*joined;
	char	**values;

	joined = join_args(argc, argv);
	if (!joined)
	{
		write (1, "Error en join_args" , 19);
		return (NULL);
	}
	values = ft_split(joined, ' ');
	free(joined);
	return (values);
}

int main(int argc, char **argv)
{
/*     t_stack *a = NULL;  // Pila A vacía
    t_stack *b = NULL;  // Pila B vacía

    // Vamos a llenar la pila B con algunos valores
    push_to_stack(&b, 3); // B: 3
    push_to_stack(&b, 2); // B: 2 -> 3
    push_to_stack(&b, 1); // B: 1 -> 2 -> 3
	push_to_stack(&a, 6); // B: 3
    push_to_stack(&a, 5); // B: 2 -> 3
    push_to_stack(&a, 4); // B: 1 -> 2 -> 3
    //Mostrar estado inicial
    printf("Pila A antes: ");
    print_stack(a);
    printf("Pila B antes: ");
    print_stack(b);

    // Aplicar ft_pa (debería mover el primer nodo de B a A)
    ft_pa(&a, &b);

    // Mostrar el estado después de aplicar ft_pa
    printf("Pila A después de pa: ");
    print_stack(a);
    printf("Pila B después de pa: ");
    print_stack(b);

	ft_sb(&b);
	printf("Pila B después de sb: ");
    print_stack(b);

	ft_ra(&a);
	print_stack(a);

	ft_rb(&b);
	print_stack(b);
	
	ft_rr(&a, &b);
	print_stack(a);
	print_stack(b);

	ft_rra(&a);
	print_stack(a);

	ft_rrb(&b);
	print_stack(b);
	
	ft_rrr(&a, &b);
	print_stack(a);
	print_stack(b);
 */
	char **tokens = split_args(argc, argv);
	int i = 0;
	while (tokens && tokens[i])
	{
		printf("Token[%d]: %s\n", i, tokens[i]);
		free(tokens[i]);
		i++;
	}
	free(tokens);

	return 0;
}
