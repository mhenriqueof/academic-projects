// Criando variáveis no JS
/* Comentário de bloco */

var numeroGlobal = 10;
let numeroLocal = 5;
const NUMEROCONST = "15";
let booleano = true;

console.log(
    "Numero Global: " + numeroGlobal +
    "\nNumero Local: " + numeroLocal +
    "\nNumero Constante: " + NUMEROCONST
);

console.log(
    "Soma de Global e Local: " + 
    (numeroGlobal + numeroLocal)
);

console.log(
    "Soma de Global e Constante: " + 
    (numeroGlobal + Number(NUMEROCONST))
);

//numeroGlobal = numeroGlobal.toString();

console.log(
    "\n TIPOS DE VARIÁVEIS: " +
    "\n Numero Global = " + typeof(numeroGlobal) +
    "\n Numero Local = " + typeof(numeroLocal) +
    "\n Numero Constante = " + typeof(NUMEROCONST) +
    "\n Variável Booleano = " + typeof(booleano)
);

numeroGlobal += numeroLocal;
//console.log(numeroGlobal);

//Operadores de igualdade
console.log(
    "\nComparando Numero Global com Numero Constante: " +
    "\n numeroGlobal == NUMEROCONST  = " + (numeroGlobal == NUMEROCONST) +
    "\n numeroGlobal != NUMEROCONST  = " + (numeroGlobal != NUMEROCONST) +
    "\n numeroGlobal > NUMEROCONST  = " + (numeroGlobal > NUMEROCONST) +
    "\n numeroGlobal < NUMEROCONST  = " + (numeroGlobal < NUMEROCONST) +
    "\n numeroGlobal >= NUMEROCONST  = " + (numeroGlobal >= NUMEROCONST) +
    "\n numeroGlobal <= NUMEROCONST  = " + (numeroGlobal <= NUMEROCONST) +
    "\n numeroGlobal === NUMEROCONST  = " + (numeroGlobal === NUMEROCONST) 
);

//Operadores Lógicos &&, ||, !

console.log(
    "\nComparando variáveis " + 
    "\nNumero Global é igual ao NUMEROCOST AND menor do que o Numero Local : " + (numeroGlobal === NUMEROCONST && numeroGlobal > numeroLocal) +
    "\nNumero Global é igual ao NUMEROCOST OR menor do que o Numero Local : " + (numeroGlobal === NUMEROCONST || numeroGlobal > numeroLocal) 
);

numeroLocal = 14;

console.log(
    "numeroGlobal é igual a numeroLocal? = " +
    (numeroGlobal-- == ++numeroLocal)
);

let varNova = null;

console.log(varNova ?? "Erro");

if (numeroGlobal == numeroLocal) {
    console.log("Numeros iguais");
} else if(numeroGlobal < numeroLocal){
    console.log("Numero Global é menor");
}else{
    console.log("Numero Global é maior");
}

const DIASDASEMANA = ["Segunda", "Terça", "Quarta", "Quinta", "Sexta"];

switch (DIASDASEMANA[6]) {
    case "Segunda":
            console.log("\n Hoje é Segunda");
        break;
    case "Terça":
            console.log("\n Hoje é Terça");
        break;
    case "Quarta":
            console.log("\n Hoje é Quarta");
        break;
    case "Quinta":
            console.log("\n Hoje é Quinta");
        break;
    case "Sexta":
            console.log("\n Hoje é Sexta");
        break;

    default:
            console.log("\n Escolha uma opção válida");
        break;
}

console.log((numeroGlobal == --numeroLocal)? "São Iguais\n" : "São Diferentes\n");

//Estruturas de repetição
let cont = 0;
console.log("\n WHILE");

while (cont < DIASDASEMANA.length) {
    console.log(" - " + DIASDASEMANA[cont] + " - ");
    cont++;
}

cont = 0;
console.log("\n DO WHILE");
do {
    console.log(" - " + DIASDASEMANA[cont] + " - ");
    cont++; 
} while (cont < DIASDASEMANA.length);

console.log("\n FOR");

for (let index = 0; index < DIASDASEMANA.length; index++) {
    console.log(" - " + DIASDASEMANA[index] + " - ");
}

//FOREACH
console.log("\n FOREACH I");

for(let index in DIASDASEMANA){
    console.log(" - " + DIASDASEMANA[index] + " - ");
}

console.log("\n FOREACH OF");
for(let dia of DIASDASEMANA){
    console.log(" - " + dia + " - ");
}










