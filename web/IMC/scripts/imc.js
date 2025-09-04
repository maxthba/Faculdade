
            function CalcularIMC(peso, altura){
               return peso / (altura*altura);
            }

            function ExecutarCalculo(){
                /*
                    obter os dados digitados pelo usuario no formulario, 
                    nos campos txtPeso e txtAltura,
                    atribuimos os dados em constantes para posteriormente, fazer o calculo.

                    document (representa todo o hmtl)
                    quando usamos a função get.elementbyid, sera retornado o elemento inteiro. 
                    Então queremos apenas o atributo value do elemento input(não o elemento inteiro)
                */
                const p = parseFloat(document.getElementById("txtPeso").value);

                const a = parseFloat(document.getElementById("txtAltura").value);

                let aviso = document.getElementsByClassName("warning");

                if(!isNaN(p) && !isNaN(a) && p>0 && p<1000 && a>0 && a<2.5){
                    document.getElementById("resultado").textContent = "IMC : " + CalcularIMC(p, a).toFixed(2);
                    for (let i = 0; i<aviso.length; i++){
                        aviso[i].textContent = " ";
                        aviso[i].classList.remove("mostrar")
                    }
                }
                else{
                    for (let i = 0; i<aviso.length; i++){
                        aviso[i].textContent = "digite um valor valido!!!";
                        aviso[i].classList.add("mostrar")
                    }
                }
            }
