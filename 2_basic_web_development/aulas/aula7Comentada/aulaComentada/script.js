// Pegando os links do menu
const menu = document.querySelectorAll('nav a');

menu.forEach(link => {   
    link.addEventListener('click', evento => {
        evento.preventDefault();
        const href = link.getAttribute('href');
        const alvo = document.querySelector(href);

        // Rolando a página até o id alvo
        if (alvo) {
            window.scroll({
                top: alvo.offsetTop -20,
                behavior: 'smooth'
            });
        }
   })
});

// Evento de Scroll
window.addEventListener('scroll', () => {
    if (window.scrollY > 100) {
        menu.forEach( m =>{
            m.classList.add('shrink');
        });
    } else {
        menu.forEach( m =>{
            m.classList.remove('shrink');
        });
    }
});

// Selecionando a tag foot
const footer = document.getElementsByTagName('footer')[0];
const paragrafo = footer.firstElementChild; 
// Formatação de datas
paragrafo.innerHTML += " " + new Date().toLocaleDateString('pt-br');
paragrafo.innerHTML += " " + new Date().toLocaleString('pt-br');
// Formatação de horas.
paragrafo.innerHTML += " " + new Date().toLocaleTimeString('pt-br', { hour: '2-digit', minute: '2-digit', hour12: false });;