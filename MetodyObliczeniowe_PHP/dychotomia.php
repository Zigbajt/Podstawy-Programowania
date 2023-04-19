<!DOCTYPE html>
<html>
<body>

<h1>Metoda Dychotomii</h1>

<?php
function f($x) {
    return 4 * $x * sin($x);
}
function dychotomia($a,$b,$e,$d){
	while(tr){
     $xl=(($a+$b)/2.0)-($d/2.0);
     $xp=(($a+$b)/2.0)+($d/2.0);
     $fl=f($xl);
     $fp=f($xp);
     if($fl>=$fp){
     	echo($fl." >= ".$fp);
     	echo("</br>");
     	$a=$xl;
        echo("a = ".$a);
    	echo("</br>");
     }
	 if($fl<=$fp){
     	echo($fl." <= ".$fp);
     	echo("</br>");
     	$b=$xl;
        echo("b = ".$a);
    	echo("</br>");
     }
     if(abs($a-$b)<$e){
     	$wynik=($a+$b)/2.0;
        echo("</br>");
        echo("WARTOŚC WYNOSI = ".$wynik);
    	echo("</br>");
     	return($wynik);
     }
    }
}
dychotomia(-6.0, -3.0, 0.01, 0.01)
?> 

</body>
</html>
