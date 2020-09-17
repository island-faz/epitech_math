/*
** usage.c for 106bombyx in /home/bourhi_a/rendu/106bombyx
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Feb 18 09:05:04 2014 
** Last update Tue Feb 18 09:07:21 2014 
*/

#include <stdio.h>

int	usage()
{
  printf("106bombyx is a small program (using gnuplot) that can draw a graphic "
	 "representation of butterflies population evolution.\n"
	 "The first generation contain 10 butterflies.\n"
	 "Tne next generation will be computed using the folowin sequence.\n\n"
	 "\tx[1] = 10\n"
	 "\tx[i] = k * x[i - 1] * (1000 - x[i - 1]) / 1000\n\n"
	 "usage :\n\n"
	 "\t./106bombyx [k]\n\n"
	 "\t\tk : constant represent ressources where k between 1 and 4.\n"
	 "Or\n\n"
	 "\t./106bombyx [i_min] [i_max].\n\n"
	 "\t\ti_min : generation from.\n"
	 "\t\ti_max : generation to.\n"
	 "\t\twhere i_min > i_max and i_min >= 1.\n");
  return (1);
}
