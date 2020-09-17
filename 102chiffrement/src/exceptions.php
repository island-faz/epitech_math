<?php
// exceptions.php for exceptions in /home/bourhi_a/rendu/102chiffrement/conv_base
// 
// Made by amine bourhime
// Login   <bourhi_a@epitech.net>
// 
// Started on  Sun Nov 24 04:13:35 2013 
// Last update Mon Nov 25 14:56:31 2013 
//

function	FORBIDDEN_CHAR_EXCEPTION()
{
  $alpha = "abcdefghijklmnopqrstuvwxyz ";
  echo "Error : Message contain forbidden characters !\n";
  echo "Allowed characters : \"" . $alpha . "\"\n";
  echo "Please try again.\n";
  exit(0);
}

function	MISSING_ARGUMENTS_EXCEPTION()
{
  echo "Error : One or many arguments is missing !\n";
  echo 'Usage exemple to crypt: ./102chiﬀrement "av czar" 2 5 1 3 "CESAR" 0' . "\n";
  echo 'Usage exemple to decrypt: ./102chiﬀrement "RR SRE A ER SCA ECEA ESE AAC" 2 5 1 3 "CESAR" 1' . "\n";
  echo "Please try again.\n";
  exit(0);
}

function	KEY_WRONG_EXCEPTION()
{
  echo "Error : Key is wrong, it must be numeric and positif !\n";
  echo "Please try again.\n";
  exit(0);
}

function	BAD_MODE_EXCEPTION()
{
  echo "Error : mode is wrong, last argument must be '0' to crypt and '1' to decrypt !\n";
  echo "Please try again.\n";
  exit(0);
}

function	NON_INV_MATRIX_EXCEPTION()
{
  echo "Error : key must be inversible !\n";
  echo "Choose another key, Please.\n";
  exit(0);
}

function	WRONG_MESSAGE_TO_CRYPT()
{
  echo "Error : wrong key or message to crypt !\n";
  echo "Please try again.\n";
  exit(0);
}

function	WRONG_BASE_EXCEPTION()
{
  echo "Error : wrong base !\n";
  echo "Please try again.\n";
  exit(0);
}

function	MESSAGE_TO_CRYPT_WRONG()
{
  echo "Error : wrong crypted message !\n";
  echo "Please try again.\n";
  exit(0);  
}