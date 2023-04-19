import 'package:flutter/material.dart';
import 'package:lab6/teacher.dart';

class TeacherSubjectsList extends StatelessWidget {
  final Teacher teacher;

  TeacherSubjectsList({Key? key, required this.teacher}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(teacher.teacher),
      ),
      body: ListView.builder(
        itemCount: teacher.subjects.length,
        itemBuilder: (context, index) {
          final subject = teacher.subjects[index];
          return ListTile(
            title: Text(subject),
          );
        },
      ),
    );
  }
}