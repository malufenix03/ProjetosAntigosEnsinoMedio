<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:11/09/2020
Última alteração: 13/09/2020
-->
<!DOCTYPE html>
<html lang="pt-br">
   
    <head>
       
        <meta charset="UTF-8">
        <title>Framefy - Login</title>
        <link rel="stylesheet" type="text/css" href="login_design.css">

    </head>

    <body>
        <?php
            include "conexao1.php";
            $email=$_POST['mail'];
            $senha=$_POST['senha'];
            $cripto=md5($senha);
            $sql="SELECT tipo FROM cadastro WHERE excluido='n' AND email='$email' AND senha='$cripto';";
            $resultado=pg_query($conecta,$sql);
            $qtde=pg_num_rows($resultado);
            if($qtde>0)
            {
                $linha=pg_fetch_array($resultado);
                $tipo=$linha['tipo'];
                session_start();
                $_SESSION['usuario']=$email;
                $_SESSION['tipo']=$tipo;
                echo"<script type='text/javascript'>
                alert('Login efetuado com sucesso')</script>";
                pg_close($conecta);
                echo "<meta HTTP-EQUIV='refresh'
                CONTENT='0;URL=index.php'>";
                
            }
            else
            {
                session_start();
                $_SESSION['login']=false;
                pg_close($conecta);
                echo "<meta HTTP-EQUIV='refresh'
                CONTENT='0;URL=form_login.php'>";
            }
        ?>
    </body>

</html>