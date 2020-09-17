/*
** main.c for 107transfert in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar  2 04:25:05 2014 
** Last update Mon Mar  3 23:28:07 2014 
*/

#include <transfert.h>

int		main(int ac, char **av)
{
  int		i;
  t_arr		arr;
  char		*param;

  i = 0;
  if (ac < 2)
    {
      printf("Missing args !\n");
      return (1); 
    }
  param = strdup(av[1]);
  arr.length = nb_sep(av[1], '|') + 1;
  arr.arr = malloc(sizeof(int) * arr.length);
  while (i < arr.length)
    {
      arr.arr[i] = atoi(param);
      while (*param && *param != '|')
	param++;
      param++;
      i++;
    }
  if (ac == 2)
    run_a(arr);
  else
    run_b(ac, av);
  return (0);
}
