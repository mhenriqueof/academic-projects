const btnLogin = document.getElementById('btnLogin');
const btnFechar = document.getElementById('btnFechar');
const login = document.getElementById('login');
const frmLogin = document.querySelector('#login form');

btnLogin.onclick = function(){
    login.showModal();
    let msgErro = document.querySelector('.erro');
    if (msgErro) {
        login.removeChild(msgErro);
    }
}

btnFechar.onclick = function(){
    login.close();
}

let dadosUsuarios = [
    {nome: "user", email: "", senha: ""},
    {nome: "aluno", email: "aluno@aluno.com", senha: "aluno"}
];

frmLogin.addEventListener('submit', evento =>{
    evento.preventDefault();

    let msgErro = document.querySelector('.erro');
    if (msgErro) {
        login.removeChild(msgErro);
    }

    let email = document.getElementById('email').value;
    let senha = document.getElementById('senha').value;

    dadosUsuarios.forEach(usuario => {
        if(email == usuario.email && senha == usuario.senha){
            sessionStorage.setItem('usuarioLogado', true);
            sessionStorage.setItem('nomeUsuario', usuario.nome);

            window.location.href = "./admin/index.html";
        }
    });

    let logado = sessionStorage.getItem('usuarioLogado');
    if (!logado) {
        let erro = document.createElement('p');
        erro.classList.add('erro');
        erro.innerText = 'Login ou senha inválida';
        login.insertBefore(erro, login.firstChild);
        document.querySelector('#login form').reset();
    }
});
