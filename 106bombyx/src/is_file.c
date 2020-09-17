/*
** is_file.c for 106bombyx in /home/bourhi_a/rendu/106bombyx
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Feb 18 09:04:10 2014 
** Last update Tue Feb 18 09:17:56 2014 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <stdio.h>

int		is_file(char *path)
{
  struct stat	sb;

  if (!lstat(path, &sb))
    return (S_ISREG(sb.st_mode)) ? (1) : (0);
  return (0);
}
