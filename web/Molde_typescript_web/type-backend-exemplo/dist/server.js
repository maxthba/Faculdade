"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const body_parser_1 = __importDefault(require("body-parser"));
const app = (0, express_1.default)();
const port = 3000;
app.use(body_parser_1.default.json());
//rota default para teste...
app.get("/", (req, res) => {
    res.send("servidor web backend rodando...");
});
app.post("/MostrarRequisicao", (req, res) => {
    const dadosRecebidos = req.body;
    res.json({
        mensagem: "Dados Recebidos com sucesso...",
        dadosRecebidos
    });
});
app.listen(port, () => {
    console.log(`Servidor rodando na porta: ${port}`);
});
// desafio: criar um script chamado clean. Quando for executado pelo npm run clean, devera excluir o diretorio dist.
