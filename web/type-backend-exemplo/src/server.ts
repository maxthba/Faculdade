import express, {Request, Response} from "express";
import bodyParser from "body-parser";

const app = express();
const port: number = 3000;

app.use(bodyParser.json());

//rota default para teste...
app.get("/", (req: Request, res: Response) => {
    res.send("servidor web backend rodando...")
});

app.post("/MostrarRequisicao", (req: Request, res: Response) => {
    const dadosRecebidos = req.body;
    res.json({
        mensagem: "Dados Recebidos com sucesso...",
        dadosRecebidos
    });
});

app.listen(port, ()=>{
    console.log(`Servidor rodando na porta: ${port}`);
});

// desafio: criar um script chamado clean. Quando for executado pelo npm run clean, devera excluir o diretorio dist.
