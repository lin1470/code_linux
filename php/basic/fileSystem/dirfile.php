<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-11-9
 * Time: 下午12:26
 */

//一个函数:能够获取指定路径下所有的文件信息,以数组返回
/*
 * @param1 string $dir,有效路径
 * @param1 string &$error,错误信息
 * @param3 int $level =0,表示当前文件所在层级
 * @return array,所有元素的二维数组
 */

function dirfile($dir,&$error,$level = 0){
    if(!is_dir($dir)){
        $error = 'error path';
        return false;
    }
    //静态保存数据的数组
    static $output = array();
    //取数据;取出当前文件中的数据
    $files = scandir($dir);
    foreach($files as $file){
        //判断是文件还是文件夹
        $tmp_file = $dir .'/' .$file;
        if(is_dir($tmp_file)){
            $output[] = array(
                'filename' => $file,
                'directory' => $dir,
                'is_dir'=> true,
                'level'=> $level,
            );

            //递归点:排除.和..
            if($file == '.'|| $file == '..') continue;
            //递归
            dirfile($tmp_file,$error,$level+1);
        } else{
            $output[] = array(
                'filename' => $file,
                'directory' => $dir,
                'is_dir'=> false,
                'level'=> $level,
            );
        }


    }

    return $output;
}
//
//$dir = '/home/bruce/Downloads';
//$files = dirfile($dir,$error);
////var_dump($files);
//foreach($files as $file){
//    echo $file['directory'] .'/'.$file['filename'].'<br>';
//}