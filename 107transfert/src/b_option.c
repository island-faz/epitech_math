/*
** b_option.c for 107transfert in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar  3 23:27:42 2014 
** Last update Sun Mar 23 06:27:11 2014 
*/

#include <transfert.h>

t_arr		*char_to_arr(char *s)
{
  int		i;
  t_arr		*arr;  

  if (!(arr = malloc(sizeof(t_arr))))
    return (0);
  arr->length = nb_sep(s, '|') + 1;
  arr->arr = malloc(sizeof(int) * arr->length);
  i = arr->length - 1;
  while (i >= 0)
    {
      arr->arr[i] = atoi(s);
      while (*s && *s != '|')
	s++;
      s++;
      i--;
    }
  return (arr);
}

double		get_y(t_arr *arr, double x)
{
  int		i;
  double	y;

  i = 0;
  y = arr->arr[i++];
  while (i < arr->length)
    y = x * y + arr->arr[i++];
  return (y);
}

int		run_b(int ac, char **av)
{
  int		i;
  double	y;
  double	inc;
  int		fd_cmd;
  int		fd_file;
  char		cur_file[32];

  i = 1;
  system("exec rm -rf .tmp");
  if (!is_dir(TMP_DIR) && (mkdir(TMP_DIR, 0777)) == -1)
    xerror("Error: cannot creat tmp folder !\n");
  if ((fd_cmd = open(TMP_CMD, O_TRUNC | O_WRONLY | O_CREAT, 0666)) == -1)
    xerror("Error: Cannot creat cmd file !\n");
  dprintf(fd_cmd, "%s\n", XY_RNGE);
  while (i < ac && av[i + 1])
    {
      sprintf(cur_file, "%s/tmp%d.dat", TMP_DIR, i);
      if ((fd_file = open(cur_file, O_TRUNC | O_WRONLY | O_CREAT, 0666)) == -1)
	xerror("Error: Cannot creat data file !\n");
      inc = -10;
      while ((int)inc < 10)
  	{
	  if (get_y(char_to_arr(av[i + 1]), inc) != (double)0)
	    y = get_y(char_to_arr(av[i]), inc) / get_y(char_to_arr(av[i + 1]), inc);
	  dprintf(fd_file, "%f %f\n", inc, y);
  	  inc += 0.001;
  	}
      dprintf(fd_file, "%f %f\n", inc, y);
      close(fd_file);
      if (i == 1)
	dprintf(fd_cmd, "plot '%s' with lines notitle;\n", cur_file);
      else
	dprintf(fd_cmd, "replot '%s' with lines notitle;\n", cur_file);
      i += 2;
    }
  close(fd_cmd);
  system("gnuplot -p .tmp/cmd");
  return (1);
}
