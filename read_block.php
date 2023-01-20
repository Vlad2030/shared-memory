<?php 



$systemid = ftok(__FILE__, 't');

echo "systemid = $systemid\n";


$mode = "c"; 
// Режим доступа 
$permissions = 0777; 
// Разрешения для сегмента общей памяти, 0755 не даст изменять другим скриптам
$size = 4096; 
// Размер сегмента в байтах 


// откроет или создаст если не существует сегмент 
$shmid = shmop_open($systemid, $mode, $permissions, $size); 

// 1024 это до какого символа выводить содержимое
echo shmop_read($shmid, 0, $size);

// отсоединяюсь от сегмента
shmop_close($shmid); 





?>