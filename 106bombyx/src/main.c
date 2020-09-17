/*
** main.c for 106bombyx in /home/bourhi_a/rendu/106bombyx
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Feb 17 05:44:38 2014 
** Last update Fri Feb 28 16:49:02 2014 
*/

#include <bombyx.h>

int		get_gen(int n, double k)
{
  int		i;
  double	x;

  i = 0;
  x = 10;
  while (i < n)
    {
      x = k * x * ((CTE - x) / CTE);
      i++;
    }
  return (x);
}

void	        bombyx_b(int i_min, int i_max, int fd)
{
  int		i;
  double	x;
  double	k;
  
  k = 1;
  while (k <= 4)
    {
      x = get_gen(i_min, k);
      i = i_min;
      while (i <= i_max)
	{
	  x = k * x * ((CTE - x) / CTE);
	  dprintf(fd, "%f %f\n", k, x);
	  i++;
	}
      k += 0.01;
    }
  system("gnuplot -p -e \"plot '.tmp.dat' using 1:2 pt 7 ps 0.2 notitle\"");
}

void		bombyx_a(double k, int fd)
{
  int		i;
  double	x;
  int		NB_GENERATION = 100;

  i = 0;
  x = 10;
  while (i < NB_GENERATION)
    {
      dprintf(fd, "%d %f\n", i + 1, x);
      x = k * x * ((CTE - x) / CTE);
      i++;
    }
  system("gnuplot -p -e \"plot '.tmp.dat' with lines notitle\"");
}

void		run_program(int fd, int ac, char **av)
{
  double	k;
  int		i_min;
  int		i_max;

  if (ac == 2)
    {
      k = atof(av[1]);
      if (k >= 1 && k <= 4)
	bombyx_a(k, fd);
      else
	usage();
    }
  else if (ac > 2)
    {
      i_min = atoi(av[1]);
      i_max = atoi(av[2]);
      if (i_min > 0 && i_max >= i_min)
	bombyx_b(i_min, i_max, fd);
      else
	usage();
    }
}

int		main(int ac, char **av)
{
  int		fd;

  if (!is_file("/usr/bin/gnuplot") && !is_file("/bin/gnuplot"))
    {
      printf("Error: Gnuplot is missing.\n");
      return (1);
    }
  if ((fd = open(".tmp.dat", O_TRUNC | O_WRONLY | O_CREAT, 0666)) == -1)
    {
      printf("Error: open failed.\n");
      return (1);
    }
  if (ac < 2)
    {
      printf("Error: missing arguments.\n"
	     "Try './106bombyx --help' for"
	     " more informations.\n");
      return (1);
    }
  if (ac == 2 && !strcmp(av[1], "--help"))
    usage();
  else
    run_program(fd, ac, av);
  close(fd);
  return (0);
}
