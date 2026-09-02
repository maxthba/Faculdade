/* Consultas Mongo Shell para a colecao chamadas. Execute uma por vez. */
use("Frequencia");

// 1. Listar todas as chamadas.
db.chamadas.find();

// 2. Listar chamadas sem o vetor detalhado de alunos.
db.chamadas.find({}, { alunos: 0 });

// 3. Buscar chamada por _id.
db.chamadas.find({ _id: "CH-12490-P-0101-2026-08-01" });

// 4. Chamadas de uma disciplina.
db.chamadas.find({ "disciplina.codigo": "12490-P" });

// 5. Chamadas de uma turma.
db.chamadas.find({ "turma.codigo": "0101" });

// 6. Chamadas de um docente.
db.chamadas.find({ "docente.RP": "4567890" });

// 7. Chamadas em uma data ou intervalo de datas (datas YYYY-MM-DD).
db.chamadas.find({ data: { $gte: "2026-08-01", $lte: "2026-08-31" } }).sort({ data: 1 });

// 8. Chamadas que possuem ausentes.
db.chamadas.find({ "resumo.ausentes": { $gt: 0 } }, { _id: 0, data: 1, "disciplina.nome": 1, "turma.codigo": 1, resumo: 1 });

// 9. Consultar a presenca de um aluno por RA.
db.chamadas.find({ "alunos.RA": "1234" }, { _id: 0, data: 1, "disciplina.nome": 1, "turma.codigo": 1, "alunos.$": 1 });

// 10. Consultar faltas de um aluno por RA.
db.chamadas.find({ alunos: { $elemMatch: { RA: "1236", presente: false } } }, { _id: 0, data: 1, "disciplina.nome": 1, "alunos.$": 1 });

// 11. Listar todos os alunos ausentes e a justificativa.
db.chamadas.aggregate([
  { $unwind: "$alunos" },
  { $match: { "alunos.presente": false } },
  { $project: { _id: 0, data: 1, disciplina: "$disciplina.nome", turma: "$turma.codigo", RA: "$alunos.RA", aluno: "$alunos.nome", justificativa: "$alunos.justificativa" } },
  { $sort: { data: 1, aluno: 1 } }
]);

// 12. Frequencia de cada aluno: presencas, faltas e percentual.
db.chamadas.aggregate([
  { $unwind: "$alunos" },
  { $group: { _id: { RA: "$alunos.RA", nome: "$alunos.nome" }, totalAulas: { $sum: 1 }, presencas: { $sum: { $cond: ["$alunos.presente", 1, 0] } }, faltas: { $sum: { $cond: ["$alunos.presente", 0, 1] } } } },
  { $project: { _id: 0, RA: "$_id.RA", nome: "$_id.nome", totalAulas: 1, presencas: 1, faltas: 1, percentualFrequencia: { $round: [{ $multiply: [{ $divide: ["$presencas", "$totalAulas"] }, 100] }, 2] } } },
  { $sort: { percentualFrequencia: 1, nome: 1 } }
]);

// 13. Resumo de presenca por disciplina e turma.
db.chamadas.aggregate([
  { $group: { _id: { disciplina: "$disciplina.nome", turma: "$turma.codigo" }, aulas: { $sum: 1 }, totalPresentes: { $sum: "$resumo.presentes" }, totalAusentes: { $sum: "$resumo.ausentes" } } },
  { $project: { _id: 0, disciplina: "$_id.disciplina", turma: "$_id.turma", aulas: 1, totalPresentes: 1, totalAusentes: 1 } },
  { $sort: { disciplina: 1, turma: 1 } }
]);

// 14. Media de presenca por aula e disciplina.
db.chamadas.aggregate([
  { $group: { _id: "$disciplina.nome", aulas: { $sum: 1 }, mediaPresentes: { $avg: "$resumo.presentes" }, mediaAusentes: { $avg: "$resumo.ausentes" } } },
  { $project: { _id: 0, disciplina: "$_id", aulas: 1, mediaPresentes: { $round: ["$mediaPresentes", 2] }, mediaAusentes: { $round: ["$mediaAusentes", 2] } } },
  { $sort: { disciplina: 1 } }
]);

// 15. Chamadas cuja quantidade de presentes diverge da quantidade de alunos no vetor.
db.chamadas.aggregate([
  { $project: { _id: 1, data: 1, disciplina: "$disciplina.nome", resumo: 1, alunosNaLista: { $size: "$alunos" } } },
  { $match: { $expr: { $ne: [{ $add: ["$resumo.presentes", "$resumo.ausentes"] }, "$alunosNaLista"] } } }
]);
