import 'package:flutter/material.dart';

import 'soccerteam.dart';
import 'soccerteamadd.dart';
import 'soccerteamlist.dart';

class _SoccerTeamListState extends State<SoccerTeamList> {
  final List<SoccerTeam> _teams = [];

  Future<void> _navigateToAddTeam() async {
    final SoccerTeam? newTeam = await Navigator.push<SoccerTeam>(
      context,
      MaterialPageRoute(builder: (context) => const SoccerTeamAdd()),
    );

    if (newTeam != null) {
      setState(() {
        _teams.add(newTeam);
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Times de Futebol'),
        backgroundColor: Theme.of(context).colorScheme.primary,
      ),
      body: _teams.isEmpty
          ? const Padding(
        padding: EdgeInsets.symmetric(horizontal: 24.0, vertical: 16.0),
        child: Center(
          child: Text(
            'Nenhum time cadastrado ainda. Toque no botão + para adicionar.',
            textAlign: TextAlign.center,
            style: TextStyle(fontSize: 25),
          ),
        ),
      )
          : ListView.builder(
        itemCount: _teams.length,
        padding: const EdgeInsets.all(12),
        itemBuilder: (context, index) {
          final team = _teams[index];
          return Dismissible(
            key: ValueKey('${team.name}-${team.foundationYear}-$index'),
            direction: DismissDirection.startToEnd,
            background: Container(
              color: Colors.green,
              alignment: Alignment.centerLeft,
              padding: const EdgeInsets.symmetric(horizontal: 20),
              child: const Icon(Icons.archive, color: Colors.white),
            ),
            onDismissed: (direction) {
              final removedTeam = team;
              final removedIndex = index;

              setState(() {
                _teams.removeAt(index);
              });

              ScaffoldMessenger.of(context)
                ..clearSnackBars()
                ..showSnackBar(
                  SnackBar(
                    content: Text('Time "${removedTeam.name}" removido.'),
                    duration: const Duration(seconds: 10),
                    action: SnackBarAction(
                      label: 'Desfazer',
                      onPressed: () {
                        setState(() {
                          _teams.insert(removedIndex, removedTeam);
                        });
                      },
                    ),
                  ),
                );
            },
            child: Card(
              margin: const EdgeInsets.symmetric(vertical: 8),
              child: ListTile(
                title: Text(team.name),
                subtitle: Text('Fundado em ${team.foundationYear}'),
                leading: const Icon(Icons.sports_soccer),
              ),
            ),
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _navigateToAddTeam,
        tooltip: 'Adicionar time',
        child: const Icon(Icons.add),
      ),
    );
  }
}