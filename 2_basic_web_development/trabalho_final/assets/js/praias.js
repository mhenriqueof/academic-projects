// Formulário Praias

const praias = JSON.parse(localStorage.getItem("praias")) || [];

document.getElementById("formPraias").addEventListener("submit", function(event) {
    event.preventDefault();

    const nome = document.getElementById("namePraias").value;
    const email = document.getElementById("mailPraias").value;
    const data = document.getElementById("datePraias").value;
    const destino = document.getElementById("destinationPraias").value;

    if (nome && email && data && destino) {
        adicionarCadastroPraias(nome, email, data, destino);
        document.getElementById("formPraias").reset();
    } else {
        alert("Preencha todos os campos.");
    }

    function adicionarCadastroPraias(nome, email, data, destino) {
        const cadastro = {
            nome: nome,
            email: email,
            data: data,
            destino: destino
        };
    
        praias.push(cadastro);
        localStorage.setItem("praias", JSON.stringify(praias));

        document.getElementById("formPraias").reset();
        
        alert("Formulário recebido!");
        carregarPraias();
    }
});

// Tabela Praias

function carregarPraias() {
    
    const tabelaBody = document.querySelector("#tabelaPraias tbody");
    tabelaBody.innerHTML = "";
    
    praias.forEach((praia) => {
        const linha = document.createElement("tr");

        linha.innerHTML = `
            <td>${praia.nome}</td>
            <td>${praia.email}</td>
            <td>${praia.data}</td>
            <td>${praia.destino}</td>
        `;
        tabelaBody.appendChild(linha);
    });
}

window.onload = carregarPraias;
