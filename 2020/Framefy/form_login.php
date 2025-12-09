<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:11/09/2020
Última alteração: 16/09/2020
-->
<!DOCTYPE html>
<html lang="pt-br">
   
    <head>
       
        <meta charset="UTF-8">
        <title>Framefy - Login</title>
        <link rel="stylesheet" type="text/css" href="login_design.css">
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
        <!-- DIV PRINCIPAL -->


                <font color=#300b59>
                    
                    <div id="login">
                        <center>
                        <br>
                            <h2>Login</h2>
                        <br>
                        
                        <form  method="post" action="login.php">
                            <label>
                                E-mail<sup>*</sup>: 
                            </label>
                            <input type="email" name="mail" required>
                            <br><br>
                            <label>
                                Senha<sup>*</sup>:
                            </label>
                            <input type="password" name="senha" required>
                            <br><br>
                           
                                <input type="submit" value="Efetuar Login" class="btn">
                        </form>
                            <?php
                                session_start();
                                if(isset($_SESSION['login']))
                                {
                                    if(!$_SESSION['login'])
                                    {
                                        echo "Usuário ou senha incorretos";
                                        $_SESSION['login']=true;
                                    }
                                        
                                }
                                if(isset($_SESSION['usuario']))
                                {
                                    echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index.php'>";
                                    exit();
                                }
                            ?>
                            <br>
                            <br>
                            Não possue login? <a class="cadastro" href="form_cadastro1.html">Faça seu cadastro</a>
                            &nbsp;&nbsp;&nbsp;&nbsp;
                            <a class="cadastro" href="email.html">Esqueceu sua senha?</a>
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