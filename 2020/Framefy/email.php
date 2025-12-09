<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:12/09/2020
Última alteração: 16/09/2020
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
        <center>
        <div class="div_principal">  <section>
        <!-- HEADER -->
        <center>
            
            <div class="header">
              <center>

                   <div class="logo">
                        <a href="index.html">
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
                        <?php                            
                            $email=$_POST['mail'];
                            include "conexao1.php";
                            $sql="SELECT * from cadastro WHERE excluido='n' AND email='$email';";
                            $resultado=pg_query($conecta,$sql);
                            $linhas=pg_num_rows($resultado);
                            if($linhas>0)
                            {
                                $aleatorio="";
                                $caracteres= "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                $tamanho=strlen($caracteres)-1;
                                $vezes=rand(30,50);
                                for($i=0;$i<$vezes;$i++)
                                {
                                    $letra=$caracteres[rand(0,$tamanho)];
                                    $aleatorio.=$letra;
                                }
                                $link="200.145.153.175/luanalima/framefy/senha.php?usuario=$email&confirmar=$aleatorio";
                                
                                $sql="INSERT INTO redefinir VALUES ('$email','$aleatorio');";
                                $resultado=pg_query($conecta,$sql);
                                $linhas=pg_affected_rows($resultado);
                                if($linhas<=0)
                                {
                                    echo "Não executou";
                                    exit();
                                }
                                // Inclui o arquivo class.phpmailer.php localizado na mesma pasta do arquivo php 
                                include "PHPMailer-master/PHPMailerAutoload.php";
                                
                                //This should be done in your php.ini, but this is how to do it if you don't have access to that
                                date_default_timezone_set('Etc/UTC');

                                // Inicia a classe PHPMailer 
                                $mail = new PHPMailer(); 
                                

                                // Método de envio 
                                $mail->IsSMTP(); 
                                


                                // Enviar por SMTP 
                                $mail->Host = "smtp.gmail.com"; 

                                // Você pode alterar este parametro para o endereço de SMTP do seu provedor 
                                $mail->Port = 465; 
                                

                                $mail->SMTPSecure = 'ssl';

                                // Usar autenticação SMTP (obrigatório) 
                                $mail->SMTPAuth = true; 

                                // Usuário do servidor SMTP (endereço de email) 
                                // obs: Use a mesma senha da sua conta de email 
                                $mail->Username = 'framefy.equipeE@gmail.com'; 
                                $mail->Password = 'framefy2020'; 


                                // Define o remetente 
                                // Seu e-mail 
                                $mail->From = "framefy.equipeE@gmail.com"; 

                                // Seu nome 
                                $mail->FromName = "Framefy"; 

                                // Define o(s) destinatário(s) 
                                $mail->AddAddress($email); 


                                // Charset (opcional) 
                                $mail->CharSet = 'UTF-8'; 

                                // Assunto da mensagem 
                                $mail->Subject = "Redefinir senha"; 

                                // Corpo do email 
                                $mail->msgHTML("<html>de: Framefy<br/>email: framefy.equipeE@gmail.com<br/>mensagem: Link para redefinição de senha: $link </html>");
                                $mail->AltBody = "Link para redefinição de senha: $link"; 


                                // Envia o e-mail 
                                $enviar = $mail->Send(); 

                                // Exibe uma mensagem de resultado 
                                if($enviar)
                                {
                                    echo "<script type='text/javascript'> alert('E-mail foi enviado com sucesso, se não encontrá-lo cheque o seu spam')</script>";
                                    echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=form_login.php'>";
                                }
                                else
                                {
                                    echo "<script type='text/javascript'> alert('Não foi possível enviar o e-mail, tente novamente mais tarde: $mail->ErrorInfo')</script>";
                                    echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=email.html'>";
                                }
                            }
                            else
                            {
                                echo"<script type='text/javascript'> alert('Esse e-mail não está cadastrado')</script>";
                                echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=email.html'>";
                            }
                                
                            pg_close($conecta);      
                        ?>
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
                        <a class="a_header" href="form_login.php">LOGIN</a>
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