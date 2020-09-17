/*
** main.c for 108monstre in /home/bourhi_a/rendu/108monstre
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar 23 20:26:09 2014 
** Last update Thu Apr  3 18:56:06 2014 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void		run_monster(int fd, double a, int nmax)
{
  int		i;
  double	y;
  double	x;

  x = -2;
  while (x <= 2 && !(i = 0) && !(y = 0))
    {
      while (i <= nmax)
	{
 	  y += cos(pow(a, i) * M_PI * x) / pow(2, i);
	  i++;
	}
       dprintf(fd, "%f %f\n", x, y);
      x += 0.01;
    }
}

int		main(int ac, char **av)
{
  int		fd;
  int		flag;
  int		nmax;
  double	a;

  flag = 0;
  if (ac < 3 && fprintf(stderr, "[+] usage: ./108monstre [a] [nmax]\n[+] This application requiere gnuplot.\n"))
    return (1);
  a = atof(av[1]);
  nmax = atoi(av[2]);
  if (nmax < 0)
    {
      dprintf(2, "[+] Input error: nmax should be positive or null.\n");
      return (1);
    }
  if (ac >= 4 && !strcmp(av[3], "-r"))
    if (!access(".tmp.dat", R_OK | W_OK))
      {
	flag = 1;
	remove(".old.dat");
	rename(".tmp.dat", ".old.dat");
      }
  if ((fd = open(".tmp.dat", O_TRUNC | O_WRONLY |
		 O_CREAT, 0666)) > 0)
    run_monster(fd, a, nmax);
  close(fd);
  if (flag)
    system("gnuplot -p .rcmd");  
  else
    system("gnuplot -p .cmd");   
  return (0);
}
