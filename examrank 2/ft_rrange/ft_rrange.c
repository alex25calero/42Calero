/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:47:48 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/29 13:26:08 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* int int_lenth(int start, int end)
{
	int i;
	i = 1;
	if (end == start)
		return (1);
	while (end > start)
	{
		i++;
		end--;
	}
	while (end < start)
	{
		i++;
		end++;
	}
	return (i);
}

int *ft_rrange(int start, int end)
{
	int i;
	int lenth;
	int *nums;
	
	i = 0;
	lenth = int_lenth(start, end);
	nums = (int*)malloc(sizeof(int) * lenth);
	if (!nums)
		return (0);
	if (end == start)
	{	
		nums[i] = end;
		return (nums);
	}
	while (end >= start)
	{
		nums[i] = end;
		i++;
		end--;
	}
	while (end <= start)
	{
		nums[i] = end;
		i++;
		end++;
	}
	return (nums);
} */

int *ft_rrange(int start, int end)
{
int *range;
int i = 0;
int n = end - start + 1;
if (start > end)
return (ft_rrange(end, start));
range = (int *)malloc(sizeof(int) * n);
if (range)
{
while (i < n)
{
range[i] = end;
end--;
i++;
}
}
return (range);
}
int main(void)
{
	int lenth;
	int *nums;
	int i = 0;
	
	//lenth = int_lenth(-1, 2);
	//printf("%i\n", lenth);
	printf("------------------\n");
	nums = ft_rrange(1, -2);
	while (i < 5)
	{
		printf("%d\n", nums[i]);
		i++;
	}
	return (0);
}
