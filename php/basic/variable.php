<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-23
 * Time: 下午9:35
 */
$a =100;
var_dump($a);
echo "<br>";
//var_dump($_SERVER);
$b = $a;
$c = &$a;
$c = "abc";
echo $a,"~",$b,"~",$c;