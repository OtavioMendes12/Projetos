
        
// // Declara uma função para processar o formulário de login
function processaFormLogin (e) {                
        // Cancela a submissão do formulário para tratar sem fazer refresh da tela
        e.preventDefault ();

        // Obtem os dados de login e senha a partir do formulário de login
        var username = $('#usuario').val();
        var password = $('#senha').val();

        // Valida login e se estiver ok, redireciona para tela inicial da aplicação
        resultadoLogin = loginUser(username, password);
        if (resultadoLogin) {
            let parametrosAlert ={
                
                icon: 'success',
                title: `Logado Com sucesso \n Bem Vindo ao sistema ${username}`,
                showConfirmButton: false,
                timerProgressBar: true,
                timer: 1500
            }
            swal.fire(parametrosAlert).then(()=>{
                window.location.href = "home.html"
            })
        }
        else { // Se login falhou, avisa ao usuário
            let parametrosAlert ={
                icon: 'error',
                title: 'Usuário ou senha incorretos',
            }
            swal.fire(parametrosAlert)
        }
}

function salvaLogin (event) {
    // Cancela a submissão do formulário para tratar sem fazer refresh da tela
    event.preventDefault ();

    // Obtem os dados do formulário
    let login  = $('#txt_login').val();
    let senha  = $('#txt_senha').val();
    let nome   = $('#txt_nome').val();
    let email  = $('#txt_email').val();
    let senha2 = $('#txt_senha2').val();
    if (senha != senha2) {
        let parametrosAlert ={
            icon: 'warning',
            title: 'As senhas informadas não conferem.',
        }
        swal.fire(parametrosAlert)
        return
    }

    // Adiciona o usuário no banco de dados
    addUser(nome, login, senha, email);
    let parametrosAlert ={
                
        icon: 'success',
        title: 'Usuário salvo com sucesso. Proceda com o login para',
        showConfirmButton: false,
        timerProgressBar: true,
        timer: 1500
    }
    swal.fire(parametrosAlert).then(()=>{
        $(".tab-cadastro input").val('')
        $('#usuario').val(login)
        let tab="login";
        $("#Titulo").html(tab)
        $(".card-user").addClass('d-none');
        $(`.tab-${tab}`).removeClass('d-none');
    })

    // Oculta a div modal do login
}

// // Associa a funçao processaFormLogin  formulário adicionado um manipulador do evento submit
$("#login-form").submit(function(e){
    processaFormLogin(e)
})

// // Associar salvamento ao botao
$("#btn_salvar").on("click",function(e){
    e.preventDefault()
    salvaLogin(e)
})

// Verifica se o login do usuário está ok e, se positivo, direciona para a página inicial


$(document).ready(() => {
    $(".tab").on("click", function(e){
        e.preventDefault()
        let tab=$(this).attr('id');
        $("#Titulo").html(tab)
        $(".card-user").addClass('d-none');
        $(`.tab-${tab}`).removeClass('d-none');
    })
})