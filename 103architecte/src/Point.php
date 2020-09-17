<?php
// point.class.php for archi in /home/bourhi_a/rendu/103architecte
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Tue Dec 10 01:25:17 2013 
// Last update Fri Dec 13 22:11:14 2013 
//

class		Point
{
  public	$x;
  public	$y;

  function __construct($x, $y)
  {
    if (is_numeric($x) || is_numeric($y))
      {
	$this->x = (float)$x;
	$this->y = (float)$y;	
      }
  }

  function translate($vx, $vy)
  {
    $this->x += $vx;
    $this->y += $vy;
  }

  function scale($vx, $vy)
  {
    $this->x *= $vx;
    $this->y *= $vy;
  }

  function rotate($angle)
  {
    $tmp = ($this->x * cos($angle) - $this->y * sin($angle));
    $this->y = (sin($angle) * $this->x + cos($angle) * $this->y);
    $this->x = $tmp;
  }

  function symmetry($angle)
  {
    $tmp = ($this->x * cos($angle) + $this->y * sin($angle));
    $this->y = (sin($angle) * $this->x - cos($angle) * $this->y);
    $this->x = $tmp;
  }

  function __toString()
  {    
    $this->x = round($this->x, 3);
    $this->y = round($this->y, 3);
    $tmp = "(" . $this->x . "," . $this->y . ")";
    return ($tmp);
  }
}