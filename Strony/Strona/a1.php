<!DOCTYPE HTML>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" href="../style.css">
        <title>Formularz a1</title>
    </head>
    <body>
        <div id="container">
        <header>
            <h1>Dawid Maciejski Kacper Kurek 314A</h1>
        </header>
        <div id="gorny">
            <h2>Menu górne</h2>
            <a href=""><div class="wybor">
            <p>s1</p>
            </div></a>
            <a href=""><div class="wybor">
            <p>s2</p>
            </div></a>
            <a href=""><div class="wybor">
            <p>s3</p>
            </div></a>
            <a href=""><div class="wybor">
            <p>s4</p>
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
                <h2>Formularze a1.php</h2>
            </head>
            <form action="/a2.php" method="post">
                <label for="imie">Imie:</label><br>
                <input type="text" id="imie" name="imie" value=""><br>
                <label for="wiek">Wiek:</label><br>
                <input type="number" id="wiek" name="wiek" min="18" max="100"><br>
                <label>Płeć:</label><br>
                <select name="select">
                    <option>-</option>
                    <option>M</option>
                    <option>K</option>
                </select><BR>
                <label>Czy jestes niepelnosprawny</label><br>
                <input type="checkbox" name="A1" id="uu" value="tak">
                <label>Tak</label><br>
                <input type="checkbox" name="A1" id="uu" value="nie">
                <label>Nie</label><br>
                <br>
                <label>Jezeli tak opisz</label><br>
                <textarea name="A"></textarea><br>
                <select name="multi" multiple="multi">
                    <option>Pracujący</option>
                    <option>Bezrobotny</option>
                </select><br>
                                                      
                <label>Wzrost:</label>
                <label>N</label>
                <input type="radio" name="radio" value="Niskim" />
                <label>S</label>
                <input type="radio" name="radio" value="Srednim" />
                <label>W</label>
                <input type="radio" name="radio" value="Wysokim" />
                <br>
                <label for="mail">Email:</label><br>
                <input type="email" id="mail" name="mail" value=""><br>
                <label for="haslo">Hasło:</label><br>
                <input type="password" id="haslo" name="haslo"><br><br>
                <input type="reset" value="Wyczyść">
                <input type="submit" name="submit" value="Wyślij">
</form>
        </div>
        <div id="footer">
            <p>14.11.2022</p>
        </div>
        </div>
    </body>
</html>