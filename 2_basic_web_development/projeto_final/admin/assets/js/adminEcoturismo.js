const ecoturismos = JSON.parse(localStorage.getItem("ecoturismos")) || [];

let nome = document.getElementById("nameEcoturismo");
let email = document.getElementById("mailEcoturismo");
let data = document.getElementById("dateEcoturismo");
let destino = document.getElementById("destinationEcoturismo");

const key = new URLSearchParams(window.location.search).get("index");

if (key !== null) {
    nome.value = ecoturismos[key].nome;
    email.value = ecoturismos[key].email;
    data.value = ecoturismos[key].data;
    destino.value = ecoturismos[key].destino;
    document.querySelector("#formEcoturismo button[type='submit']").innerText = "Alterar";
}

document.getElementById("formEcoturismo").addEventListener("submit", e => {
    e.preventDefault();

    const ecoturismo = {
        nome: nome.value,
        email: email.value,
        data: data.value,
        destino: destino.value,
    };

    if (key != null) {
        ecoturismos[key] = ecoturismo;
    } else {
        ecoturismos.push(ecoturismo);
    }

    localStorage.setItem("ecoturismos", JSON.stringify(ecoturismos));
    carregarEcoturismo();
});

function carregarEcoturismo() {
    const tabelaBody = document.querySelector("#adminEcoturismo tbody");
    tabelaBody.innerHTML = "";

    ecoturismos.forEach((ecoturismo, index) => {
        const linha = document.createElement("tr");

        linha.innerHTML = `
            <td>${ecoturismo.nome}</td>
            <td>${ecoturismo.email}</td>
            <td>${ecoturismo.data}</td>
            <td>${ecoturismo.destino}</td>
            <td>
                <button><a href="?index=${index}">Editar</a></button>
                <button onclick="removerEcoturismo(${index})">Remover</button>
            </td>
        `;
        tabelaBody.appendChild(linha);
    });
}

function removerEcoturismo(index) {
    ecoturismos.splice(index, 1);
    localStorage.setItem("ecoturismos", JSON.stringify(ecoturismos));
    carregarEcoturismo();
}

document.getElementById("logoutAdmin").addEventListener("click", function() {
    window.location.href = "../ecoturismo.html";
});

window.onload = carregarEcoturismo();
