<?php
// architecte.clas.php for archi in /home/bourhi_a/rendu/103architecte
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Tue Dec 10 01:23:08 2013 
// Last update Wed Dec 11 05:12:58 2013 
//

class		Archi
{
  public	$matrix;
  public	$in_point;
  public	$out_point;

  function __construct($x, $y)
  {
    $this->in_point = new Point($x, $y);
    $this->out_point = new Point($x, $y);
    $this->matrix = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
  }

  function translate($vx, $vy)
  {
    $tmp = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $tmp[0][2] = $vx;
    $tmp[1][2] = $vy;
    $this->matrix = Archi::multiply_matrix($tmp, $this->matrix);
    $this->out_point->translate($vx, $vy);
    echo "translation de vecteur (" . $vx . "," . $vy . ")\n";
  }

  function scale($vx, $vy)
  {
    $tmp = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $tmp[0][0] = $vx;
    $tmp[1][1] = $vy;
    $this->matrix = Archi::multiply_matrix($tmp, $this->matrix);
    $this->out_point->scale($vx, $vy);
    echo "homothétie de rapports " . $vx . " et " . $vy ."\n";
  }

  function rotate($d_angle)
  {
    $angle = M_PI * ($d_angle / 180);
    $tmp = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $tmp[0][0] = cos($angle);
    $tmp[0][1] = -sin($angle);
    $tmp[1][0] = sin($angle);
    $tmp[1][1] = cos($angle);
    $this->matrix = Archi::multiply_matrix($tmp, $this->matrix);
    $this->out_point->rotate($angle);
    echo "rotation d’angle ". $d_angle . " degrés\n";
  }

  function symmetry($d_angle)
  {
    $angle = 2 * M_PI * ($d_angle / 180);
    $tmp = array(array(1, 0, 0),
		 array(0, 1, 0),
		 array(0, 0, 1));
    $tmp[0][0] = cos($angle);
    $tmp[0][1] = sin($angle);
    $tmp[1][0] = sin($angle);
    $tmp[1][1] = -cos($angle);
    $this->matrix = Archi::multiply_matrix($tmp, $this->matrix);
    $this->out_point->symmetry($angle);
    echo "symétrie par rapport à un axe incliné de " . $d_angle ." degrés\n";
  }

  function show_matrix()
  {
    for ($i = 0; $i < 3; $i++)
      printf("\t%-6.3f  %-6.3f  %.3f\n",
	     $this->matrix[$i][0],
	     $this->matrix[$i][1],
	     $this->matrix[$i][2]);
  }

  public static function multiply_matrix($m_1, $m_2)
  {
    $tmp = array(array(0, 0, 0),
		 array(0, 0, 0), 
		 array(0, 0, 0));
    for ($i = 0; $i < 3; $i++)
      for ($k = 0; $k < 3; $k++)
	for ($j = 0; $j < 3; $j++)
	  $tmp[$i][$k] += $m_1[$i][$j] * $m_2[$j][$k];
    return ($tmp);
  }
}