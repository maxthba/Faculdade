import express, { Request, Response } from "express";
import bodyParser from "body-parser";

import{
    getAllEstudantes,
    getEstudanteById,
    addEstudante
}from "./db/estudantes";

const app = express();
const port = 3000;

app.use(bodyParser.json());

//definir as rotas
app.get('/estudantes', async (req: Request, res: Response) => {
    try{
        const estudantes = await getAllEstudantes();
        res.json(estudantes);
    }catch(err){
        console.log(err);
        res.status(500).json({
            "error": "Erro ao buscar estudante"
        });
    }
});

//obter estudante pelo id
app.get('/estudantes/:id', async (req: Request, res: Response) => {
    try{
        const id = Number(req.params.id);
        const estudante = await getEstudanteById(id);
        if(estudante){
            res.json(estudante);
        }else{
            res.status(404).json({message: "estudante nao encontrado com id fornecido"})
        }
    }catch(error){
        console.error(error);
        res.status(500).json({error: "erro ao buscar estudante pelo id fornecido."})
    }
});

//rota para inserir estudante
app.post("/estudantes", async(req:Request, res:Response)=>{
    try{
        const {ra, nome, email} = req.body;
        if(!ra || !nome || !email){
            return res.status(400).json({error: "Campos RA, Nome e Email sao obrigatorios."})
        }
        const id = await addEstudante(ra, nome, email);
        res.status(201).json({message: "Estudante adicionado com sucesso", id});
    }catch(error){
        console.error(error);
        res.status(500).json({error: "Erro ao inserir estudante"})
    }
});

app.listen(port, ()=>{
    console.log(`servidor rodando: http://localhost:${port}`);
})