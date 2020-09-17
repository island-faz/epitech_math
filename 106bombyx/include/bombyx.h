/*
** bombyx.h for 106bombyx in /home/bourhi_a/rendu/106bombyx
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Feb 18 09:09:32 2014 
** Last update Tue Feb 18 13:33:38 2014 
*/

#ifndef		BOMBYX_H_
#define		BOMBYX_H_

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define CTE	1000

int		usage();
int		is_file(char *path);
int		get_gen(int n, double k);
void	        bombyx_b(int i_min, int i_max, int fd);
void		bombyx_a(double k, int fd);
void		run_program(int fd, int ac, char **av);
int		dprintf(int fd, const char *format, ...);

#endif		/* BOMBYX_H_ */		
