// Formulário Cidades

const cidades = JSON.parse(localStorage.getItem("cidades")) || [];

document.getElementById("formCidades").addEventListener("submit", function(event) {
    event.preventDefault();

    const nome = document.getElementById("nameCidades").value;
    const email = document.getElementById("mailCidades").value;
    const data = document.getElementById("dateCidades").value;
    const destino = document.getElementById("destinationCidades").value;

    if (nome && email && data && destino) {
        adicionarCadastroCidades(nome, email, data, destino);
        document.getElementById("formCidades").reset();
    } else {
        alert("Preencha todos os campos.");
    }

    function adicionarCadastroCidades(nome, email, data, destino) {
        const cadastro = {
            nome: nome,
            email: email,
            data: data,
            destino: destino
        };
    
        cidades.push(cadastro);
        localStorage.setItem("cidades", JSON.stringify(cidades));

        document.getElementById("formCidades").reset();

        alert("Formulário recebido!");
        carregarCidades();
    }
});

// Tabela Cidades

function carregarCidades() {
    
    const tabelaBody = document.querySelector("#tabelaCidades tbody");
    tabelaBody.innerHTML = "";
    
    cidades.forEach((cidade) => {
        const linha = document.createElement("tr");

        linha.innerHTML = `
            <td>${cidade.nome}</td>
            <td>${cidade.email}</td>
            <td>${cidade.data}</td>
            <td>${cidade.destino}</td>
        `;
        tabelaBody.appendChild(linha);
    });
}

window.onload = carregarCidades;
