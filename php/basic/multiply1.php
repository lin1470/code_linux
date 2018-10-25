<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-10-25
 * Time: 下午9:29
 */

function show(){

    for($i =0;$i<=9;$i++)
    {
        for($j = $i;$j<=9;$j++)
            echo $i."*".$j."=".$i*$j."   ";
        echo '<br/>';
    }
}
//echo show();