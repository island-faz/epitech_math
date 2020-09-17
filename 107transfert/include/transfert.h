/*
** 107tr.h for 107transfert in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar  2 04:41:55 2014 
** Last update Tue Mar  4 00:08:41 2014 
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifndef				TRANSFERT_H_
#define				TRANSFERT_H_

# define ABS(x)			((((x)) < 0) ? (-(x)) : ((x)))
# define TMP_DIR		".tmp"
# define TMP_CMD		".tmp/cmd"
# define XY_RNGE		"set yrange[-30:30];\nset xrange[-10:10];"

typedef struct			s_arr
{
  int				*arr;
  int				length;
}				t_arr;

double				my_pow(double d, int n);
int				is_dir(char *path);
void				run_a(t_arr arr);
int				run_b(int ac, char **av);
void				put_equation(t_arr arr);
int				nb_sep(char *s, char sep);
void				xerror(char *s);

#endif				/* TRANSFERT_H_ */
