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

/* 	DIMENSIONS OF THE MAP	*/
# define WIDTH 100
# define HEIGHT 50

/* 	NUMBER OF THREADS
	DO NOT TOUCH 			*/
# define THREADS 20

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

// debug library
# include <stdio.h>

struct						imageInfo_{
	void					*imgPtr;
	char					*img;
	int						bpp;
	int						lineLength;
	int						endian;
};

struct						graphicOutput_{
	void					*mlx;
	void					*win;
	char					*name;
	struct imageInfo_		*img;
};

struct						itemList_{
	int						**item;
	int						height;
	int						width;
	int						posX;
	int						posY;
	int						points;
	struct itemList_		*next;
};

struct						globalInfo_{
	int						fileDescriptor;
	int						map[HEIGHT][WIDTH];
	int						activeGraphic;
	struct itemList_		*firstItem;
	struct itemList_		*item;
	struct graphicOutput_	*graphicOutput;
};

int							main(int ac, char **av);
void						initDna(struct globalInfo_ *dna, int flag);
void						initgraphicOutput(struct graphicOutput_ *graphicOutput);
void        				getItemSize(const char *line, struct globalInfo_ *dna);
void        				getItemPos(const char *line, struct globalInfo_ *dna);
void        				addItem(char **line, struct globalInfo_ *dna);
void        				createMap(struct globalInfo_ *dna);
void       					displayMap(int array[][WIDTH]);
void						exitProgram(const char *errorMsg);

#endif
