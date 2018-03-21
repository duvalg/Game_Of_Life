/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initStructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:46:56 by gduval            #+#    #+#             */
/*   Updated: 2018/03/21 11:47:05 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

void		initDna(struct globalInfo_ *dna, int flag){
	if (!dna)
		exitProgram("error while creating structures");
	dna->fileDescriptor = 0;
	dna->activeGraphic = flag;
	dna->firstItem = NULL;
	dna->item = NULL;
}

static void	initImg(struct imageInfo_ *img){
	if (!img)
		exitProgram("error while creating structures");
	img->imgPtr = NULL;
	img->img = NULL;
	img->bpp = 0;
	img->lineLength = 0;
	img->endian = 0;
}

void		initgraphicOutput(struct graphicOutput_ *graphicOutput){
	struct imageInfo_	img;

	if (!graphicOutput)
		exitProgram("error while creating structures");
	initImg(&img);
	graphicOutput->mlx = NULL;
	graphicOutput->win = NULL;
	graphicOutput->name = NULL;
	graphicOutput->img = &img;
}
