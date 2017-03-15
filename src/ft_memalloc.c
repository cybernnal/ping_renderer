/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <tbillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 11:45:41 by tbillard          #+#    #+#             */
/*   Updated: 2015/12/02 18:50:49 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <ping.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *ptr;

	ptr = (unsigned char*)malloc(sizeof(unsigned char) * (size));
	if (ptr == 0)
	{
		printf("Malloc error\n");
		return (0);
	}
	bzero(ptr, size);
	return (ptr);
}
