<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:12/09/2020
Última alteração: 27/09/2020
-->
<!DOCTYPE html>
<html lang="pt-br">
   
    <head>
       
        <meta charset="UTF-8">
        <title>Framefy - Redefinir senha</title>
        <link rel="stylesheet" type="text/css" href="login_design.css">
        <link rel="icon" type="imagem/png" href="imagens/icone.jpg">
        
    </head>

    <body>
        <?php
            include "conexao1.php";
            $usuario=$_GET['usuario'];
            $confirmar=$_GET['confirmar'];
            $sql="SELECT * from redefinir WHERE email='$usuario' AND confirmar='$confirmar';";
            $resultado=pg_query($conecta,$sql);
            $linhas=pg_num_rows($resultado);
            if($linhas>0)
            {
                session_start();
                $_SESSION['usuario']=$usuario;
            }
            else
            {
                echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index.php'>";
                exit();
            }
        
        ?>
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
        <!-- DIV PRINCIPAL -->
            
            
                <font color=#300b59>
                    
                     <div id="email">
                        <center>
                            <h2>Redefinir senha</h2>
                        <br>
                        
                        <form  method="post" action="redefinir.php">
                            
                            <script language="javascript">
                            function passwordChanged() {
                                var strength = document.getElementById('strength');
                                var strongRegex = new RegExp("^(?=.{8,})(?=.[A-Z])(?=.[a-z])(?=.[0-9])(?=.\\W).*$", "g");
                                var mediumRegex = new RegExp("^(?=.{7,})(((?=.[A-Z])(?=.[a-z]))|((?=.[A-Z])(?=.[0-9]))|((?=.[a-z])(?=.[0-9]))).*$", "g");
                                var enoughRegex = new RegExp("(?=.{6,}).*", "g");
                                var pwd = document.getElementById("senha");
                                if (pwd.value.length == 0) {
                                        strength.innerHTML = ' ';
                                } else if (false == enoughRegex.test(pwd.value)) {
                                        strength.innerHTML = 'Mais caracteres';
                                } else if (strongRegex.test(pwd.value)) {
                                        strength.innerHTML = '<span style="color:green">Forte!</span>';
                                } else if (mediumRegex.test(pwd.value)) {
                                        strength.innerHTML = '<span style="color:orange">Intermediária!</span>';
                                } else {
                                        strength.innerHTML = '<span style="color:red">Fraca!</span>';
                                }
                            }
                            </script>
                            <label>
                                Nova senha<sup>*</sup>: 
                            </label>
                            <input name="senha" id="senha" type="text" size="15v" maxlength="100" onkeyup="return passwordChanged();" required>
                            <br><span id="strength"> </span><br><br>
 
                            <label>
                                Confirmar senha<sup>*</sup>: 
                            </label>
                            <input type="password" name="confirme" required>
                            <br><br>
                                <input type="submit" value="Mudar senha" class="email">
                        </form> <br><br>
                        </center>
                    </div>
                                 
                </font>
                <center>
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
                </center>
           </section></div>
        </center>
        
    </body>

</html>