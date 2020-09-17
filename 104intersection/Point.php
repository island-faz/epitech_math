<?php
// Point.php for 104intersection in /home/bourhi_a/rendu/104intersection
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Sat Jan  4 11:32:09 2014 
// Last update Sat Jan  4 14:59:21 2014 
//

class		Point
{
  public	$x;
  public	$y;
  public	$z;


  function __construct($x, $y, $z)
  {
    if (is_numeric($x) && is_numeric($y) && is_numeric($z))
      {
	$this->x = $x;
	$this->y = $y;
	$this->z = $z;
      }
  }

  function __toString()
  {    
    $tmp = "(" . $this->x . "," . $this->y . "," . $this->z .")";
    return ($tmp);
  }
}