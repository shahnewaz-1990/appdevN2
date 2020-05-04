/*Can't figure out how to linking it with other file */


<?php
$file= 'testcurl.txt';
$numbers= $_POST['db'];
$str= date("M d Y H:i:s",time()).' '.$values."\n";

if(file_exists($file)){
	$fp=fopen($file,a);
	fwrite($fp, $str);
	fclose($fp);
}
	else{
	$fp = fopen($file,w);
	fwrite($fp, $str);
	fclose($fp);
}
?> 
