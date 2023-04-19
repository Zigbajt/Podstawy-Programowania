import 'package:flutter/material.dart';
import 'package:lab6/teacher.dart';
import 'package:lab6/przedmioty.dart';

class Lista extends StatefulWidget {
  @override
  _ListaState createState() => _ListaState();
}

class _ListaState extends State<Lista> {
  late List<Teacher> _teachers;
  late List<Teacher> _filteredTeachers;

  @override
  void initState() {
    super.initState();
    TeachersPobierz().fetchTeachers().then((teachers) {
      setState(() {
        _teachers = teachers;
        _filteredTeachers = _teachers;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Lista prowadzących'),
      ),
      body: Column(
        children: [
          TextField(
            onChanged: (value) => Filtr(value),
          ),
          Expanded(
            child: _filteredTeachers != null
                ? ListView.builder(
              itemCount: _filteredTeachers.length,
              itemBuilder: (context, index) {
                final teacher = _filteredTeachers[index];
                return ListTile(
                  title: Text(teacher.teacher),
                  onTap: () {
                    Navigator.of(context).push(MaterialPageRoute(
                        builder: (context) => TeacherSubjectsList(
                          teacher: teacher,
                        )));
                  },
                );
              },
            )
                : Center(child: CircularProgressIndicator()),
          ),
        ],
      ),
    );
  }

  void Filtr(String value) {
    final List<Teacher> filteredTeachers = _teachers
        .where((teacher) =>
        teacher.teacher.toLowerCase().contains(value.toLowerCase()))
        .toList();
    setState(() {
      _filteredTeachers = filteredTeachers;
    });
  }
}

