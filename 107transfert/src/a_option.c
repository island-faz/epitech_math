/*
** a_option.c for 107transfert in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar  3 00:05:09 2014 
** Last update Sun Mar 23 06:39:18 2014 
*/

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <transfert.h>

double		run_a_horner(t_arr arr)
{
  int		i;
  double	a;
  double	inc = 0;

  while ((int)inc < 1000)
    {
      i = 0;
      a = arr.arr[i++];
      while (i < arr.length)
	{
	  a = inc * a + arr.arr[i];
	  i++;
	}
      inc += 0.001;
    }
}

void		run_a_naive(t_arr arr)
{
  int		i;
  int		tmp;
  double	y;
  double	inc = 0;

  while ((int)inc < 1000)
    {
      i = 0;
      y = 0;
      while (i < arr.length)
	{
	  tmp = (arr.length - i - 1);
	  y += (double)arr.arr[i] * my_pow(inc, tmp);
	  i++;
	}
      inc += 0.001;
    }
}

void		run_a(t_arr arr)
{
  clock_t	start, stop;

  printf("évaluation du polynôme ");
  put_equation(arr);
  printf(" en 1 000 000 points :\n");
  start = clock();
  run_a_naive(arr);
  stop = clock();
  printf("algorithme naïf: %d millisecondes\n",
  	 (int)((double)(stop - start) / CLOCKS_PER_SEC * 1000));
  start = clock();
  run_a_horner(arr);
  stop = clock();
  printf("algorithme de Horner: %d millisecondes\n",
  	 (int)((double)(stop - start) / CLOCKS_PER_SEC * 1000));
}
