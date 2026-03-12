class Key {
  final String label;
  final KeyType type;

  
  final String? value;

  
  final CalcAction? action;

  /// Construtor const:
  /// - permite criar objetos imutáveis (quando todos os campos também forem imutáveis)
  /// - ajuda a reforçar a ideia de "tecla como valor"
  const Key({
    required this.label,
    required this.type,
    this.value,
    this.action,
  });
}