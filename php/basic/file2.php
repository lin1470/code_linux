<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-11-9
 * Time: 上午10:19
 */

// 读模式,如果不存在提示错误
$f1 = @fopen("hello","rb");

//写模式,不存在则创建
$f2 = @fopen("hello","wb");

$res = fwrite($f1,'<html><body>hello</body>');
var_dump($res);

//创建文件
touch("hello");
//读取指定长度
$res = fread("hello",1000);
echo $res;

//读取全部内容
//while(!feof($f)){
//    echo fread($f,1024);
//}


//删除文件
@unlink("h.php");
//关闭资源
fclose($f1);
fclose($f2);

echo "hello";
