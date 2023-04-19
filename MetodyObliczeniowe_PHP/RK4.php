<!DOCTYPE html>
<html>
<body>

<h1>Rozwiązywanie równań różniczkowych zwyczajnych - Rungego Kutty </h1>

<?php
 
function dydx($x, $y)
{
    return(1.6*$x + 0.5*$y**2);
}
 
function rungeKutta($x0, $y0, $x, $h)
{
     
    $n = (($x - $x0) / $h);
 
    $k1; $k2; $k3; $k4; $k5;

    $y = $y0;
    
    echo("<br>");
    echo("------------------------------------");
    echo("<br>");
    for($i = 1; $i <= $n; $i++)
    {
    	echo("<h3> Iteracja ".$i."</h3>");
        $k1 = $h * dydx($x0, $y);
        echo("k1 =".$h." * ".dydx($x0, $y)." = ".$k1);
        echo("<br>");
        $k2 = $h * dydx($x0 + 0.5 * $h,$y + 0.5 * $k1);
        echo("k2 =".$h." * ".dydx($x0 + 0.5 * $h,$y + 0.5 * $k1)." = ".$k2);
        echo("<br>");
        $k3 = $h * dydx($x0 + 0.5 * $h,$y + 0.5 * $k2);
        echo("k3 =".$h." * ".dydx($x0 + 0.5 * $h,$y + 0.5 * $k2)." = ".$k3);
        echo("<br>");
        $k4 = $h * dydx($x0 + $h, $y + $k3);
 		echo("k4 =".$h." * ".dydx($x0 + $h, $y + $k3)." = ".$k4);
        echo("<br>");
        $yyyy=$y;
        $y = $y + (1.0 / 6.0) * ($k1 + 2 *$k2 + 2 * $k3 + $k4);;
        echo("y =".$yyyy."+ (1.0 / 6.0) * ".($k1 + 2 *$k2 + 2 * $k3 + $k4)." = ".$y);
        echo("<br>");
        $xx00=$x0;
        $x0 = $x0 + $h;
        echo("x0 = ".$xx00." + ".$h." = ".$x0);
        echo("<br>");
        echo("------------------------------------");
        echo("<br>");
    }
 	echo ("The value of y at x is : ".$y);
    return $y;
}
    $x0 = 0;
    $y = 0.3;
    $x = 1;
    $h = 0.1;
    rungeKutta($x0, $y, $x, $h);
?>

</body>
</html>
