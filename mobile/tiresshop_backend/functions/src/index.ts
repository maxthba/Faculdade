import {onRequest} from "firebase-functions/v2/https";
import * as logger from "firebase-functions/logger";
import * as admin from "firebase-admin";

const app = admin.initializeApp();
const db = app.firestore();
const colPneus = db.collection("pneus");

export const addSampleTire = onRequest(
  {region: "southamerica-east1"},
  async (_request, response) => {
    const pneu = {
      largura: 225,
      altura: 50,
      aro: 17,
      marca: "prielli",
      modelo: "cinturato P7",
      precoVenda: 780.99,
    };

    try {
      const docRef = await colPneus.add(pneu);
      response.send("pneu exemplo inserido. Referencia " + docRef.id);
    } catch (e) {
      logger.error("erro ao inserir o pneu de exemplo.", e);
      response.status(500).send("erro ao inserir o pneu de exemplo");
    }
  },
);
