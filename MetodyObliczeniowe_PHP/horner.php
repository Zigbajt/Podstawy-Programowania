<!DOCTYPE html>
<html>
<body>

<?php
    $w=array(1.0,0.0,0.3,-2.1,1.5,1.7);
    $x=0.7;
    $mlen=$w.count($w);
    $len=$mlen[5];
    
    function horner($tab,$x,$len){
    		$z=0.0;
            $y=(float)$tab[0];
            echo("---------".'<br>');
    		echo('tab = '.$tab[0].'<br>');
    		echo('z = '.$z.'<br>');
    		echo("y = ".$y.'<br>');
    		echo("---------".'<br>');
            $i=1.0;
            while($i<$len){
            	$z=((float)$y*(float)$x);
                $y=(float)$z+(float)$tab[$i];
                echo("---------".'<br>');
    			echo('tab = '.$tab[$i].'<br>');
    			echo('z = '.$z.'<br>');
    			echo("y = ".$y.'<br>');
    			echo("---------".'<br>');
                $i++;
                
            }
            
            return $y;
   }
    
    $wynik=horner($w,$x,$len);
    echo('W'.($len-1).'('.$x.') = '.$wynik.'<br>');
    
?>

</body>
</html>