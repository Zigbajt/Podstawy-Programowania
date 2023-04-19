<!DOCTYPE html>
<html>
<body>

<h1>Metoda eliminacji Gaussa</h1>

<?php
	function wypisz($tab,$w,$ww){
		echo('<table cellspacing="0" cellpadding="0" border="1" style="width: 100%;">');
        for($i=0;$i<$w;$i++){
        echo("<tr>");
			for($j=0;$j<$ww;$j++){
            	echo("<td>".$tab[$i][$j]."</td>");
			}
        echo("<tr>");
		}
    echo("</table>");
    echo("<br>");
	}
	function oblicz($tab,$w){
		$x=[$w];
		for($i=$w-1;$i>=0;$i--){
			if($i==$w-1){
				$mi=$tab[$i][$w];
				$x[$i]=$mi/$tab[$i][$i];
				echo($x[$i]."=".$mi."/".$tab[$i][$i]);
				echo("<br>");
                echo("<b>x<sup>".$i."</sup> = ".$x[$i].'</b>');
                echo("<br>");
			}else{
            	$liczba=0;
				$mi=$tab[$i][$w];
                for($j=$i+1;$j<$w;$j++){
                $liczba=$liczba+$tab[$i][$j]*$x[$j];
                //echo($liczba."=".$tab[$i][$j]."*".$x[$j]);
                //echo("<br>");
                //echo("-------");
                //echo("<br>");
                }
				$x[$i]=($mi-$liczba)/$tab[$i][$i];
				echo($x[$i]."=(".$mi."-(".$liczba."))/".$tab[$i][$i]);
				echo("<br>");
                echo("<b>x<sup>".$i."</sup> = ".$x[$i].'</b>');
                echo("<br>");
			}
		}
	}
	$ss=1;
	$s=1;
	$wielkosc=3;
    //odwrotnie wprowadzać dane
	$A=array(
		array(3.03,1.71,3.42),
		array(-4.45,1.28,-0.36),
		array(0.62,2.91,6.37),
	);
	$B=array(-2.6,3.36,5.75);
	$C1=[$wielkosc+1][$wielkosc+1];
	$C2=[$wielkosc+1][$wielkosc+1];
	$C3=[$wielkosc+1][$wielkosc+1];
	while($s<=3){
		if($s==1){
			for($z=0;$z<$wielkosc;$z++){
				for($j=0;$j<$wielkosc+1;$j++){
					if($j==$wielkosc){
						$C1[$z][$j]=$B[$z];
					}else{
						$C1[$z][$j]=$A[$z][$j];
					}
				}
			}
            echo("C<sub>".$s."</sub>");
			wypisz($C1,$wielkosc,$wielkosc+1);
		}else if($s==2){
			for($z=0;$z<$wielkosc;$z++){
				for($j=0;$j<$wielkosc+1;$j++){
					if($z==0){
						$C2[$z][$j]=$C1[$z][$j];
					}else{
						if($j==0){
							$C2[$z][$j]=0;
						}else{
                        	$liczba1=$C1[$z][$z-$z];
							$liczba2=$C1[$z-$z][$z-$z];
							$C2[$z][$j]=$C1[$z][$j]-(($liczba1/$liczba2)*$C2[$z-$z][$j]);
							echo($C2[$z][$j]."=".$C1[$z][$j]."-((".$liczba1."/".$liczba2.")*".$C1[$z-$z][$j]);
							echo("<br>");
						}		
					}
				}
			}
            echo("C<sub>".$s."</sub>");
			wypisz($C2,$wielkosc,$wielkosc+1);
		}else if($s==3){
			for($z=0;$z<$wielkosc;$z++){
				for($j=0;$j<$wielkosc+1;$j++){
					if($z==0 or $z==1){
						$C3[$z][$j]=$C2[$z][$j];
					}else{
                    	if($j==0 or $j==1){
							$C3[$z][$j]=0;
						}else{
							$liczba1=$C2[$z][$z-1];
							$liczba2=$C2[$z-1][$z-1];
							$C3[$z][$j]=$C2[$z][$j]-(($liczba1/$liczba2)*$C2[$z-1][$j]);
							echo($C3[$z][$j]."=".$C2[$z][$j]."-((".$liczba1."/".$liczba2.")*".$C2[$z-1][$j]);
							echo("<br>");	
                        }
					}
				}
			}
            echo("C<sub>".$s."</sub>");
			wypisz($C3,$wielkosc,$wielkosc+1);
		}
		$s++;
	}
	oblicz($C3,$wielkosc);
?> 

</body>
</html>