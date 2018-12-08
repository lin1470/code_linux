<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-11-9
 * Time: 下午12:21
 */
//接受数据:保证安全
$dir = $_GET['dir'] ?? '';

//判断路径有效性;无效返回进入index.html

if(!is_dir($dir)){
    echo "路径无效";
    //return
    header('Refresh:3;url = index.html');
    exit;
}

//调用获取文件的函数的数据信息
include_once 'dirfile.php';

//使用函数
$files = dirfile($dir,$error);
//var_dump($files);
if(!$files){
    //路径无效
    echo $error;
    //跳转
    header('Refresh:3;url=index.html');
    //终止执行
    exit;
}


//包含显示文件信息的模板(HTML)文件
include_once "list.html";