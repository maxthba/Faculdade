part of 'soccerteamadd.dart';

class _SoccerTeamAddState extends State<SoccerTeamAdd> {
  final _formKey = GlobalKey<FormState>();
  final TextEditingController _nameController = TextEditingController();
  final TextEditingController _yearController = TextEditingController();

  void _saveTeam() {
    if (_formKey.currentState?.validate() ?? false) {
      final String name = _nameController.text.trim();
      final int foundationYear = int.parse(_yearController.text.trim());

      final team = SoccerTeam(name: name, foundationYear: foundationYear);
      Navigator.pop(context, team);
    }
  }

  @override
  void dispose() {
    _nameController.dispose();
    _yearController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Novo Time')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              TextFormField(
                controller: _nameController,
                decoration: const InputDecoration(
                  labelText: 'Nome do time',
                  border: OutlineInputBorder(),
                ),
                validator: (value) {
                  if (value == null || value.trim().isEmpty) {
                    return 'Informe o nome do time.';
                  }
                  return null;
                },
              ),
              const SizedBox(height: 16),
              TextFormField(
                controller: _yearController,
                decoration: const InputDecoration(
                  labelText: 'Ano de fundação',
                  border: OutlineInputBorder(),
                ),
                keyboardType: TextInputType.number,
                validator: (value) {
                  if (value == null || value.trim().isEmpty) {
                    return 'Informe o ano de fundação.';
                  }
                  final year = int.tryParse(value);
                  if (year == null ||
                      year < 1850 ||
                      year > DateTime.now().year) {
                    return 'Informe um ano válido.';
                  }
                  return null;
                },
              ),
              const SizedBox(height: 24),
              ElevatedButton(
                onPressed: _saveTeam,
                child: const Text('Salvar time'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}