var img = new Image()
img.src = 'trees.jpg';

var titulo = 1;
$('#main2').fadeOut(1)
$('#nav-conteudo-text2').hide(1);

var circle;
var button;
var signIn;
var loader;
var x;
var y;


function showCadastro(){
  $('#main1, #main2').toggle(10);
  $('#nav-conteudo-text1, #nav-conteudo-text2').toggle(1)
}



function materialClick(event) {
  circle = document.querySelector('.circle');
  button = document.querySelector('.button');
  signIn = document.querySelector('.sign-in');
  loader = document.querySelector('.loader');
  x = event.offsetX - circle.offsetWidth / 2;
  y = event.offsetY - circle.offsetHeight / 2;
  
  circle.classList.remove('animate');
  circle.style.left = x + 'px';
  circle.style.top = y + 'px';
  setTimeout(function() {
    circle.classList.add('animate');
    button.classList.add('animate');
    signIn.classList.add('animate');
    loader.classList.add('animate');
    setTimeout(function() {
      loader.classList.add('animateOut');
    }, 1000);
    setTimeout(function() {
      content.classList.add('removed')
    }, 2000);
  }, 50);
  setTimeout(function() {
    window.location.href = "/home.html";
}, 1800);

}
