<?php
// functions.php for functions in /home/bourhi_a/rendu/102chiffrement/conv_base
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Sun Nov 24 04:15:56 2013 
// Last update Mon Nov 25 15:09:23 2013 
//

include 'exceptions.php';

function	verify_message($message)
{
  $message_len = strlen($message);
  $alpha = " abcdefghijklmnopqrstuvwxyz";
  $i = 0;
  while ($i < $message_len)
    {
      if (strpos($alpha, $message[$i]) !== false);
      else
	return (false);
      $i++;
    }
  return (true);
}

function	check_message_validty($message, $base)
{
  $base .= " ";
  for ($i = 0; $i < strlen($message); $i++)
    {
      if (strpos($base, $message[$i]) !== false);
      else
	MESSAGE_TO_CRYPT_WRONG();
    }
}

function	message_to_hash($message)
{
  $hash	= array();
  $alpha = " abcdefghijklmnopqrstuvwxyz";
  $alpha_len = strlen($alpha);
  $message_len = strlen($message);
  $i = 0;

  while ($i < $message_len)
    {
      $j = 0;
      while($j < $alpha_len)
	{
	  if ($message[$i] == $alpha[$j])
	    {
	      array_push($hash, $j);
	      $j = $alpha_len;
	    }
	  $j++;
	}
      $i++;
    }
  if (($message_len % 2) == 1)
    array_push($hash, 0);    
  return ($hash);
}

function	check_base($base)
{
  $base_len = strlen($base);

  for ($i = 0; $i < $base_len; $i++)
    {
      $l = 0;
      for ($j = 0; $j < $base_len; $j++ )
	if ($base[$i] == $base[$j])
	  $l++;
      if ($l > 1)
	WRONG_BASE_EXCEPTION();
    }
}

function	check_args($argc, $argv)
{  
  $key = array();

  if ($argc < 8)
    MISSING_ARGUMENTS_EXCEPTION();
  check_base($argv[6]);
  if ($argv[7] == 0)
    {
      if (!verify_message($argv[1]))
	FORBIDDEN_CHAR_EXCEPTION();
    }
  else if ($argv[7] == 1)
    check_message_validty($argv[1], $argv[6]);
  for ($i = 2; $i <= 5; $i++)
    if (!is_numeric($argv[$i]) || $argv[$i] < 0)
      KEY_WRONG_EXCEPTION();
    else
      array_push($key, $argv[$i]);
  if ($argv[7] != 0 && $argv[7] != 1)
    BAD_MODE_EXCEPTION();
  return ($key);
}

function	matrix_multiply($hash, $key)
{
  $res = array();

  for ($i = 0; $i < count($hash); $i += 2)
    {
      @array_push($res, ($hash[$i] * $key[0] + $hash[$i + 1] * $key[2]));
      @array_push($res, ($hash[$i] * $key[1] + $hash[$i + 1] * $key[3]));
    }
  return ($res);
}

function	inv_matrix($key)
{
  $val = $key[0] * $key[3] - $key[1] * $key[2];
  $key_inv = array();

  if ($val == 0)
    NON_INV_MATRIX_EXCEPTION();
  else
    {
      $val = 1 / $val;
      array_push($key_inv, $key[3] * ($val));
      array_push($key_inv, $key[1] * ($val) * -1);
      array_push($key_inv, $key[2] * ($val) * -1);
      array_push($key_inv, $key[0] * ($val));
    }
  return ($key_inv);
}