/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createMap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:34:17 by gduval            #+#    #+#             */
/*   Updated: 2018/03/16 13:37:27 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gol.h"

static int  checkConnections(int array[][WIDTH], int x, int y, int type){
    int connections = 0;

    if (y > 0 && (array[y - 1][x] == type))
        connections++;
    if (y > 0 && x > 0 && array[y - 1][x - 1] == type)
        connections++;
    if (y > 0 && x < (WIDTH - 1) && array[y - 1][x + 1] == type)
        connections++;
    if (y < (HEIGHT - 1) && array[y + 1][x] == type)
        connections++;
    if (y < (HEIGHT - 1) && x > 0 && array[y + 1][x - 1] == type)
        connections++;
    if (y < (HEIGHT - 1) && x < (WIDTH - 1) && array[y + 1][x + 1] == type)
        connections++;
    if (x > 0 && array[y][x - 1] == type)
        connections++;
    if (x < (WIDTH - 1) && array[y][x + 1] == type)
        connections++;
    return (connections);
}

static void newCell(int array[][WIDTH]){
    int x;
    int y = -1;
    int connections = 0;

    while (++y < HEIGHT){
        x = -1;
        while (++x < WIDTH){
            connections = checkConnections(array, x, y, 1);
            if (connections == 3 && array[y][x] == 0)
                array[y][x] = 2;
        }
    }
}

static void killCell(int array[][WIDTH]){
    int x;
    int y = -1;
    int connections = 0;

    while (++y < HEIGHT){
        x = -1;
        while (++x < WIDTH){
            connections = checkConnections(array, x, y, 1);
            connections += checkConnections(array, x, y, -1);
            if ((connections < 2 || connections > 3) && array[y][x] == 1)
                array[y][x] = -1;
        }
    }
}

static void applyRules(int array[][WIDTH]){
    newCell(array);
    killCell(array);
}

void        displayMap(int array[][WIDTH]){
    int         y = -1;
    int         x;

    while (++y < HEIGHT){
        x = -1;
        while (++x < WIDTH){
            if (array[y][x] == 0){
                ft_putchar('.');
            }
            else{
                if (array[y][x] == 1){
                    ft_putchar('#');
                }
                if (array[y][x] == 2){
                    ft_putchar('#');
                    array[y][x] = 1;
                }
                else if (array[y][x] == -1){
                    array[y][x] = 0;
                    ft_putchar('.');
                }
            }
        }
        ft_putendl("");
    }
}

static void placeItems(struct globalInfo_ *dna){
    int i;

    dna->item = dna->firstItem;
    while (dna->item){
        i = -1;
        if ((dna->item->height + dna->item->posY) >= HEIGHT || \
        (dna->item->width + dna->item->posX) >= WIDTH){
            exitProgram("items don't fit in the map");
		}
        while (++i < dna->item->points){
            if (dna->map[dna->item->item[i][0] + dna->item->posY][dna->item->item[i][1] + dna->item->posX] == 0){
                dna->map[dna->item->item[i][0] + dna->item->posY][dna->item->item[i][1] + dna->item->posX] = 1;
            }
            else{
                exitProgram("some items overlap");
            }
        }
        dna->item = dna->item->next;
    }
}

void    createMap(struct globalInfo_ *dna){
    int turn = 0;
    int y = -1;
    int x;

    while (++y < HEIGHT){
        x = -1;
        while (++x < WIDTH){
            dna->map[y][x] = 0;
		}
    }
    placeItems(dna);
    while (1){
		if (system("clear")){
            exitProgram("system error - please retry");
		}
		applyRules(dna->map);
		if (dna->activeGraphic){
			ft_putendl("Display with minilibx");
			exit(EXIT_SUCCESS);
		}
		else{
			ft_putnbr(turn);
	        ft_putendl("");
	        displayMap(dna->map);
	        if (system("sleep 0.20s"))
	            exitProgram("system error - please retry");
	        ++turn;
		}
    }
}
