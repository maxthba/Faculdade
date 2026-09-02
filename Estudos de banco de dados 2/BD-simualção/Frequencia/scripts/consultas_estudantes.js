/* Consultas Mongo Shell para a colecao estudantes. Execute uma por vez. */
use("Frequencia");

// 1. Listar todos os estudantes.
db.estudantes.find();

// 2. Mostrar RA, nome, curso e periodo.
db.estudantes.find({}, { _id: 0, RA: 1, nome: 1, curso: 1, periodo: 1 });

// 3. Buscar estudante por RA.
db.estudantes.find({ RA: "1234" });

// 4. Buscar estudantes por curso e periodo.
db.estudantes.find({ curso: "Engenharia de Software", periodo: 4 });

// 5. Buscar por parte do nome.
db.estudantes.find({ nome: { $regex: "ana", $options: "i" } });

// 6. Listar matriculas de um estudante.
db.estudantes.find({ RA: "1234" }, { _id: 0, nome: 1, matriculas: 1 });

// 7. Estudantes matriculados em uma disciplina.
db.estudantes.find({ "matriculas.disciplinaCodigo": "12490-P" }, { _id: 0, RA: 1, nome: 1, matriculas: 1 });

// 8. Estudantes de uma turma especifica.
db.estudantes.find({ "matriculas.turmaCodigo": "0101" }, { _id: 0, RA: 1, nome: 1 });

// 9. Estudantes com mais de uma matricula.
db.estudantes.aggregate([
  { $project: { _id: 0, RA: 1, nome: 1, totalMatriculas: { $size: "$matriculas" } } },
  { $match: { totalMatriculas: { $gt: 1 } } }
]);

// 10. Quantidade de estudantes por curso e periodo.
db.estudantes.aggregate([
  { $group: { _id: { curso: "$curso", periodo: "$periodo" }, total: { $sum: 1 } } },
  { $sort: { "_id.curso": 1, "_id.periodo": 1 } }
]);

// 11. Situacoes de matricula por disciplina.
db.estudantes.aggregate([
  { $unwind: "$matriculas" },
  { $group: { _id: { disciplina: "$matriculas.disciplinaNome", situacao: "$matriculas.situacao" }, total: { $sum: 1 } } },
  { $sort: { "_id.disciplina": 1 } }
]);

// 12. Estudantes que possuem chamada registrada (cruzamento com chamadas).
db.estudantes.aggregate([
  { $lookup: { from: "chamadas", localField: "RA", foreignField: "alunos.RA", as: "chamadas" } },
  { $project: { _id: 0, RA: 1, nome: 1, totalChamadas: { $size: "$chamadas" } } },
  { $match: { totalChamadas: { $gt: 0 } } },
  { $sort: { totalChamadas: -1, nome: 1 } }
]);
