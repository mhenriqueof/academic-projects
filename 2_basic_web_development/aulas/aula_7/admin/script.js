let dados = JSON.parse(localStorage.getItem('dados')) || [];

let nome = document.getElementById('nome');
let quantidade = document.getElementById('quantidade');
let preco = document.getElementById('preco');
let email = document.getElementById('email');

const key = new URLSearchParams(window.location.search).get('chave');

if (key) {
    nome.value = dados[key].nome;
    quantidade.value = dados[key].quantidade;
    preco.value = dados[key].preco;
    email.value = dados[key].email;
    document.querySelector('#formProduto button[type="submit"]').innerText = "Alterar";
}

document.getElementById('formProduto').addEventListener('submit', e =>{
    e.preventDefault();
    const produto ={
        nome: nome.value,
        quantidade: quantidade.value,
        preco: preco.value,
        email: email.value
    };

    (!key)? dados.push(produto) : dados[key] = produto;

    localStorage.setItem('dados', JSON.stringify(dados));

    window.location.href = "./index.html";
});

function atualizarTabela() {
    const tabela = document.querySelector('#tabela tbody');

    dados.forEach((produto, index) => {
        const linha = document.createElement('tr');
        linha.innerHTML = `
        <td>${produto.nome}</td>
        <td>${produto.quantidade}</td>
        <td>${produto.preco}</td>
        <td>${produto.email}</td>
        <td>
            <a href="?chave=${index}">Editar</a>
            <a href="#" onclick="removerProduto(${index})">Excluir</a>
        </td>`;
        tabela.appendChild(linha);
    });
}

function removerProduto(index) {
    dados.splice(index, 1);
    localStorage.setItem('dados', JSON.stringify(dados));
    window.location.reload();
}

window.onload = atualizarTabela;