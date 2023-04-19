<!DOCTYPE html>
<html> 
<body> 
 
<h1>Różniczkowanie numeryczne – Wzór Taylora</h1> 
 
<?php 
	function Wypisz($tab,$p){ 
		echo('<table cellspacing="0" cellpadding="0" border="1" style="width: 100%;">'); 
		$z=$p; 
		for($i=0;$i<$p;$i++){ 
			echo("<tr>"); 
			for($j=0;$j<=$z;$j++){ 
				echo("<td>".$tab[$j][$i]."</td>"); 
			} 
			if($i>1){ 
			} 
			echo("<tr>"); 
		} 
		echo("</table>"); 
	} 
	function Tabela($rezultat,$tabX,$tabY,$p){ 
		$z=$p; 
		$yy=0; 
		for ($i=0;$i<$p+1;$i++){ 
			for ($j=$z;$j>=0;$j--){
				if($i==0){ 
					$rezultat[$i][$j]=$tabX[$j]; 
				}else if($i==1){ 
					$rezultat[$i][$j]=$tabY[$j]; 
				}else{ 
					if($j<$yy){ 
					
					}else{ 
						$rezultat[$i][$j]=($rezultat[$i-1][$j]-$rezultat[$i-1][$j-1]); 
					}
				} 
				
			} 
			if($i>0){ 
				$yy++; 
			} 
		} 
		return $rezultat; 
	} 
	function Konwertuj($tab,$tab1,$p){ 
		$yy=$p-1; 
		for ($i=0;$i<$p;$i++){ 
		$tab1[$i]=$tab[$yy]; 
		$yy--; 
		} 
		return $tab1; 
		} 
		function Wylicz($tab,$h,$k,$p){ 
		if($k==1){ 
			for($i=1;$i<$p;$i++){ 
				if($i==1){ 
					echo("<br>"); 
					echo("f<sub>(x)</sub><sup>(".$k.")</sup> = "); 
					echo($tab[$i+1][$p-1]." + "); 
					$f=$tab[$i+1][$p-1]; 
				}else{ 
					echo(" 1/".$i."(".$tab[$i+1][$p-1].") + "); 
					$f+=(1/$i)*$tab[$i+1][$p-1]; 
				}
			}
			echo("<br>"); 
			$wynik=1/$h*$f; 
			
		} 
		return $wynik; 
	} 
	$punkty=7; 
	$tabx=array( 
	3.0, 
	3.2, 
	3.4, 
	3.6, 
	3.8, 
	4.0, 
	4.2 
	); 
	$taby=array( 
	-5.0, 
	-9.37, 
	-12.09, 
	-13.63, 
	-14.74, 
	-16.89, 
	-17.02 
	); 
	$tabX=[$punkty]; 
	$tabY=[$punkty]; 
	$tabX=Konwertuj($tabx,$tabX,$punkty); 
	$tabY=Konwertuj($taby,$tabY,$punkty); 
	$k=1; 
	$h=$tabX[1]-$tabX[0]; 
	$rezultat=[$punkty][$punkty]; 
	$rezultat=Tabela($rezultat,$tabX,$tabY,$punkty); 
	wypisz($rezultat,$punkty); 
	echo("<br>"); 
	echo("h = ".$h); 
	$w=Wylicz($rezultat,$h,$k,$punkty); 
	echo("<br>"); 
	echo("f<sub>(x)</sub><sup>(".$k.")</sup> = ".$w); 
	
?> 
</body> 
</html>