import OracleDB from "oracledb";

// caminho da wallet de conexao com o oracle
const walletPath = "D:/banco de dados/primeiro banco/wallet"

// inicializar o cliente oracle, usando a wallet.
OracleDB.initOracleClient({configDir: walletPath});

// formato de saido dos dados, vai ser objetos javascript estruturados
OracleDB.outFormat = OracleDB.OUT_FORMAT_OBJECT;

const dbConfig = {
    user: "WEBAPP",
    password: "SuperSecretMyPassword123",
    connectString: "tcjqj6iicg8crs6z_high"
}

// funcao para abrir conexoes com o oracle
export async function open(){
    try{
        const connection = OracleDB.getConnection(dbConfig);
        console.log("Conexao OCI - aberta");
        return connection;
    }catch(err){
        console.error("Erro ao abrir conexao com o Oracle: ", err);
        throw err;
    }
}

export async function close(connection: OracleDB.Connection){
    try{
        await connection.close();
        console.log("Conexao OCI - fechada");
    }catch(err){
        console.error("erro ao fechar conexao com o Oracle: ", err)
    }
}
