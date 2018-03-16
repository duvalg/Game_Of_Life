/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:41:46 by gduval            #+#    #+#             */
/*   Updated: 2018/03/16 13:41:47 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOL_H
# define GOL_H

/* 	DIMENSIONS OF THE MAP
	be sure items positionfit in the map 	*/
# define WIDTH 1920
# define HEIGHT 1080

/* 	NUMBER OF THREADS
	DO NOT TOUCH 							*/
# define THREADS 20

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

struct					itemList_{
	char				*basicItem;
	int					**item;
	int					height;
	int					width;
	struct itemList_	*next; 				// point to the next items
};

struct					globalInfo_{
	int					fileDescriptor;
	int					**map;
	struct itemsList_	*firstItem;
	struct itemsList_	*item;
};

int					main(int ac, char **av);
void				exitProgram(const char *errorMsg);

#endif
