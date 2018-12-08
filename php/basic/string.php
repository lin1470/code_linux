<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-24
 * Time: 下午9:45
 */
// 双引号和单引号问题
$str = 'hey';
$str1 = '$str,world.';
$str2 = "$str,world.";

// nowdoc模式
$str3 =<<<'END'
    $str hello world!
    hello world
END;
// Heredoc模式
$str4 =<<<BEGIN
    $str hello wrold
    hello world
BEGIN;

echo $str;
echo $str1;
echo $str2;
echo $str3;
echo $str4;
