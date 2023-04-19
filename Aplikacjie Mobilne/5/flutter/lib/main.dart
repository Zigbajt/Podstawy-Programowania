import 'dart:io';

import 'package:battery_info/enums/charging_status.dart';
import 'package:flutter/material.dart';
import 'package:sensors_plus/sensors_plus.dart';
import 'package:battery_info/battery_info_plugin.dart';
import 'package:battery_info/model/android_battery_info.dart';
import 'package:camera/camera.dart';
import 'package:image_picker/image_picker.dart';

late List<CameraDescription> cameras;
Future<void> main() async {
  // Pobierz listę dostępnych kamer
  WidgetsFlutterBinding.ensureInitialized();
  cameras = await availableCameras();
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Lab5',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // Try running your application with "flutter run". You'll see the
        // application has a blue toolbar. Then, without quitting the app, try
        // changing the primarySwatch below to Colors.green and then invoke
        // "hot reload" (press "r" in the console where you ran "flutter run",
        // or simply save your changes to "hot reload" in a Flutter IDE).
        // Notice that the counter didn't reset back to zero; the application
        // is not restarted.
        primarySwatch: Colors.brown,
      ),
      home: MenuPage(),
    );
  }
}
class MenuPage extends StatelessWidget {
  const MenuPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Menu'),
      ),
      body: Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          ElevatedButton(
            onPressed: () {
              Navigator.push(context, MaterialPageRoute(builder: (context)=>Accl(title: "Akcelerometr")));
            },
            child: Text('Akcelerometr'),
          ),
          SizedBox(
            height: 20,
          ),
          ElevatedButton(
            onPressed: () {
              Navigator.push(context, MaterialPageRoute(builder: (context)=>Cam(title: "Kamera",cameras: cameras,)));
            },
            child: Text('Kamera'),
          ),
          SizedBox(
            height: 20,
          ),
          ElevatedButton(
            onPressed: () {
              Navigator.push(context, MaterialPageRoute(builder: (context)=>Bateria(title: "Bateria")));
            },
            child: Text('Bateria'),
          ),
        ],
      ),
      ),
    );
  }
}

class Bateria extends StatefulWidget {
  final String title;
  Bateria({required this.title, Key? key}) : super(key: key);

  @override
  State<Bateria> createState() => _BateriaState();
}

class _BateriaState extends State<Bateria> {
  @override
  Widget build(BuildContext context) {
      return Scaffold(
        appBar: AppBar(
          title: const Text('Bateria'),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              FutureBuilder<AndroidBatteryInfo?>(
                  future: BatteryInfoPlugin().androidBatteryInfo,
                  builder: (context, snapshot) {
                    if (snapshot.hasData) {
                      return Text(
                          'Battery Health: ${snapshot.data?.health?.toUpperCase()}');
                    }
                    return CircularProgressIndicator();
                  }),
              SizedBox(
                height: 20,
              ),
              StreamBuilder<AndroidBatteryInfo?>(
                  stream: BatteryInfoPlugin().androidBatteryInfoStream,
                  builder: (context, snapshot) {
                    if (snapshot.hasData) {
                      return Column(
                        children: [
                          Text("Voltage: ${(snapshot.data?.voltage)} mV"),
                          SizedBox(
                            height: 20,
                          ),
                          Text(
                              "Charging status: ${(snapshot.data?.chargingStatus.toString().split(".")[1])}"),
                          SizedBox(
                            height: 20,
                          ),
                          Text(
                              "Battery Level: ${(snapshot.data?.batteryLevel)} %"),
                          SizedBox(
                            height: 20,
                          ),
                          Text("Scale: ${(snapshot.data!.scale)} "),
                          SizedBox(
                            height: 20,
                          ),
                          _getChargeTime(snapshot.data!),
                        ],
                      );
                    }
                    return CircularProgressIndicator();
                  })
            ],
          ),
        ),
    );
  }
  Widget _getChargeTime(AndroidBatteryInfo data) {
    if (data.chargingStatus == ChargingStatus.Charging) {
      return data.chargeTimeRemaining == -1
          ? Text("Calculating charge time remaining")
          : Text(
          "Charge time remaining: ${(data.chargeTimeRemaining! / 1000 / 60).truncate()} minutes");
    }
    return Text("Battery is full or not connected to a power source");
  }
}

class Accl extends StatefulWidget {
  final String title;
  Accl({required this.title,Key? key}) : super(key: key);


  @override
  State<Accl> createState() => _AcclState();
}

class _AcclState extends State<Accl> {
  late List<double> _accelerometerValues;
  @override
  void initState() {
    super.initState();
    accelerometerEvents.listen((AccelerometerEvent event) {
      setState(() {
        _accelerometerValues = <double>[event.x, event.y, event.z];
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    if (_accelerometerValues == null) {
      return Scaffold(
        appBar: AppBar(
          title: const Text('Akcelerometr'),
        ),
        body: Center(
          child: Text('Ładowanie danych z akcelerometru...'),
        ),
      );

    }
    return Scaffold(
      appBar: AppBar(
        title: const Text('Akcelerometr'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
                'Orientacja urządzenia:'
            ),
            SizedBox(
              height: 20,
            ),
            Text(
                'X: ${_accelerometerValues[0]}'
            ),
            SizedBox(
              height: 20,
            ),
            Text(
                'Y: ${_accelerometerValues[1]}'
            ),
            SizedBox(
              height: 20,
            ),
            Text(
                'Z: ${_accelerometerValues[2]}'
            ),
          ],
        ),
      ),
    );
  }
}



class Cam extends StatefulWidget {
  final String title;
  final List<CameraDescription> cameras;
  const Cam({Key? key,required this.title,required this.cameras}) : super(key: key);


  @override
  State<Cam> createState() => _CamState();
}

class _CamState extends State<Cam> {
  late CameraController _controller;
  late Future<void> _initializeControllerFuture;


  @override
  void initState() {
    super.initState();
    // Wybierz pierwszą dostępną kamerę
    _controller = CameraController(widget.cameras[0], ResolutionPreset.medium);
    _initializeControllerFuture = _controller.initialize();
  }

  @override
  void dispose() {
    // Zwolnij zasoby zajęte przez kontroler kamery
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Zrób zdjęcie')),
      body: FutureBuilder<void>(
        future: _initializeControllerFuture,
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.done) {
            // Kontroler kamery został pomyślnie zainicjalizowany
            return CameraPreview(_controller);
          } else {
            // Inicjalizacja kontrolera kamery jest w toku
            return Center(child: CircularProgressIndicator());
          }
        },
      ),
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.camera_alt),
        // Kiedy użytkownik naciśnie przycisk, zapisz zdjęcie za pomocą kontrolera kamery
        onPressed: () async {
          try {
            await _initializeControllerFuture;
            // Zapisz zdjęcie w folderze aplikacji
            final ImagePicker _picker = ImagePicker();
            final XFile? photo = await _picker.pickImage(source: ImageSource.camera);
            File photofile = File(photo!.path);


            // Po zapisaniu zdjęcia zamknij ekran
            Navigator.pop(context);
          } catch (e) {
            print(e);
          }
        },
      ),
    );
  }
}


