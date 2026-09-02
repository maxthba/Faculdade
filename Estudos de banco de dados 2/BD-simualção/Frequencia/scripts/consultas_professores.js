/* Consultas Mongo Shell para a colecao professores. Execute uma por vez. */
use("Frequencia");

// 1. Listar todos os professores.
db.professores.find();

// 2. Mostrar somente RP e nome.
db.professores.find({}, { _id: 0, RP: 1, nome: 1 });

// 3. Buscar professor por RP.
db.professores.find({ RP: "4567890" });

// 4. Buscar professor pelo nome exato.
db.professores.find({ nome: "Ada Lovelace" });

// 5. Buscar professores cujo nome contenha um texto (sem diferenciar maiusculas/minusculas).
db.professores.find({ nome: { $regex: "mar", $options: "i" } });

// 6. Ordenar por nome.
db.professores.find().sort({ nome: 1 });

// 7. Contar professores.
db.professores.countDocuments();

// 8. Professores que aparecem em alguma turma de disciplinas.
db.professores.aggregate([
  { $lookup: { from: "disciplinas", localField: "RP", foreignField: "turmas.docente.RP", as: "disciplinas" } },
  { $match: { "disciplinas.0": { $exists: true } } },
  { $project: { _id: 0, RP: 1, nome: 1, totalDisciplinas: { $size: "$disciplinas" } } }
]);

// 9. Professores sem turma vinculada.
db.professores.aggregate([
  { $lookup: { from: "disciplinas", localField: "RP", foreignField: "turmas.docente.RP", as: "disciplinas" } },
  { $match: { "disciplinas.0": { $exists: false } } },
  { $project: { _id: 0, RP: 1, nome: 1 } }
]);

// 10. Quantidade de chamadas registradas por professor.
db.professores.aggregate([
  { $lookup: { from: "chamadas", localField: "RP", foreignField: "docente.RP", as: "chamadas" } },
  { $project: { _id: 0, RP: 1, nome: 1, totalChamadas: { $size: "$chamadas" } } },
  { $sort: { totalChamadas: -1, nome: 1 } }
]);
