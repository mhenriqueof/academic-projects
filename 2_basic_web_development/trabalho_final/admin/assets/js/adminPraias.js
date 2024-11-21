const praias = JSON.parse(localStorage.getItem("praias")) || [];

let nome = document.getElementById("namePraias");
let email = document.getElementById("mailPraias");
let data = document.getElementById("datePraias");
let destino = document.getElementById("destinationPraias");

const key = new URLSearchParams(window.location.search).get("index");

if (key !== null) {
    nome.value = praias[key].nome;
    email.value = praias[key].email;
    data.value = praias[key].data;
    destino.value = praias[key].destino;
    document.querySelector("#formPraias button[type='submit']").innerText = "Alterar";
}

document.getElementById("formPraias").addEventListener("submit", e => {
    e.preventDefault();

    const praia = {
        nome: nome.value,
        email: email.value,
        data: data.value,
        destino: destino.value,
    };

    if (key != null) {
        praias[key] = praia;
    } else {
        praias.push(praia);
    }

    localStorage.setItem("praias", JSON.stringify(praias));
    carregarPraias();
});

function carregarPraias() {
    const tabelaBody = document.querySelector("#adminPraias tbody");
    tabelaBody.innerHTML = "";

    praias.forEach((praia, index) => {
        const linha = document.createElement("tr");

        linha.innerHTML = `
            <td>${praia.nome}</td>
            <td>${praia.email}</td>
            <td>${praia.data}</td>
            <td>${praia.destino}</td>
            <td>
                <button><a href="?index=${index}">Editar</a></button>
                <button onclick="removerPraias(${index})">Remover</button>
            </td>
        `;
        tabelaBody.appendChild(linha);
    });
}

function removerPraias(index) {
    praias.splice(index, 1);
    localStorage.setItem("praias", JSON.stringify(praias));
    carregarPraias();
}

window.onload = carregarPraias();
