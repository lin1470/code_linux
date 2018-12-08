<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-25
 * Time: 下午9:11
 */

$username = '张三';
//echo $username;
//已有样式,可以直接使用数据
//向下包含.
include 'include4.html';

include_once '11.html';  //没有这个文件的话,会报警告,而不是错误.
//require_once '11.html'; 这个如果代码出错的话,直接会报错.