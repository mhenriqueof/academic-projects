const menu = document.getElementsByClassName('menu');
for (let i = 0; i < 3; i++) {
    menu[i].style.textDecoration = 'none';
    menu[i].style.padding = '10px';
}


const cabecalho = document.getElementById('cabecalho');
cabecalho.style.textAlign = 'center';


const input = document.getElementsByClassName('input');
for (let i = 0; i < input.length; i++) {
    input[i].style.margin = '8px';
}

const but = document.getElementsByClassName('but');
for (let i = 0; i < but.length; i++) {
    but[i].style.margin = '10px';
}

const table = document.getElementById('table');
table.style.width = '100%';
table.style.borderCollapse = 'collapse';

const thead = document.getElementById('thead');
thead.style.backgroundColor = '#0085a6';
thead.style.color = 'white';

const ts = document.getElementsByClassName('ts');
for (let i = 0; i < ts.length; i++) {
    ts[i].style.border = '1px solid black';
    ts[i].style.padding = '8px';
    ts[i].style.textAlign = 'center';
}

let cont = 6;
while (cont < ts.length) {
    ts[cont].style.backgroundColor = '#7cd1f2';
    cont += 2;
    ts[cont].style.backgroundColor = '#7cd1f2';
    cont += 3;
}

const buttons = document.getElementById('buttons');
buttons.style.display = 'flex';
buttons.style.justifyContent = 'center';
buttons.style.margin = '20px';
