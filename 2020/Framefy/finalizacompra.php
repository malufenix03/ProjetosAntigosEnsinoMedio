<!--
Programado por: Luana Rodrigues da Silva e Lima
Criação:28/09/2020
Última alteração: 29/09/2020
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
            <br><br><br><br><br><br><br>
                <?php
                    session_start();
                    $email=$_SESSION['usuario'];
                    include "conexao1.php";
                    $sql="SELECT * FROM cadastro where email=$email AND excluido='n';";
                    $resultado=pg_query($select,$conecta);
                    $linhas=pg_num_rows($resultado);
                    $linha=pg_fetch_array($resultado);
                    $id_cliente=$linha['id_cliente'];
                    $sql="SELECT * FROM produto;";
                    $resultado=pg_query($select,$conecta);
                    $linhas=pg_num_rows($resultado);
                    $flag=true;
                    for($i=0;$i<$linhas;$i++)
                    {
                        if(isset($_SESSION['carrinho'][$i]))
                        {
                            $sql="SELECT * FROM produto where id_produto=$i AND excluido='n';";
                            $resultado=pg_query($select,$conecta);
                            $linhas=pg_num_rows($resultado);
                            if($linhas>0)
                            {
                                $linha=pg_fetch_array($resultado);
                                $quant=$linha['estoque'];
                                if($quant==0)
                                {
                                    echo "<script type='text/javascript'> alert('Produto esgotado')</script>";
                                    echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index1.php'>";
                                    exit;
                                }
                                $quantidade=$_SESSION['carrinho'][$i];
                                $estoque=$quant-quantidade;
                                if($estoque<0)
                                {
                                    echo "<script type='text/javascript'> alert('Quantidade do produto que deseja comprar está fora de estoque')</script>";
                                    echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index1.php'>";
                                    exit;
                                }
                            }
                        }
                    }
                    $sql="SELECT * FROM compra;";
                    $resultado=pg_query($select,$conecta);
                    $linhas=pg_num_rows($resultado);
                    $auxiliar=1;    
                    for($i=0;$i<$linhas;$i++)
                    {
                        
                        $linha=pg_fetch_array($resultado);
                        $id=$linha['id_compra'];
                        if($auxiliar==$id)
                        {
                            $auxiliar++;
                        }
                    }
                    for($i=0;$i<$linhas;$i++)
                    {
                        if(isset($_SESSION['carrinho'][$i]))
                        {
                            $sql="SELECT * FROM produto where id_produto=$i AND excluido='n';";
                            $resultado=pg_query($select,$conecta);
                            $linhas=pg_num_rows($resultado);
                            if($linhas>0)
                            {
                                $linha=pg_fetch_array($resultado);
                                $quant=$linha['estoque'];
                                $quantidade=$_SESSION['carrinho'][$i];
                                $estoque=$quant-quantidade;
                                $prec=$linha['preco'];
                                $total=$prec*$quantidade;
                                $sql="UPDATE produto set estoque=$estoque WHERE id_produto=$i AND excluido='n';";
                                $resultado=pg_query($select,$conecta);
                                $linhas=pg_affected_rows($resultado);
                                if($linhas<=0)
                                {
                                    $flag=false;
                                    break;
                                }
                            }
                        }
                        
                        $sql="INSERT INTO compra VALUES ($auxiliar,$id_cliente,$id_produto,$quantidade,$preco,$total,'n',NULL);";
                        $resultado=pg_query($select,$conecta);
                        $linhas=pg_affected_rows($resultado);
                    }
                    if($flag)
                    {
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
                         $mail->Subject = "Compra realizada"; 

                         // Corpo do email 
                         $mail->msgHTML("<html>de: Framefy<br/>email: framefy.equipeE@gmail.com<br/>mensagem: Compras realizada com sucesso</html>");
                         $mail->AltBody = "Compra realizada"; 


                         // Envia o e-mail 
                         $enviar = $mail->Send(); 

                         // Exibe uma mensagem de resultado 
                         if($enviar)
                         {
                             echo "<script type='text/javascript'> alert('Compra realizada com sucesso, um email foi enviado')</script>";
                             echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=form_login.php'>";
                         }
                         else
                         {
                             echo "<script type='text/javascript'> alert('Compra realizada com sucesso, porém não foi possível enviar um email: $mail->ErrorInfo')</script>";
                             echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=email.html'>";
                         }
                    }
                    else
                    {
                        echo"<script type='text/javascript'> alert('Não foi possível realizar compra')</script>";
                        echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=index1.php'>";
                    }

                    pg_close($conecta);
                    $sql="SELECT * FROM compra WHERE excluido='n' AND"
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