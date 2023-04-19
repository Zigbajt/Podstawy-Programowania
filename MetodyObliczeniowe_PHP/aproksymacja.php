<!DOCTYPE html> 
<html> 
<body> 
 
<h1>Aproksymacja – Metoda Najmniejszych Kwadratów</h1> 
 
<?php 
	function Wypisz($tab,$p,$sum,$a){ 
		echo('<table cellspacing="0" cellpadding="0" border="1" style="width: 100%;">'); 
		for($i=0;$i<=$p;$i++){ 
			echo("<tr>"); 
			if($i==$p){ 
				for($z=0;$z<5;$z++){ 
					echo("<td><b>".$sum[$z]."</b></td>"); 
				} 
			}else{ 
				for($j=0;$j<5;$j++){ 
					echo("<td>".$tab[$j][$i]."</td>"); 
				} 
			} 
			
			
			echo("<tr>"); 
		} 
		echo("</table>"); 
		echo("<br>"); 
		echo($sum[0]."*a<sub>0</sub>+".$sum[1]."*a<sub>1</sub>=".$sum[3]);
		echo("<br>"); 
		echo($sum[1]."*a<sub>0</sub>+".$sum[2]."*a<sub>1</sub>=".$sum[4]); 
		echo("<br>"); 
		echo("<br>"); 
		echo("a<sub>0</sub> = ".$a[0]); 
		echo("<br>"); 
		echo("a<sub>1</sub> = ".$a[1]); 
		echo("<br>"); 
		echo("<br>"); 
		if($a[1]>0){ 
			echo("Q<sub>m</sub>(x) = ".$a[0]."+".$a[1]."x"); 
		}else{ 
			echo("Q<sub>m</sub>(x) = ".$a[0]."".$a[1]."x"); 
		} 
	} 
	function Tabela($tab,$tabX,$tabY,$p){ 
		for($i=0;$i<5;$i++){ 
			for($j=0;$j<$p;$j++){ 
				if($i==0){ 
					$tab[$i][$j]=1; 
				}else if($i==1){ 
					$tab[$i][$j]=$tabX[$j]; 
				}else if($i==2){ 
					$tab[$i][$j]=pow($tab[$i-1][$j],2); 
				}else if($i==3){ 
					$tab[$i][$j]=$tab[$i-3][$j]*$tabY[$j]; 
				}else if($i==4){ 
					$tab[$i][$j]=$tab[$i-3][$j]*$tabY[$j]; 
				} 
			} 
		} 
		return $tab; 
	} 
	function Sumuj($tab,$sum,$p){ 
		$tmp; 
		for($i=0;$i<5;$i++){ 
			$tmp=0; 
			for($j=0;$j<$p;$j++){ 
				$tmp+=$tab[$i][$j]; 
			} 
				$sum[$i]=$tmp; 
		} 
		return $sum; 
	} 
	function Wylicz($sum,$xy){ 
		$W=$sum[0]*$sum[2]-$sum[1]*$sum[1]; 
		$Wa0=$sum[3]*$sum[2]-$sum[4]*$sum[1]; 
		$Wa1=$sum[0]*$sum[4]-$sum[1]*$sum[3]; 
		$a[0]=$Wa0/$W; 
		$a[1]=$Wa1/$W; 
		return $a; 
	} 
	$punkty=10; 
	$tabX=array( 
	-2.25, 
	1.9, 
	0.19, 
	-0.5, 
	-1.09, 
	0.94, 
	-0.13, 
	-0.5, 
	-0.67, 
	1.1 
	); 
	$tabY=array( 
	-19.2, 
	-21.41, 
	-9.90, 
	-19.56, 
	-0.3, 
	-12.04, 
	1.14, 
	11.26, 
	4.45, 
	-3.27 
	); 
	$rezultat=[$punkty][$punkty]; 
	$sum=[5]; 
	$a=[2]; 
	$rezultat=Tabela($rezultat,$tabX,$tabY,$punkty); 
	$sum=Sumuj($rezultat,$sum,$punkty); 
	$a=Wylicz($sum,$a); 
	wypisz($rezultat,$punkty,$sum,$a); 
	
?> 
 
</body> 
</html>