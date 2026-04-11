import 'dart:convert';

import 'package:http/http.dart' as http;

import 'soccerteam.dart';

class TeamApiService {
  TeamApiService._();

  static final Uri _addTimeUrl = Uri.parse(
    'https://addtime-tm3t3magva-rj.a.run.app',
  );
  static final Uri _showTimesUrl = Uri.parse(
    'https://showtimes-tm3t3magva-rj.a.run.app',
  );

  static Future<List<SoccerTeam>> fetchTeams() async {
    final response = await http.get(_showTimesUrl);

    if (response.statusCode < 200 || response.statusCode >= 300) {
      throw Exception('Falha ao listar times (${response.statusCode}).');
    }

    final dynamic decoded = jsonDecode(response.body);

    List<dynamic> rawItems = <dynamic>[];
    if (decoded is List<dynamic>) {
      rawItems = decoded;
    } else if (decoded is Map<String, dynamic>) {
      final times = decoded['times'];
      if (times is List<dynamic>) {
        rawItems = times;
      }
    }

    return rawItems
        .whereType<Map<String, dynamic>>()
        .map((item) {
          final dynamic rawName = item['nome'] ?? item['name'] ?? '';
          final dynamic rawYear =
              item['anoFundacao'] ?? item['foundationYear'] ?? 0;

          final String name = rawName.toString();
          final int year = rawYear is int
              ? rawYear
              : int.tryParse(rawYear.toString()) ?? 0;

          return SoccerTeam(name: name, foundationYear: year);
        })
        .toList();
  }

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
