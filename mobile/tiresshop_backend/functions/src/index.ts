import {onRequest} from "firebase-functions/v2/https";
import * as logger from "firebase-functions/logger";
import * as admin from "firebase-admin";

const app = admin.initializeApp();
const db = app.firestore();
const colPneus = db.collection("pneus");

export const addSampleTire = onRequest(
  {region: "southamerica-east1", invoker: "public"},
  async (_request, response) => {
    const pneu = {
      largura: 225,
      altura: 50,
      aro: 17,
      marca: "Pirelli",
      modelo: "Cinturato P7",
      precoVenda: 780.99,
    };
    try {
      const docRef = await colPneus.add(pneu);
      response.send("Pneu exemplo inserido. Referencia: " + docRef.id);
    } catch (e) {
      logger.error("erro ao inserir o pneu de exemplo.", e);
      response.status(500).send("erro ao inserir o pneu de exemplo");
    }
  },
);

export const deleteTire = onRequest(
  {region: "southamerica-east1", invoker: "public"},
  async (_request, response) => {
    const tireId = "lWsCYLsttVBP13NzHkuM";
    await colPneus.doc(tireId).delete();
    response.send("Exclusao -  provavelmente - realizada");
  },
);

export const showSampleTires15 = onRequest(
  {region: "southamerica-east1", invoker: "public"},
  async (_request, response) => {
    // busca de pneus com aro 15.
    const tires: FirebaseFirestore.DocumentData[] = [];
    const snapshot = await colPneus.where("aro", "==", 15).get();
    snapshot.forEach((doc) => {
      tires.push(doc.data());
    });
    response.status(200).json(tires);
  },
);
