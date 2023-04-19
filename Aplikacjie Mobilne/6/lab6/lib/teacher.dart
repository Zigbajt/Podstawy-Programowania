import 'dart:convert';
import 'package:http/http.dart' as http;

class Teacher {
  final int id;
  final String teacher;
  final List<String> subjects;

  Teacher({required this.id, required this.teacher, required this.subjects});

  factory Teacher.fromJson(Map<String, dynamic> json) {
    return Teacher(
      id: json['id'],
      teacher: json['teacher'],
      subjects: List<String>.from(json['subjects']),
    );
  }
}
class TeachersPobierz {
  Future<List<Teacher>> fetchTeachers() async {
    final response = await http.get(
        Uri.parse('https://mocki.io/v1/7604b5c4-1df8-4c8e-9fe8-375aa1591eae'),
        headers: {'Accept-Charset': 'utf-8'}
        );
    String text = utf8.decode(response.bodyBytes);
    final jsonData = json.decode(text);
    final teachers = jsonData['list'] as List<dynamic>;
    final teacherList = teachers.map((teacher) => Teacher(
      id: teacher['id'],
      teacher: teacher['teacher'],
      subjects: List<String>.from(teacher['subjects']),
    )).toList();
    return teacherList;
  }
}
