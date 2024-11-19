if (sessionStorage.getItem("usuarioLogado") != 'true') {
    alert("Você precisa fazer login para acessar a página.");
    window.location.href = "../index.html";
} else {
    document.body.classList.remove('esconder');
}

document.getElementById("logoutAdmin").addEventListener("click", function() {
    sessionStorage.removeItem("usuarioLogado");
    window.location.href = "../index.html";
});
