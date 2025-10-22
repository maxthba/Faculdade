import { open, close } from "../config/db";
import oracledb from "oracledb";

export interface Estudante {
  id: number;
  ra: string;
  nome: string;
  email: string;
}

// Obter todos os estudantes da tabela estudantes do oracle
export async function getAllEstudantes(): Promise<Estudante[]> {
  const conn = await open();
  try {
    const result = await conn.execute(
      `SELECT ID as "id", RA as "ra", NOME as "nome", EMAIL as "email" FROM ESTUDANTES`,
      {},
      { outFormat: oracledb.OUT_FORMAT_OBJECT }
    );
    return (result.rows ?? []) as Estudante[];
  } finally {
    await close(conn);
  }
}

export async function getEstudanteById(id: number): Promise<Estudante | null> {
  const conn = await open();
  try {
    const result = await conn.execute(
      `SELECT ID as "id", RA as "ra", NOME as "nome", EMAIL as "email" FROM ESTUDANTES WHERE ID = :id`,
      { id },
      { outFormat: oracledb.OUT_FORMAT_OBJECT }
    );
    const row = (result.rows && result.rows[0]) as Estudante | undefined;
    return row ?? null;
  } finally {
    await close(conn);
  }
}

export async function addEstudante(ra: string, nome: string, email: string): Promise<number> {
  const conn = await open();
  try {
    const result = await conn.execute<{ outBinds: { id?: number[] } }>(
      `
      INSERT INTO ESTUDANTES(RA, NOME, EMAIL)
      VALUES(:ra, :nome, :email)
      RETURNING ID INTO :id
      `,
      {ra, nome, email, id: { dir: oracledb.BIND_OUT, type: oracledb.NUMBER }},
      { autoCommit: true }
    );

    const outBinds = result.outBinds as { id?: number[] } | undefined;

    if (!outBinds || !outBinds.id || outBinds.id.length === 0) {
      throw new Error("Erro ao obter um ID retornado na inserção de estudante.");
    }

    return outBinds.id[0];
    
  } finally {
    await close(conn);
  }
}