/*
** put_equation.c for 107transfert in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar  3 00:13:33 2014 
** Last update Mon Mar  3 00:14:37 2014 
*/

#include <stdio.h>
#include <transfert.h>

void	put_equation(t_arr arr)
{
  int	i = 0;
  int	flag = 0;

  while (i < arr.length)
    {
      if (arr.arr[i] != 0 && (flag = 1))
	{
	  printf("%d", !i ? arr.arr[i] : ABS(arr.arr[i]));
	  if (arr.length - i - 1 != 0)
	    if (arr.length - i - 1 == 1 && printf("x"));
	    else
	      printf("x^%d", arr.length - i - 1);
	}
      if (i + 1 < arr.length && arr.arr[i + 1] != 0)
	if (arr.arr[i + 1] > 0)
	  flag ? printf(" + ") : 1;
	else
	  printf(!flag ? "-" : " - ");
      i++;
    }
}
