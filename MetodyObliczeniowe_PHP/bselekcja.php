<!DOCTYPE html>
<html>
<body>

<h1>Rozwiązywanie równań nieliniowych - Metoda bisekcji</h1>

<?php
// Zdefiniuj funkcję, której zerowe miejsce chcemy znaleźć
function f($x) {
  return sqrt($x)-cos(0.374+$x);
}

// Zdefiniuj przedział, w którym szukamy zerowego miejsca funkcji
$a = -1;
$b = 1;

// Zdefiniuj dokładność, z jaką szukamy zerowego miejsca
$eps = 0.01;

// Uruchom pętlę wyszukiwania zerowego miejsca
$ff=1;
while (abs($a - $b) > $eps) {
  echo("Iteracja".$ff);
  echo("<br>");
  echo("x<sub>1</sub> = ".$a."   x<sub>2</sub> = ".$b);
  echo("<br>");
  
  $c = ($a + $b) / 2;
  echo("x =(".$a."+". $b.") / 2 = ".$c);
  echo("<br>");
  
  $y=f($a) * f($c);
  echo("y = ".$y);
  echo("<br>");
  
  if ($y <= 0) {
    $b = $c;
    echo("|F(x)|> eps");
  	echo("<br>");
  } else {
    $a = $c;
    echo("|F(x)|< eps");
  	echo("<br>");
  }
  echo("");
  echo("<br>");
  $ff++;
}

// Wyświetl wynik
echo "Zerowe miejsce funkcji wynosi: " . ($a + $b) / 2;
?> 

</body>
</html>
