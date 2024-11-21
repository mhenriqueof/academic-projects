const cidades = JSON.parse(localStorage.getItem("cidades")) || [];

let nome = document.getElementById("nameCidades");
let email = document.getElementById("mailCidades");
let data = document.getElementById("dateCidades");
let destino = document.getElementById("destinationCidades");

const key = new URLSearchParams(window.location.search).get("index");

if (key !== null) {
    nome.value = cidades[key].nome;
    email.value = cidades[key].email;
    data.value = cidades[key].data;
    destino.value = cidades[key].destino;
    document.querySelector("#formCidades button[type='submit']").innerText = "Alterar";
}

document.getElementById("formCidades").addEventListener("submit", e => {
    e.preventDefault();

    const cidade = {
        nome: nome.value,
        email: email.value,
        data: data.value,
        destino: destino.value,
    };

    if (key != null) {
        cidades[key] = cidade;
    } else {
        cidades.push(cidade);
    }

    localStorage.setItem("cidades", JSON.stringify(cidades));
    carregarCidades();
});

function carregarCidades() {
    const tabelaBody = document.querySelector("#adminCidades tbody");
    tabelaBody.innerHTML = "";

    cidades.forEach((cidade, index) => {
        const linha = document.createElement("tr");

        linha.innerHTML = `
            <td>${cidade.nome}</td>
            <td>${cidade.email}</td>
            <td>${cidade.data}</td>
            <td>${cidade.destino}</td>
            <td>
                <button><a href="?index=${index}">Editar</a></button>
                <button onclick="removerCidades(${index})">Remover</button>
            </td>
        `;
        tabelaBody.appendChild(linha);
    });
}

function removerCidades(index) {
    cidades.splice(index, 1);
    localStorage.setItem("cidades", JSON.stringify(cidades));
    carregarCidades();
}


document.getElementById("logoutAdmin").addEventListener("click", function() {
    window.location.href = "../cidades.html";
});

window.onload = carregarCidades();
