/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:07:23 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:07:39 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_value			*value_new(int rank, int place)
{
	t_value	*ret;

	if (!(ret = (t_value*)malloc(sizeof(t_value))))
		return (NULL);
	ret->rank = rank;
	ret->place = place;
	return (ret);
}
