import {onRequest} from "firebase-functions/v2/https";
import * as logger from "firebase-functions/logger";
import {initializeApp} from "firebase-admin/app";
import {getFirestore} from "firebase-admin/firestore";

const app = initializeApp();
const db = getFirestore(app, "bancoteste");
const colTimes = db.collection("Times");

export const addTime = onRequest(
  {region: "southamerica-east1", invoker: "public"},
  async (_request, response) => {
    const nome = _request.body?.nome;
    const anoFundacao = _request.body?.anoFundacao;

    if (typeof nome !== "string" || nome.trim().length === 0) {
      response.status(400).send("Campo 'nome' e obrigatorio.");
      return;
    }

    const time = {
      nome: nome.trim(),
      anoFundacao: anoFundacao,
    };

    try {
      const docRef = await colTimes.add(time);
      response.send("Time adicionado com sucesso. Referencia: " + docRef.id);
    } catch (error) {
      logger.error("Erro ao inserir time.", error);
      response.status(500).send("Erro ao inserir o time.");
    }
  }
);
