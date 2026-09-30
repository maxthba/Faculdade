/* Consultas Mongo Shell para a colecao chamadas. Execute uma por vez. */
use("movies")

// Acha filmes do ano de 1999
db.chamadas.find({year: 1999})

// Acha filmes do ano de 2010 em diante
db.chamdas.find({year: {$gte:2010}})

// Acha filmes do ano de 2010 em diante com tempo de duração menor que 150 minutos
db.chamadas.find({year: {$gte:2010}, runtime: {$lte: 150}})

// Acha filmes do ano de 2010 em diante com tempo de duração menor que 150 minutos e nota do IMDB igual a 5.5
db.chamadas.find({year: {$gte:2010}, runtime: {$lte: 150}, "imdb.rating": 5.5})

    
