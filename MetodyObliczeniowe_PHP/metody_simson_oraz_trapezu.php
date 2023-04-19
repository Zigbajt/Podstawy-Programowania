<!DOCTYPE html>
<html>
<body>

<h1>Obliczanie całki oznaczonej metodą Trapezów</h1>
<?php
	$N=10.0; //liczba punktów podziałowych
	$xp=0.0; //poczatek przedzialu calkowania
	$xk=1.0; //koniec przedzialu calkowania
    $h= (double)(($xk - $xp) / $N);
    $tabx[$N];
    $taby[$N];
	function f($x){
		return (12.0/((4.0*$x-9.0)*(4.0*$x-9.0))); //Nasza funkcja
        //return($x * $x + 3.0 * $x + 2.0);
	}
    $tabx[0]=$xp;
    $taby[0]=f($tabx[0]);
    echo("<br>");
    echo($tabx[0]);
    echo("<br>");
    echo($taby[0]);
    echo("<br>");
    for($j=1;$j<=$N;$j++){
    	$tabx[$j]=$xp+$j*$h;
        $taby[$j]=f($tabx[$j]);
        echo($tabx[$j]);
    	echo("<br>");
        echo($taby[$j]);
    	echo("<br>");
    }
	$s=($taby[0]+$taby[$N])/2.0;
    for($j=1;$j<$N;$j++){
    	$s= $s+$taby[$j];
    }
    $s= $s*($h);
	echo("Wartosc calki wynosi : ");
	echo($s);


?>

</body>
</html>



//simson

<!DOCTYPE html>
<html>
<body>

<h1>Obliczanie całki oznaczonej metodą Simpsona</h1>
<?php
	$N=10.0; //liczba punktów podziałowych
	$xp=0.0; //poczatek przedzialu calkowania
	$xk=1.0; //koniec przedzialu calkowania
    $h= (double)(($xk - $xp) / $N);
    $tabx[$N];
    $taby[$N];
	function f($x){
		return (12.0/((4.0*$x-9.0)*(4.0*$x-9.0))); //Nasza funkcja
        //return($x * $x + 3.0 * $x + 2.0);
	}
    $tabx[0]=$xp;
    $taby[0]=f($tabx[0]);
    echo("<br>");
    echo($tabx[0]);
    echo("<br>");
    echo($taby[0]);
    echo("<br>");
    for($j=1;$j<=$N;$j++){
    	$tabx[$j]=$xp+$j*$h;
        $taby[$j]=f($tabx[$j]);
        echo($tabx[$j]);
    	echo("<br>");
        echo($taby[$j]);
    	echo("<br>");
    }
	$s=0.0;
    for($j=0;$j<=$N;$j++){
    	if($j==0 || $j==$N){
        	$st=1;
        }else if($j%2 == 0){
        	$st=2;
        }else if($j%2 != 0){
        	$st=4;
        }
    	$s= $s+$st*$taby[$j];
    }
    $s= $s*($h/3);
	echo("Wartosc calki wynosi : ");
	echo($s);


?>

</body>
</html>