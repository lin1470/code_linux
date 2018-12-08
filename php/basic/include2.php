<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-25
 * Time: 下午9:10
 */
//包含文件:向上包含
//include 'include1.php';

show();
echo PI;

// 再次包含  //前面包含已经重名的.
//include 'include1.php';

include 'include1.php'; // 只有动态运行到这里代码才会加载到内存里面.

show();
echo PI;
