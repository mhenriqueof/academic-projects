// Header
const header = document.createElement('header');
document.body.appendChild(header);

const homeLink = document.createElement('a');
homeLink.href = '#';
homeLink.textContent = 'Home';
header.appendChild(homeLink);

const sobreLink = document.createElement('a');
sobreLink.href = '#';
sobreLink.textContent = 'Sobre';
header.appendChild(sobreLink);

const contatoLink = document.createElement('a');
contatoLink.href = '#';
contatoLink.textContent = 'Contato';
header.appendChild(contatoLink);


// Main
const main = document.createElement('main');
document.body.appendChild(main);

// Formulário
const section1 = document.createElement('section');
main.appendChild(section1);

const h2 = document.createElement('h2');
section1.appendChild(h2);
h2.textContent = 'Exercício';

section1.appendChild(document.createElement('hr'));


const form = document.createElement('form');
section1.appendChild(form);

const campo = (id, campo, placeholder) => {
    const label = document.createElement('label');
    form.appendChild(label);
    label.setAttribute('for', id);
    label.textContent = campo;

    const input = document.createElement('input');
    form.appendChild(input);
    input.type = 'text';
    input.name = id;
    input.id = id;
    input.placeholder = placeholder;
    form.appendChild(document.createElement('br'));
}

campo('nome', 'Nome:', 'Insira Nome aqui');
campo('cpf', 'CPF:', 'Insira CPF aqui');
campo('endereco', 'Endereço:', 'Insira Endereço aqui');
campo('telefone', 'Telefone:', 'Insira Telefone aqui');
campo('email', 'Email:', 'Insira Email aqui');

const btnEnviar = document.createElement('input');
form.appendChild(btnEnviar);
btnEnviar.type = 'submit';
btnEnviar.value = 'Enviar';

const separador = document.createElement('span');
form.appendChild(separador);
separador.textContent = ' | '

const btnLimpar = document.createElement('input');
form.appendChild(btnLimpar);
btnLimpar.type = 'reset';
btnLimpar.value = 'Limpar';

section1.appendChild(document.createElement('hr'));

// Tabela
const section2 = document.createElement('section');
main.appendChild(section2);

const table = document.createElement('table');
section2.appendChild(table);
