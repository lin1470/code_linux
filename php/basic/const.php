<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-23
 * Time: 下午10:13
 */
//定义常量
define('PI',3.14);
define('SELF_PI',3);
const FAMILY_NAME = 'Green';
define('-_-','SIMLE');

//访问常量
echo PI,'<br/>';
//echo -_-;
echo constant('-_-');

//系统常量
echo PHP_VERSION;
echo PHP_INT_MAX;
echo PHP_INT_SIZE;
echo PHP_INT_MIN,'<br/>';

//魔术常量
echo __DIR__,"<br/>";
echo __FILE__,"<br/>";
echo __LINE__,"<br/>";
echo __LINE__,"<br/>";
