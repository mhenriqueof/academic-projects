// Formulário Ecoturismo

const ecoturismos = JSON.parse(localStorage.getItem("ecoturismos")) || [];

document.getElementById("formEcoturismo").addEventListener("submit", function(event) {
    event.preventDefault();

    const nome = document.getElementById("nameEcoturismo").value;
    const email = document.getElementById("mailEcoturismo").value;
    const data = document.getElementById("dateEcoturismo").value;
    const destino = document.getElementById("destinationEcoturismo").value;

    if (nome && email && data && destino) {
        adicionarCadastroEcoturismo(nome, email, data, destino);
        document.getElementById("formEcoturismo").reset();
    } else {
        alert("Preencha todos os campos.");
    }

    function adicionarCadastroEcoturismo(nome, email, data, destino) {
        const cadastro = {
            nome: nome,
            email: email,
            data: data,
            destino: destino
        };
    
        ecoturismos.push(cadastro);
        localStorage.setItem("ecoturismos", JSON.stringify(ecoturismos));

        document.getElementById("formEcoturismo").reset();

        alert("Formulário recebido!");
        carregarEcoturismo();
    }
});

// Tabela Ecoturismo

function carregarEcoturismo() {
    
    const tabelaBody = document.querySelector("#tabelaEcoturismo tbody");
    tabelaBody.innerHTML = "";
    
    ecoturismos.forEach((ecoturismo) => {
        const linha = document.createElement("tr");

        linha.innerHTML = `
            <td>${ecoturismo.nome}</td>
            <td>${ecoturismo.email}</td>
            <td>${ecoturismo.data}</td>
            <td>${ecoturismo.destino}</td>
        `;
        tabelaBody.appendChild(linha);
    });
}

window.onload = carregarEcoturismo();
