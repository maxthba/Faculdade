/* Consultas Mongo Shell para a colecao disciplinas. Execute uma por vez. */
use("Frequencia");

// 1. Listar todas as disciplinas.
db.disciplinas.find();

// 2. Mostrar os dados principais, sem turmas.
db.disciplinas.find({}, { _id: 0, codigo: 1, nome: 1, cargaHorariaTotal: 1, curso: 1, periodo: 1 });

// 3. Buscar por codigo.
db.disciplinas.find({ codigo: "12490-P" });

// 4. Buscar por parte do nome.
db.disciplinas.find({ nome: { $regex: "banco", $options: "i" } });

// 5. Disciplinas de curso, periodo, ano e semestre.
db.disciplinas.find({ curso: "Engenharia de Software", periodo: 4, anoCalendario: 2026, semestreCalendario: 2 });

// 6. Disciplinas com determinada carga horaria minima.
db.disciplinas.find({ cargaHorariaTotal: { $gte: 40 } });

// 7. Exibir somente uma turma pelo codigo.
db.disciplinas.find({ "turmas.codigo": "0101" }, { _id: 0, codigo: 1, nome: 1, "turmas.$": 1 });

// 8. Turmas ministradas por um professor.
db.disciplinas.aggregate([
  { $unwind: "$turmas" },
  { $match: { "turmas.docente.RP": "4567890" } },
  { $project: { _id: 0, codigo: 1, nome: 1, turma: "$turmas.codigo", docente: "$turmas.docente" } }
]);

// 9. Turmas com numero atual de matriculados acima de um limite.
db.disciplinas.aggregate([
  { $unwind: "$turmas" },
  { $match: { "turmas.qtdeAtualDeMatriculados": { $gte: 30 } } },
  { $project: { _id: 0, codigo: 1, nome: 1, turma: "$turmas.codigo", matriculados: "$turmas.qtdeAtualDeMatriculados" } }
]);

// 10. Total de vagas, matriculados, desistencias, transferencias e trancamentos por disciplina.
db.disciplinas.aggregate([
  { $unwind: "$turmas" },
  { $group: { _id: { codigo: "$codigo", nome: "$nome" }, vagasIniciais: { $sum: "$turmas.qtdeInicialDeMatriculados" }, matriculadosAtuais: { $sum: "$turmas.qtdeAtualDeMatriculados" }, desistencias: { $sum: "$turmas.desistencias" }, transferencias: { $sum: "$turmas.transferencias" }, trancamentos: { $sum: "$turmas.trancamentos" } } },
  { $sort: { "_id.nome": 1 } }
]);

// 11. Todas as aulas agendadas, em ordem cronologica.
db.disciplinas.aggregate([
  { $unwind: "$turmas" },
  { $unwind: "$turmas.agendaDeAulas" },
  { $project: { _id: 0, disciplina: "$nome", turma: "$turmas.codigo", docente: "$turmas.docente.nome", inicio: "$turmas.agendaDeAulas.dataHoraInicio", fim: "$turmas.agendaDeAulas.dataHoraFim", horas: "$turmas.agendaDeAulas.qtdeHorasAula" } },
  { $sort: { inicio: 1 } }
]);

// 12. Disciplinas sem nenhuma chamada registrada.
db.disciplinas.aggregate([
  { $lookup: { from: "chamadas", localField: "codigo", foreignField: "disciplina.codigo", as: "chamadas" } },
  { $match: { "chamadas.0": { $exists: false } } },
  { $project: { _id: 0, codigo: 1, nome: 1 } }
]);
