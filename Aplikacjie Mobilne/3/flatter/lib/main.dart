import 'package:flutter/material.dart';
import 'package:app/draver.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Lab 2',
      routes: {
        Strona4.routeName: (context) =>
        const Strona4(),
      },
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
        primarySwatch: Colors.deepPurple,
      ),
      home: MyStatefulWidget(),
    );
  }
}

class MyStatefulWidget extends StatefulWidget {
  MyStatefulWidget({super.key});

  @override
  State<MyStatefulWidget> createState() => _MyStatefulWidgetState();
}

class _MyStatefulWidgetState extends State<MyStatefulWidget> {
  int cindex=0;
  final tab=[
    Strona1(),
    Strona2(),
    Strona3(),
  ];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Lab 2'),
      ),
      drawer: Menu(),
      body: IndexedStack(
        index: cindex,
        children: tab,
      ),
      bottomNavigationBar: BottomNavigationBar(

        items: const <BottomNavigationBarItem>[
          BottomNavigationBarItem(
            icon: Icon(Icons.home),
            label: 'Strona 1',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.adb),
            label: 'Strona 2',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.settings),
            label: 'Strona 3',
          ),
        ],
        currentIndex: cindex,
        selectedItemColor: Colors.deepPurpleAccent,
        onTap: (index) => setState(() => cindex = index),
      ),
    );
  }
}
class Strona1 extends StatefulWidget {
  const Strona1();
  @override
  State<Strona1> createState() => _Strona1State();
}

class _Strona1State extends State<Strona1> {
  String email='';
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.symmetric(vertical: 20.0,horizontal: 40.0),
      child: Form(
        child: Column(
          children: <Widget>[
            SizedBox(height: 20.0),
            TextFormField(
              validator: (value){
                if(value==null || value.isEmpty){
                  return 'Prak wartości';
                }
                return null;
              },
              onChanged: (value) async{
                setState(() {
                  email=value;
                  //message=email;
                });
              },
            ),
            SizedBox(height: 20.0),
            ElevatedButton(
              child: Text(
                'Wykonaj',
                style: TextStyle(fontSize: 24),
              ),
              onPressed: () async{
                //Navigator.of(context).push(MaterialPageRoute(builder:(context)=>Strona4(text: email)));
                Navigator.pushNamed(
                  context,
                  Strona4.routeName,
                  arguments: ScreenArguments(
                    email,
                  ),
                );
              },
            )
          ],
        ),
      ),
    );
  }
}

class Strona2 extends StatelessWidget {
  const Strona2({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return Container(
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Text(
            'Strona2',
            style: TextStyle(height: 5, fontSize: 30),
          ),
        ],
      ),
    );
  }
}

class Strona3 extends StatelessWidget {
  const Strona3({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Text(
            'Strona3',
            style: TextStyle(height: 5, fontSize: 30),
          ),
        ],
      ),
    );
  }
}
class Strona4 extends StatelessWidget {
  const Strona4({Key? key}) : super(key: key);
  static const routeName = '/extractArguments';
  @override
  Widget build(BuildContext context) {
    final ScreenArguments args = ModalRoute.of(context)!.settings.arguments as ScreenArguments;
    return Scaffold(
      appBar: AppBar(
        title: const Text('Lab 2'),
      ),
      //drawer: Menu(),
      body: Container(
        child: Center(
          child: Text(
            args.message,
            style: TextStyle(height: 5, fontSize: 10),
          ),
        ),
      ),
    );
  }
}
class ScreenArguments {
  final String message;

  ScreenArguments(this.message);
}






