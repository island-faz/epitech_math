<?php
// functions.php for 104intersections in /home/bourhi_a/rendu/104intersection
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Sat Jan  4 15:05:51 2014 
// Last update Sun Jan  5 23:07:35 2014 
//

function check_args($argc, $argv)
{
  if ($argc < 9)
    {
      echo "Missing args\n";
      exit(0);
    }
  for ($i = 1; $i < 9 ; $i++)
    if (!is_numeric($argv[$i]))
      {
	echo "Bad args\n";
	exit(0);
      }  
}

function sphere_intersection($r, $v, $p)
{
  $inter_secs = array();
  $eq = new Equation_2d();
  $eq->add_a($v->x * $v->x);
  $eq->add_a($v->y * $v->y);
  $eq->add_a($v->z * $v->z);
  $eq->add_b(2 * $v->x * $p->x);
  $eq->add_b(2 * $v->y * $p->y);
  $eq->add_b(2 * $v->z * $p->z);
  $eq->add_c($p->x * $p->x);
  $eq->add_c($p->y * $p->y);
  $eq->add_c($p->z * $p->z);
  $eq->add_c($r * $r *-1);
  $ret = $eq->solve_equation();
  for ($i = 0; $i < count($ret); $i++)
    {
      array_push($inter_secs,
		 new Point($v->x * round($ret[$i], 3) + $p->x,
			   $v->y * round($ret[$i], 3) + $p->y,
			   $v->z * round($ret[$i], 3) + $p->z));
    }
  echo "droite passant par le point " . $p . ", de vecteur directeur " . $v . "\n";
  return ($inter_secs);
}

function cylindre_intersection($r, $v, $p)
{
  $inter_secs = array();
  $eq = new Equation_2d();
  $eq->add_a($v->x * $v->x);
  $eq->add_a($v->y * $v->y);
  $eq->add_b(2 * $v->x * $p->x);
  $eq->add_b(2 * $v->y * $p->y);
  $eq->add_c($p->x * $p->x);
  $eq->add_c($p->y * $p->y);
  $eq->add_c($r * $r * -1);
  $ret = $eq->solve_equation();
  for ($i = 0; $i < count($ret); $i++)
    {
      array_push($inter_secs,
		 new Point($v->x * round($ret[$i], 3) + $p->x,
			   $v->y * round($ret[$i], 3) + $p->y,
			   $v->z * round($ret[$i], 3) + $p->z));
    }
  echo "droite passant par le point " . $p . ", de vecteur directeur " . $v . "\n";
  return ($inter_secs);
}

function cone_intersection($angle, $v, $p)
{
  $inter_secs = array();
  $angle = $angle * pi() / 180;
  $tmp = tan($angle) * tan($angle) * -1;
  $eq = new Equation_2d();
  $eq->add_a($v->x * $v->x);
  $eq->add_a($v->y * $v->y);
  $eq->add_a($v->z * $v->z / $tmp);
  $eq->add_b(2 * $v->x * $p->x);
  $eq->add_b(2 * $v->y * $p->y);
  $eq->add_b(2 * $v->z * $p->z / $tmp);
  $eq->add_c($p->x * $p->x);
  $eq->add_c($p->y * $p->y);
  $eq->add_c($p->z * $p->z / $tmp);
  $ret = $eq->solve_equation();
  for ($i = 0; $i < count($ret); $i++)
    {
      array_push($inter_secs,
		 new Point(round($v->x * $ret[$i] + $p->x, 3),
			   round($v->y * $ret[$i] + $p->y, 3),
			   round($v->z * $ret[$i] + $p->z, 3)));
     }
  echo "droite passant par le point " . $p . ", de vecteur directeur " . $v . "\n";
  return ($inter_secs);
}