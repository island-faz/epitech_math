<?php
// Droite.php for 104intersection in /home/bourhi_a/rendu/104intersection
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Sat Jan  4 11:31:59 2014 
// Last update Sat Jan  4 13:07:56 2014 
//

class		Droite
{
  public	$p;
  public	$v;

  function __construct($vx, $vy, $vz, $px, $py, $pz)
  {
    if (is_numeric($vx) && is_numeric($vy) && is_numeric($vz) &&
	is_numeric($px) && is_numeric($py) && is_numeric($pz))
      {
	$this->v = new Point($vx, $vy, $vz);
	$this->p = new Point($px, $py, $pz);
      }
  }

  function __toString()
  {    
    return "droite passant par le point " . $p . ", de vecteur directeur " . $v;
  }
}