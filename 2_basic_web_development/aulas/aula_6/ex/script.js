//Criano Header
const header = document.createElement('header');

const homeLink = document.createElement('a');
homeLink.href = '#';
homeLink.textContent = "Home";
header.appendChild(homeLink);

const sobreLink = document.createElement('a');
sobreLink.href = '#';
sobreLink.textContent = "Sobre";
header.appendChild(sobreLink);

const contatoLink = document.createElement('a');
contatoLink.href = '#';
contatoLink.textContent = "Contato";
header.appendChild(contatoLink);

document.body.appendChild(header);

//Criando o Main
const main = document.createElement('main');
document.body.appendChild(main);

//Criando sessão do formulário
const section1 = document.createElement('section');
main.appendChild(section1);

const h1 = document.createElement('h1');
h1.textContent = "Exercício";
const hr = document.createElement('hr');
section1.appendChild(h1);
section1.appendChild(hr);

const formPrincipal = document.createElement('form');

const criarCampo = (nome, tipo, inputId, placeholder) => {
    const label = document.createElement('label');
    //label.htmlFor = inputId; 
    label.setAttribute('for', inputId);
    label.textContent = nome;
    formPrincipal.appendChild(label);

    const input = document.createElement('input');
    input.type = tipo;
    input.name = inputId;
    input.id = inputId;
    input.placeholder = placeholder;
    formPrincipal.appendChild(input);
    formPrincipal.appendChild(document.createElement('br'));
};

criarCampo('Nome: ', 'text', 'nome', 'Digite o seu nome');
criarCampo('CPF: ', 'text', 'nome', 'Digite o seu cpf');
criarCampo('Endereço: ', 'text', 'endereco', 'Digite o seu endereço');
criarCampo('Telefone: ', 'text', 'telefone', 'Digite o seu telefone');
criarCampo('E-mail: ', 'email', 'email', 'Digite o seu e-mail');

const btnEnviar = document.createElement('input');
btnEnviar.type = 'submit';
btnEnviar.value = 'Enviar';

const btnLimpar = document.createElement('input');
btnLimpar.type = 'reset';
btnLimpar.value = 'Limpar';

formPrincipal.appendChild(btnEnviar);
//formPrincipal.append(" | ");
//formPrincipal.appendChild(document.createTextNode(" | "));

const separador = document.createElement('span');
separador.textContent = " | ";
formPrincipal.appendChild(separador);

formPrincipal.appendChild(btnLimpar);

section1.appendChild(formPrincipal);

section1.appendChild(document.createElement('hr'));

//Criando Tabela

const section2 = document.createElement('section');
main.appendChild(section2);

const tabela = document.createElement('table');
const colgroup = document.createElement('colgroup');

const col = () => document.createElement('col');
const colClass = () =>{
    const col = document.createElement('col');
    col.classList.add('fundo-claro');
    return col;
};

colgroup.appendChild(col());
colgroup.appendChild(colClass());
colgroup.appendChild(col());
colgroup.appendChild(colClass());
tabela.appendChild(colgroup);

const thead = document.createElement('thead');
const trThead = document.createElement('tr');

let headers = ['Nome', 'CPF', 'Endereço', 'Telefone', 'E-mail'];

headers.forEach(texto => {
    const th = document.createElement('th');
    th.textContent = texto;
    trThead.appendChild(th);
});

thead.appendChild(trThead);
tabela.appendChild(thead);

const tbody =  document.createElement('tbody');

for(let i = 0; i < 8; i++){
    const tr = document.createElement('tr');
    let dados = ['Paulo', '123456789', 'Rua Brigadeiro Franco', '41 9898989', 'email@email.com'];
    dados.forEach(texto => {
        const td = document.createElement('td');
        td.textContent = texto;
        tr.appendChild(td);
    });
    tbody.appendChild(tr);
}
tabela.appendChild(tbody);

const tfoot = document.createElement('tfoot');
const trTfoot = document.createElement('tr');
const tdTfoot = document.createElement('td');
tdTfoot.colSpan = 5;

const form2 = document.createElement('form');

const btnAnterior = document.createElement('input');
btnAnterior.type = 'button';
btnAnterior.value = 'Anterior';

const btnProximo = document.createElement('input');
btnProximo.type = 'button';
btnProximo.value = 'Proximo';

const select = document.createElement('select');
select.name = 'pagina';
select.id = 'pagina';

for(let i = 1; i < 5; i++){
    const option = document.createElement('option');
    option.value = i;
    option.textContent = i;
    select.appendChild(option);
}

form2.appendChild(btnAnterior);
form2.appendChild(select);
form2.appendChild(btnProximo);

tdTfoot.appendChild(form2);
trTfoot.appendChild(tdTfoot);
tfoot.appendChild(trTfoot);

section2.appendChild(tabela);

//Criando o Footer
const footer = document.createElement('footer');
footer.innerHTML = `<hr>
<p><sup>&copy;</sup>2024 - Todos os direitos Reservados;
</p>`

document.body.appendChild(footer);