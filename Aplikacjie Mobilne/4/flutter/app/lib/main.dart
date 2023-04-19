import 'dart:convert';
import 'dart:io';
import 'package:flutter/material.dart';
import 'package:flutter_hooks/flutter_hooks.dart';
import 'package:http/http.dart' as http;

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        colorSchemeSeed: const Color(0xff6750a4),
      ),
      title: 'Lab4',
      home: MyView(),
    );
  }
}

// Klasa widoku zawierająca komponent Text
class MyView extends StatefulWidget {
  @override
  _MyViewState createState() => _MyViewState();
}

class _MyViewState extends State<MyView> {
  // Pole przechowujące dane pobrane z endpointu
  dynamic data;
  bool isLoading = true;

  @override
  void initState() {
    super.initState();
    // Pobierz dane z endpointu podczas tworzenia widoku
    //isLoading = false;
    fetchData();

  }

  // Funkcja pobierająca dane z endpointu
  Future<void> fetchData() async {

    //await Future.delayed(const Duration(seconds: 2));
    final response = await http.get(Uri.parse('https://api.chucknorris.io/jokes/random'));
    if (response.statusCode == 200) {
      // Przetwórz dane z formatu JSON i zapisz je do pola data
      setState(() {
        isLoading = false;
        data = json.decode(response.body);

      });
    } else {
      print('Błąd podczas pobierania danych');
    }
    //isLoading = true;
    isLoading = true;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Lab4'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'Dane:',
            ),
            SizedBox(height: 20.0,),
            data != null ?
            Text(
              data['value'],
              style: TextStyle(fontWeight: FontWeight.bold),
            ) : Container(),
            SizedBox(height: 20.0,),
            ElevatedButton(
              onPressed: isLoading ? () async {
                // Zmieniamy stan aplikacji

                fetchData();
                //isLoading = true;
              }:null,
              child: Text('Wczytaj'),
            ),
          ],
        ),
      ),
    );
  }
}



