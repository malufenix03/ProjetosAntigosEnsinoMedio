<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:13/09/2020
Última alteração: 16/09/2020
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
            $senha=$_POST['senha'];
            $confirme=$_POST['confirme'];
            session_start();
            if($senha!=$confirme)
            {
                echo"<script type='text/javascript'> alert('Senha inválida')</script>";
                echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=form_login.php'>";
                exit();
            }
            $cripto=md5($senha);
            $email=$_SESSION['usuario'];
            $sql="UPDATE cadastro set senha='$cripto' WHERE excluido='n' AND email='$email';";
            $resultado=pg_query($conecta,$sql);
            $qtde=pg_affected_rows($resultado);
            if($qtde>0)
            {
                $sql="DELETE from redefinir WHERE email='$email';";
                $resultado=pg_query($conecta,$sql);
                $qtde=pg_affected_rows($resultado);
                pg_close($conecta);
                echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index.html'>";
            }
            else
            {
                session_destroy();
                pg_close($conecta);
                echo"<script type='text/javascript'> alert('Não foi possível mudar senha')</script>";
                echo "<meta HTTP-EQUIV='refresh'
                CONTENT='0;URL=form_login.php'>";
            }
        ?>
    </body>

</html>