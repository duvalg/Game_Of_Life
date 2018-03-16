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

static void		getItemList(struct globalInfo_ dna){
	char	*line = NULL;
	char	*tmp = NULL;
	int		ret = 0;

	while ((ret = get_next_line(dna.fileDescriptor, &line)) > 0){
		tmp = ft_strtrim(line);
		free(line);
		if (strstr(tmp, "item.info"))
			createItem(dna);	// NOT IMPLEMENTED YET
		if (strstr(tmp, "item.size"))
			getItemSize();		// NOT IMPLEMENTED YET
		if (strchr(tmp, "[")){
			while ((ret = get_next_line(dna.fileDescriptor, &line)) > 0){
				if (strchr(line, ']')){
					getItem();	// NOT IMPLEMENTED YET
					break ;
				}
			}
		}
		free(tmp);
		tmp = NULL;
	}
}

static void		openFile(const char *FileName){
	struct globalInfo_	dna;

	if ((dna.fileDescriptor = open(FileName, O_RDONLY)) < 1)
		exitProgram("could not open the file");
	initStruct();				// NOT IMPLEMENTED YET
	getItemList(dna);
}

int				main(int ac, char **av){
	if (ac != 2)
		exitProgram("wrong number of parameters");
	else
		openFile((const char *)av[1]);
	return (0);
}
