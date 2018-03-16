/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitProgram.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:31:13 by gduval            #+#    #+#             */
/*   Updated: 2018/03/16 14:31:55 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

void	exitProgram(const char *errorMsg){
	ft_putendl_fd(errorMsg, 2);

	// Should print usages
	exit(EXIT_FAILURE);
}
