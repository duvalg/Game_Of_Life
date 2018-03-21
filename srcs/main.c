/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:34:17 by gduval            #+#    #+#             */
/*   Updated: 2018/03/16 13:37:27 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

static void		createItem(struct globalInfo_ *dna){
	struct itemList_	*newItem;

	if (!(newItem = (struct itemList_ *)malloc(sizeof(struct itemList_)))){
		exitProgram("error while allocating memory");
	}
	newItem->item = NULL;
	newItem->height = 0;
	newItem->width = 0;
	newItem->posX = 0;
	newItem->posY = 0;
	newItem->points = 0;
	newItem->next = NULL;
	if (!dna->firstItem){
		dna->firstItem = newItem;
		dna->item = newItem;
	}
	else{
		dna->item->next = newItem;
		dna->item = newItem;
	}

}

static void		getItemList(struct globalInfo_ *dna){
	char	*line = NULL;
	char	*tmp = NULL;
	int		ret = 0;

	while ((ret = get_next_line(dna->fileDescriptor, &line)) > 0){
		if (!(tmp = ft_strtrim(line)) || (ft_strnstr(tmp, "//", 2))){
			free(line);
			continue ;
		}
		if (strstr(tmp, "item.create")){
			createItem(dna);
		}
		else if (strstr(tmp, "item.size")){
			getItemSize(tmp, dna);
		}
		else if (strstr(tmp, "item.pos")){
			getItemPos(tmp, dna);
		}
		else if (strchr(tmp, '[')){
			addItem(&tmp, dna);
		}
		free(line);
		free(tmp);
		tmp = NULL;
	}
}

static void		openFile(const char *FileName, int flag){
	struct globalInfo_	dna;

	initDna(&dna, flag);
	if ((dna.fileDescriptor = open(FileName, O_RDONLY)) < 1){
		exitProgram("could not open the file");
	}
	getItemList(&dna);
	createMap(&dna);
}

int				main(int ac, char **av){
	int			flag = 0;

	if (ac != 2){
		if (strcmp("-g", av[1])){
			exitProgram("wrong number of parameters");
		}
		else{
			++flag;
		}
	}
	if (flag){
		openFile((const char *)av[2], flag);
	}
	else{
		openFile((const char *)av[1], flag);
	}
	return (0);
}
