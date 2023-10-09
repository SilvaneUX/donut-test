<!DOCTYPE html>


<html>

<head>

<title></title>


</head>

<body>

<form action="konverter.php" method="get">


<input type="text" name="dollar" placeholder="Masukan Angka Dollar"/>


<input type="submit" name="submit" value="Convert">

</form>


$dollar = $_GET['dollar'];


<?php  


error_reporting(E_ALL ^ (E_NOTICE | E_WARNING));


echo "$dollar US dollar = Rp ". number_format($rupiah, 0, ".", ".")."<br />";


$rupiah = $dollar * 10000;

echo "<br>";

 ?>
</body>

</html>