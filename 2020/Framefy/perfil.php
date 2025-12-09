<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:16/09/2020
Última alteração: 27/09/2020
-->
<!DOCTYPE html>
<html lang="pt-br">
   
    <head>
       
        <meta charset="UTF-8">
        <title>Framefy - Login</title>
        <link rel="stylesheet" type="text/css" href="design.css">
        <link rel="icon" type="imagem/png" href="imagens/icone.jpg">
        
    </head>

    <body>
        <center>
        <div class="div_principal">  <section>
        <!-- HEADER -->
        <center>
            
            <div class="header">
              <center>

                   <div class="logo">
                        <a href="index.php">
                            <img id="header_logo" src="imagens/logomarca.jpg">
                        </a>
                    </div>

                   <div class="links">
                        <a class="a_header" href="index.php">HOME</a>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <a class="a_header" href="index.html">PRODUTOS</a>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <a class="a_header" href="form_login.php">LOGIN</a>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <a class="a_header" href="index.html">DEVS</a>

                        <br><br>

                   </div>

                    <div class="busca">
                        <input type="text" id="txtbusca" placeholder="Buscar..."/>
                        <img src="imagens/img_busca.png" id="btnbusca"/>

                    </div>

                    <div class="header_carrinho">
                        <a href="index.html">
                            <img src="imagens/img_carrinho.png" id="img_carrinho"/>
                        </a>
                        <br>

                    </div>

            </center>
        </div>
        </center>
            <br><br><br><br><br><br><br>
                <?php
                    session_start();
                    if(isset($_SESSION['usuario']))
                    {
                        include "conexao1.php";
                        $email=$_SESSION['usuario'];
                        $sql="SELECT * FROM cadastro WHERE email='$email' AND excluido='n';";
                        $resultado=pg_query($conecta,$sql);
                        $linhas=pg_num_rows($resultado);
                        $linha=pg_fetch_array($resultado);
                        if($linhas>0)
                        {
                            echo "<center>
                            PERFIL<br><br>
                            </center>";
                            echo $linha['nome'];
                            echo "<br>
                            <center>
                            <a href=\"perfil.php?compra=1\">
                            Compras realizadas</a>&nbsp;&nbsp;&nbsp;
                            <a href=\"perfil.php?visualizar=1\">Dados pessoais</a>&nbsp;&nbsp;&nbsp;
                            <a href=\"perfil.php?sair=1\">
                            Logout</a>
                            </center>
                            ";
                        }
                        else
                        {
                            echo "Não rolou";
                        }
                        if($_GET['sair']==1)
                        {
                            session_destroy();
                            echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index.php'>";
                        }
                        if($_GET['visualizar']==1)
                        {
                            echo "<br>Nome: ".$linha['nome'];
                            echo "<br>Endereço: ".$linha['endereco'];
                            echo "<br>Email: ".$linha['email'];
                            echo "<br>CEP: ".$linha['cep'];
                            echo "<br>Cpf: ".$linha['cpf'];
                            echo "<br>Data de nascimento: ".$linha['data_nasc'];
                            if($linha['sexo']=='f')
                            {
                                echo "<br>Sexo feminino";
                            }
                            if($linha['sexo']=='m')
                            {
                                echo "<br>Sexo masculino";
                            }
                            if($linha['sexo']=='o')
                            {
                                echo "<br>Outro sexo";
                            }
                            echo "<br><br><a href=\"perfil.php?alterar=1\">Alterar informações</a>";
                            echo "&nbsp;&nbsp;&nbsp<a href=\"perfil.php?senha=1\">Alterar senha</a>";
                        }
                        if($_GET['compra']==1)
                        {
                            
                        }
                        if($_GET['alterar']==1)
                        {
                            $nome=$linha['nome'];
                            $endereco=$linha['endereco'];
                            $email=$linha['email'];
                           $cep=$linha['cep'];
                            $cpf=$linha['cpf'];
                            $data_nasc=$linha['data_nasc'];
                            echo "<form action=\"alterar.php?tudo=1\" method=\"post\">";
                            echo "<br>NOME:<br>";
                            echo "<input type=\"text\" name=\"nome\" pattern=\"[A-Za-záàâãéèêíïóôõöúçñÁÀÂÃÉÈÍÏÓÔÕÖÚÇÑ ]+$\" maxlenght = 50 size = 40  value=\"$nome\" required><br>";

                            echo "<br>ENDEREÇO:<br>";

                            echo "<input type=\"text\" name=\"endereco\" size = 40 value=\"$endereco\" required><br>";

                            echo "<br>CEP:<br>";
                            echo "<input type=\"number\" name=\"cep\" maxlenght = 50 size = 40 value=\"$cep\" required><br>";

                            echo "<br>CPF:<br>";
                            echo "<input type=\"number\" name=\"cpf\" maxlenght = 50 size = 40  value=\"$cpf\" required><br>";

                            echo "<br>DATA DE NASCIMENTO:<br>";
                            echo "<input type=\"date\" name=\"data_nasc\" value=\"$data_nasc\" required><br>";

                            echo "<br>SEXO:<br>";
                            if($linha['sexo']=='f')
                            {
                                echo "<input type=\"radio\" name=\"sexo\" value=\"m\">";
                                echo "<label for=\"masculino\">Masculino</label><br>";
                                echo "<input type=\"radio\" name=\"sexo\" checked value=\"f\">";
                                echo "<label for=\"feminino\">Feminino</label><br>";
                                echo "<input type=\"radio\" name=\"sexo\" value=\"x\">";
                                echo "<label for=\"outro\">Outro</label><br>";
                            }
                            if($linha['sexo']=='m')
                            {
                                echo "<input type=\"radio\" name=\"sexo\" checked value=\"m\">";
                                echo "<label for=\"masculino\">Masculino</label><br>";
                                echo "<input type=\"radio\" name=\"sexo\" value=\"f\">";
                                echo "<label for=\"feminino\">Feminino</label><br>";
                                echo "<input type=\"radio\" name=\"sexo\" checked value=\"x\">";
                                echo "<label for=\"outro\">Outro</label><br>";
                            }
                            if($linha['sexo']=='o')
                            {
                                echo "<input type=\"radio\" name=\"sexo\" value=\"m\">";
                                echo "<label for=\"masculino\">Masculino</label><br>";
                                echo "<input type=\"radio\" name=\"sexo\" value=\"f\">";
                                echo "<label for=\"feminino\">Feminino</label><br>";
                                echo "<input type=\"radio\" name=\"sexo\" value=\"x\">";
                                echo "<label for=\"outro\">Outro</label><br>";
                            }
                            
                            echo "<br>EMAIL:<br>";
                            echo "<input type=\"email\" name=\"mail\" value=\"$email\" required><br>";

                            echo "<label for=\"cliente\">Usuário</label><br>";

                            echo "<br><br><input type=\"submit\" value=\"ENVIAR\"><br><br>";
                            echo "<input type=\"reset\" value=\"LIMPAR\">";

                            echo "</form> ";
                        }
                        if($_GET['senha']==1)
                        {
                            echo "<form action=\"alterar.php?senha=1\" method=\"post\">";
                            echo "
                            <script language=\"javascript\">
                            function passwordChanged() {
                                var strength = document.getElementById('strength');
                                var strongRegex = new RegExp(\"^(?=.{8,})(?=.[A-Z])(?=.[a-z])(?=.[0-9])(?=.\\W).*$\", \"g\");
                                var mediumRegex = new RegExp(\"^(?=.{7,})(((?=.[A-Z])(?=.[a-z]))|((?=.[A-Z])(?=.[0-9]))|((?=.[a-z])(?=.[0-9]))).*$\", \"g\");
                                var enoughRegex = new RegExp(\"(?=.{6,}).*\", \"g\");
                                var pwd = document.getElementById(\"senha\");
                                if (pwd.value.length == 0) {
                                        strength.innerHTML = ' ';
                                } else if (false == enoughRegex.test(pwd.value)) {
                                        strength.innerHTML = 'Mais caracteres';
                                } else if (strongRegex.test(pwd.value)) {
                                        strength.innerHTML = '<span style=\"color:green\">Forte!</span>';
                                } else if (mediumRegex.test(pwd.value)) {
                                        strength.innerHTML = '<span style=\"color:orange\">Intermediária!</span>';
                                } else {
                                        strength.innerHTML = '<span style=\"color:red\">Fraca!</span>';
                                }
                            }
                            </script>
                            <label>
                                Senha<sup>*</sup>: 
                            </label>
                            <input name=\"senha\" id=\"senha\" type=\"text\" size=\"15v\" maxlength=\"100\" onkeyup=\"return passwordChanged();\" required>
                            <br><span id=\"strength\"></span><br><br>
                            <label>
                                Confirmar senha<sup>*</sup>: 
                            </label>
                            <input type=\"password\" name=\"confirme\" required>
                            <br><br>
                                <input type=\"submit\" value=\"Mudar senha\"> ";
                            echo "</form>";
                            if($_SESSION['senha']==1)
                            {
                                echo "<br>Senha inválida";
                                $_SESSION['senha']=0;
                            }

                        }
                    }
                    else
                        echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index.php'>";
                    
                    
                ?>
            
                <!-- FOOTER -->
                <div class="footer">
                   <center>
                       <br><br>
                        <a class="a_header" href="index.php">HOME</a>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <a class="a_header" href="index.html">PRODUTOS</a>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <a class="a_header" href="index.html">LOGIN</a>
                        &nbsp;&nbsp;&nbsp;&nbsp;
                        <a class="a_header" href="index.html">DEVS</a>
                        
                        <br><br>
                        
                        01 - Ana Silva | 
                        08 - Diego Rodrigues | 
                        21 - Leonardo Muto | 
                        25 - Luana Lima | 
                        30 - Sara Ceschin | 
                        32 - Sofia Conti
                        
                        <br><br><br>
                    </center>
                </div>
           </section></div>
        </center>
        
    </body>

</html>