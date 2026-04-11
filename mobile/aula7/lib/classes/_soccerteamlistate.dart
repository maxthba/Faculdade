part of 'soccerteamlist.dart';

class _SoccerTeamListState extends State<SoccerTeamList> {
  final List<SoccerTeam> _teams = [];

  @override
  void initState() {
    super.initState();
    _loadTeams();
  }

  Future<void> _loadTeams() async {
    try {
      final teams = await TeamApiService.fetchTeams();
      if (!mounted) {
        return;
      }

      setState(() {
        _teams
          ..clear()
          ..addAll(teams);
      });
    } catch (_) {
      if (!mounted) {
        return;
      }
      ScaffoldMessenger.of(context)
        ..clearSnackBars()
        ..showSnackBar(
          const SnackBar(content: Text('Erro ao carregar times.')),
        );
    }
  }

  Future<void> _navigateToAddTeam() async {
    final SoccerTeam? newTeam = await Navigator.push<SoccerTeam>(
      context,
      MaterialPageRoute(builder: (context) => const SoccerTeamAdd()),
    );

    if (newTeam != null) {
      try {
        await TeamApiService.addTeam(newTeam);
        if (!mounted) {
          return;
        }

        await _loadTeams();
        if (!mounted) {
          return;
        }

        ScaffoldMessenger.of(context)
          ..clearSnackBars()
          ..showSnackBar(
            const SnackBar(content: Text('Time salvo com sucesso.')),
          );
      } catch (_) {
        if (!mounted) {
          return;
        }
        ScaffoldMessenger.of(context)
          ..clearSnackBars()
          ..showSnackBar(
            const SnackBar(content: Text('Erro ao salvar no servidor.')),
          );
      }
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
            key: ValueKey(team.hash.isEmpty
                ? '${team.name}-${team.foundationYear}-$index'
                : team.hash),
            direction: DismissDirection.startToEnd,
            background: Container(
              color: Colors.red,
              alignment: Alignment.centerLeft,
              padding: const EdgeInsets.symmetric(horizontal: 20),
              child: const Icon(Icons.delete, color: Colors.white),
            ),
            confirmDismiss: (direction) async {
              if (team.hash.isEmpty) {
                return false;
              }

              final messenger = ScaffoldMessenger.of(context);

              try {
                await TeamApiService.deleteTeam(team.hash);
                await _loadTeams();
                if (!mounted) {
                  return false;
                }
                messenger
                  ..clearSnackBars()
                  ..showSnackBar(
                    SnackBar(
                      content: Text('Time "${team.name}" removido.'),
                    ),
                  );
                return true;
              } catch (_) {
                if (!mounted) {
                  return false;
                }
                messenger
                  ..clearSnackBars()
                  ..showSnackBar(
                    const SnackBar(
                      content: Text('Erro ao remover no servidor.'),
                    ),
                  );
                return false;
              }
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