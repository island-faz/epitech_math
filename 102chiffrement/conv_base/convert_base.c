/*
** convert_base.c<2> for covert_base in /home/bourhi_a/rendu/prog_elem/PSU_2013_my_printf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Nov 14 00:41:09 2013 bourhime amine
** Last update Thu Dec 26 05:25:54 2013 
*/

#include <stdlib.h>

char	*convert_base(unsigned int decimal, char *base_from, char *base_to)
{
  char	*final_result;
  if (!(final_result = malloc(128)))
    {
      return (0); 
    }
  final_result[my_putnbr_base(decimal, base_to, final_result)] = '\0';
  return (final_result);
}

int	main(int ac, char **av)
{
  if (my_getnbr(av[4]) == 0)
    {
      my_putstr(convert_base(my_getnbr(av[1]), av[2], av[3]));
    }
  else if (my_getnbr(av[4]) == 1)
    {
      my_putnbr(my_getnbr_base(av[1], av[3], 1));
    }
}
