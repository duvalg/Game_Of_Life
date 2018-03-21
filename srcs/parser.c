/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:34:17 by gduval            #+#    #+#             */
/*   Updated: 2018/03/16 13:37:27 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

static int  isNum(const char c){
    return ((c < '0' || c > '9') && c != '-') ? 0 : 1;
}


void        addItem(char **line, struct globalInfo_ *dna){
    char    basicItem[dna->item->height][dna->item->width];
    char    *tmp = NULL;
    int     x = -1, y = -1;
    int     points = 0;
    int     ret = 0;

    while ((ret = get_next_line(dna->fileDescriptor, line)) > 0){
        tmp = ft_strtrim(*line);
        if (strchr(*line, ']'))
            break ;
        if (y == dna->item->height)
            exitProgram("error while parsing : item.form");
        ++y;
        while (tmp[++x]){
            if (x == dna->item->width)
                exitProgram("error while parsing : item.form");
            basicItem[y][x] = tmp[x];
        }
        if (x != dna->item->width)
            exitProgram("error while parsing : item.form");
        x = -1;
        free(*line);
        free(tmp);
    }

    // create item array
    y = -1;
    while (++y < dna->item->height){
        x = -1;
        while (++x < dna->item->width){
            if (basicItem[y][x] != '.' && basicItem[y][x] != '#')
                exitProgram("bad item format");
            if (basicItem[y][x] == '#')
                ++points;
        }
    }
    dna->item->points = points;
    if (!(dna->item->item = (int **)malloc(sizeof(int *) * points)))
        exitProgram("error while allocating memory");
    while (--points >= 0){
        if (!(dna->item->item[points] = (int *)malloc(sizeof(int) * 2)))
            exitProgram("error while allocating memory");
    }

    // fill array
    int **ptr = dna->item->item;

    y = -1;
    while (++y < dna->item->height){
        x = -1;
        while (++x < dna->item->width){
            if (basicItem[y][x] == '#'){
                (*ptr)[0] = y;
                (*ptr)[1] = x;
                ptr++;
            }
        }
    }
}

void        getItemPos(const char *line, struct globalInfo_ *dna){
    int     i = -1;
    int     count = 0;
    int     getInfo = 0;
    char    c = '\0';

    while ((c = line[++i])){
        while ((c = line[i]) && isNum((const char)c)){
            ++count;
            if ((getInfo = (int)ft_atoi(line + i)) < 0){
                exitProgram("error while parsing : item.pos");
            }
            else{
                if (count == 1)
                    dna->item->posY = getInfo;
                else if (count == 2)
                    dna->item->posX = getInfo;
                else
                    exitProgram("error while parsing : item.pos");
                i += ft_intlen(getInfo);
            }
        }
    }
}

void        getItemSize(const char *line, struct globalInfo_ *dna){
    int     i = -1;
    int     count = 0;
    int     getInfo = 0;
    int     size = (int)ft_strlen(line);
    char    c = '\0';

    while (++i < size){
        while ((c = line[i]) && isNum((const char)c)){
            ++count;
            if (!(getInfo = (int)ft_atoi(line + i))){
                exitProgram("00 error while parsing : item.size");
            }
            else{
                if (count == 1)
                    dna->item->height = getInfo;
                else if (count == 2)
                    dna->item->width = getInfo;
                else
                    exitProgram("01 error while parsing : item.size");
                i += ft_intlen(getInfo);
            }
        }
    }
}
