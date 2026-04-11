import 'dart:convert';

import 'package:http/http.dart' as http;

import 'soccerteam.dart';

class TeamApiService {
  TeamApiService._();

  static final Uri _addTimeUrl = Uri.parse(
    'https://addtime-tm3t3magva-rj.a.run.app',
  );

  static Future<void> addTeam(SoccerTeam team) async {
    final response = await http.post(
      _addTimeUrl,
      headers: {'Content-Type': 'application/json'},
      body: jsonEncode({
        'nome': team.name,
        'anoFundacao': team.foundationYear,
      }),
    );

    if (response.statusCode < 200 || response.statusCode >= 300) {
      throw Exception('Falha ao adicionar time (${response.statusCode}).');
    }
  }
}
