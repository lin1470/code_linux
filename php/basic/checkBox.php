<?php
/**
 * Created by PhpStorm.
 * User: bruce
 * Date: 18-11-9
 * Time: 下午12:03
 */

//echo '<pre>';
//var_dump($_POST);
$hobby = $_POST['hobby'];
?>



篮球<input type="checkbox" name="hobby[]" <?php echo in_array('篮球',$hobby) ? 'checked="checked"' : '';?> value="篮球"/>
    足球<input type="checkbox" name="hobby[]" <?php echo in_array('足球',$hobby) ? 'checked="checked"' : '';?> value="足球"/>
    台球<input type="checkbox" name="hobby[]" <?php echo in_array('台球',$hobby) ? 'checked="checked"' : '';?> value="台球"/>
    品乓球<input type="checkbox" name="hobby[]" <?php echo in_array('乒乓球',$hobby) ? 'checked="checked"' : '';?> value="乒乓球"/>
    羽毛球<input type="checkbox" name="hobby[]" <?php echo in_array('羽毛球',$hobby) ? 'checked="checked"' : '';?> value="羽毛球"/>
    排球<input type="checkbox" name="hobby[]" <?php echo in_array('排球',$hobby) ? 'checked="checked"' : '';?> value="排球"/>