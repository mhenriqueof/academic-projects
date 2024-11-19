let numero = 7;
// 5! = 5*4*3*2*1 = 120
for (let i = numero - 1 ; i > 1; i--) {
    numero *= i;
    console.log("numero: " + numero + " i " + i);
}

console.log("Resultado fatorial: " + numero);

numero = 7;

for (var res = 1; numero > 1; ) {
    res *= numero--;
}

console.log("Resultado fat 2: " + res);


let base = 5;
let expoente = 3;
// 5^3 = 5*5*5 = 125

let positivo = (expoente > 0) ? true : false;

if (!positivo) { expoente *= -1}

for(var res = base; expoente > 1; expoente--){
    res *= base;
}
res = (positivo)? res : 1/res;

console.log("Resultado da exponenciação: " + res);
