// Recuperando os dados do Local Storage
let dados = JSON.parse(localStorage.getItem('dados')) || [];

let nome = document.getElementById('nome');
let quantidade = document.getElementById('quantidade');
let preco = document.getElementById('preco');
let email = document.getElementById('email');

// Recuperado QueryParam
const key = new URLSearchParams(window.location.search).get('chave');

// Preenchendo o formulário em cao de alteração
if(key){
    nome.value = dados[key].nome;
    quantidade.value = dados[key].quantidade;
    preco.value = dados[key].preco;
    email.value = dados[key].email;
    document.querySelector('#formProduto button[type="submit"]').innerText = "Alterar";
} 

// Reset da página e QueryParam
document.getElementById('formProduto').addEventListener('reset', function (e) {
    e.preventDefault();
    window.location.href = "./index.html";
});

// Cadastro de produtos
document.getElementById('formProduto').addEventListener('submit', function (e) {
    e.preventDefault();

    // Remover mensagens de erro anteriores
    removerMensagensErro();

    let validado = true;

    // Validação de nome
    if (!nome.value) {
        exibirErro('nome', 'Nome é obrigatório');
        validado = false;
    }

    // Validação de quantidade
    if (!quantidade.value || isNaN(quantidade.value)) {
        exibirErro('quantidade', 'Quantidade inválida');
        validado = false;
    }

    let precoValidado = validarValorMonetario(preco.value);
    // Validação de preço
    if (!precoValidado || isNaN(precoValidado)) {
        console.log(precoValidado);
        exibirErro('preco', 'Preço inválido');
        validado = false;
    }

    // Validação simples de e-mail
    const emailPartes = email.value.split('@');
    if (emailPartes.length !== 2 || !emailPartes[1].includes('.') || emailPartes[0] === '' || emailPartes[1].split('.')[0] === '') {
        exibirErro('email', 'Email inválido');
        validado = false;
    }
    
    // Verificando se passou nas validações
    if (!validado) {
        return;
    }

    // Criando produto
    const produto = {
        nome: nome.value,
        quantidade: quantidade.value,
        preco: precoValidado,
        email: email.value
    };

    // Caso não exista a chave o produto é adicionado, se não ele é alterado
    (!key)? dados.push(produto) : dados[key] = produto;

    // Atualizando o LocalStorage
    localStorage.setItem('dados', JSON.stringify(dados));

     window.location.href = "./index.html";
});

// Validação de valores monetários
function validarValorMonetario(valor){
    valor = valor.replaceAll("R", "").replaceAll("$", "").replaceAll(" ", "");
    if (valor.includes(",")) {
        valor = valor.replaceAll(".", "");
        valor = valor.replace(",", ".");
    }
    console.log(valor);
    return Number(valor);
}

// Função para exibir mensagem de erro abaixo do campo
function exibirErro(campoId, mensagem) {
    const campo = document.getElementById(campoId);
    const erro = document.createElement('p');
    erro.classList.add('erro');
    erro.innerText = mensagem;
    campo.after(erro);
}

// Função para remover mensagens de erro existentes
function removerMensagensErro() {
    const erros = document.querySelectorAll('.erro');
    erros.forEach(erro => erro.remove());
}

// Exibir tabela
function atualizarTabela() {
    const tabela = document.querySelector('#tabela tbody');
    
    // Exibindo dados na tabela
    dados.forEach((produto, index) => {
        // Formatação de preço
        let precoFormatado = Number(produto.preco)
            .toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
        // Formatação de Número
        let qtdeFormatada = Number(produto.quantidade).toLocaleString('pt-br');

        const linha = document.createElement('tr');
        linha.innerHTML = `
            <td>${produto.nome}</td>
            <td>${qtdeFormatada}</td>
            <td>${precoFormatado}</td>
            <td>${produto.email}</td>
        `;
        tabela.appendChild(linha);
    });
}

// Remover produto
function removerProduto(index) {
    dados.splice(index, 1);
    localStorage.setItem('dados', JSON.stringify(dados));
    window.location.reload();
}

// Atualizar a tabela ao carregar a página
window.onload = atualizarTabela;
