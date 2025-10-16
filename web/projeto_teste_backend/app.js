//estas 3 linhas são referenciais
// aos pacotes que vamos usar

const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');

//porta de funcionamento para nosso serviço - node http (servidor web - service)
// conts = constante a porta do swervidor não muda
const port = 3000;

//definindo que nosso servidor é uma aplicação em javascript usando um pacote express

const serverApp = express();

// defenir nosso servidor alguns padroes. Nosso servidor recebera requisiçoees no formato json e podera devolver respostas formato json

serverApp.use(bodyParser.json());

//o servidor aceitara requisisoes http de qualquer lugar

serverApp.use(cors());

//um servidor , possui ROTAs, cada rota representa serviço. Que o servidor faz, ou pode ser um arquivo.
//Servidor = serve (rotas ou paginas)

serverApp.get('/', (req,res) =>{
    //implementar o que o servidor vai fazer quando o cliente acessar , por exemplo
    //http://ip_do_servidor_;3000/
    res.send('Oi Max');
});

serverApp.get('/numeroPi', (req,res) =>{
    res.send("3.1415");
});

//impementar o start do servidor, colocar o servidor para rodar (de pe)

serverApp.listen(port);


