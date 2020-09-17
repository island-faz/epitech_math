<?php
// functions.php for archi in /home/bourhi_a/rendu/103architecte
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Thu Dec 12 02:33:30 2013 
// Last update Thu Dec 12 02:35:50 2013 
//

define("BAD_ARGS", "Bad arguments, try again !");
define("MISSING_ARGS", "Bad arguments, try again !");

function __autoload($class_name)
{
  include $class_name . '.php';
}

function xerror($error)
{
  echo $error . "\n";
  exit(1);
}

function check_args($argc, $argv)
{
  $array = array();
  if ($argc < 3 || !is_numeric($argv[1]) || 
      !is_numeric($argv[2]))
    xerror(MISSING_ARGS);
  else
    array_push($array, $argv[1], $argv[2]);
  for ($i = 3; $i < $argc; $i++)
    if (!is_numeric($argv[$i]) && 
	$argv[$i] != 'T' && $argv[$i] != 'H' &&
	$argv[$i] != 'R' && $argv[$i] != 'S')
      xerror(BAD_ARGS);
    else if ($argv[$i] == 'T' || $argv[$i] == 'H')
      if ($i + 2 >= $argc ||
	  !is_numeric($argv[$i + 1]) ||
	  !is_numeric($argv[$i + 2]))
	xerror(BAD_ARGS);
      else
	array_push($array, $argv[$i], $argv[$i + 1], 
		   $argv[$i + 2]);
    else if ($argv[$i] == 'R' || $argv[$i] == 'S')
      if ($i + 1 >= $argc || !is_numeric($argv[$i + 1]))
	xerror(BAD_ARGS);
      else
	array_push($array, $argv[$i], $argv[$i + 1]);
  return ($array);
}

function run_103($argy)
{
  $archi = new Archi($argy[0], $argy[1]);
  for ($i = 2; $i < count($argy); $i++)
    {
      if ($argy[$i] == 'T')
	$archi->translate($argy[$i + 1], $argy[$i + 2]);
      else if ($argy[$i] == 'H')
	$archi->scale($argy[$i + 1], $argy[$i + 2]);
      else if ($argy[$i] == 'R')
	$archi->rotate($argy[$i + 1]);
      else if ($argy[$i] == 'S')
	$archi->symmetry($argy[$i + 1]);
    }
  $archi->show_matrix();
  echo $archi->in_point . " => " . $archi->out_point . "\n";
}
