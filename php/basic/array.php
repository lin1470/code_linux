<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-24
 * Time: 下午10:16
 */
//索引数组
$arr1 = array(1,2,3,4,5);
//关联数组
$arr2 = array('name' => '张三','age' => 30,'gender' => '男');
//混合数组
$arr3 = array(1,2,'name' => '张三','age' => 30);

$arr4 = array(1=>1,10=>10,100=>100);
// 默认的从最大的开始递增
$arr4[] = 10000;
// 不会自动根据索引大小来排序.
$arr4[2] = 102;
var_dump($arr4);