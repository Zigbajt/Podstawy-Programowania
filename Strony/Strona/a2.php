<!DOCTYPE HTML>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" href="../style.css">
        <title>Formularz a2</title>
    </head>
    <body>
        <div id="container">
        <header>
            <h1>Dawid Maciejski Kacper Kurek 314A</h1>
        </header>
        <div id="gorny">
            <h2>Menu górne</h2>
            <a href=""><div class="wybor">
            <p>d1</p>
            </div></a>
            <a href=""><div class="wybor">
            <p>d2</p>
            </div></a>
            <a href=""><div class="wybor">
            <p>d3</p>
            </div></a>
            <a href=""><div class="wybor">
            <p>d4</p>
            </div></a>
            <div id="oo"></div>
        </div>
        <div id="lewy">
            <h2>Menu Lewe</h2>
            <a href="index.html"><div class="opcja">
            <p>Strona główna</p>
            </div></a>
            <a href="Podstrony/obrazy.html"><div class="opcja">
            <p>Obrazy</p>
            </div></a>
            <a href="Podstrony/Dokumnety.html"><div class="opcja">
            <p>Dokumenty</p>
            </div></a>
            <a href="Podstrony/Formularz.html"><div class="opcja">
            <p>Formularze</p>
            </div></a>
        </div>
        <div id="main">
            <head>
                <h2>Formularze a2.php</h2>
            </head>
			<p>
				<?php
    if(isset($_POST['submit'])){
        $imie=htmlspecialchars($_POST['imie']);
        $wiek=$_POST['wiek'];
        if($_POST['select']=="-"){
            echo("brak plec");
        }else if($_POST['select']=="K"){
            $plec="Kobietą";
        }else if($_POST['select']=="M"){
            $plec="Mężczyzną";
        }
        $wzrost=$_POST['radio'];
        $sprawnosc=$_POST['A1'];
        $multi=$_POST['multi'];
        $tekst=htmlspecialchars($_POST['A']);
        $mail=$_POST['mail'];
        $haslo=htmlspecialchars($_POST['haslo']);
        
        echo("Cześć ".$imie." masz ".$wiek." lat. Jesteś ".$plec." o ".$wzrost." wzroście.");
        echo("<br>");
        echo("Niepelnosprawnosc: ".$sprawnosc);
        echo("<br>");
        echo("Praca: ".$multi);
        echo("<br>");
        echo("Opis: ".$tekst);
        echo("<br>");
        echo("Haslo: ".$haslo);
    }

?>
			<p>
        </div>
        <div id="footer">
            <p>14.11.2022</p>
        </div>
        </div>
    </body>
</html>