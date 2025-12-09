<!--
Programado por: Ana Beatriz da Silva
Criação:09/09/2020
Última alteração: 16/09/2020
-->
<!DOCTYPE html>
<html lang="pt-br">
   
    <head>
       
        <meta charset="UTF-8">
        <title>Framefy - Página Inicial</title>
        <link rel="stylesheet" type="text/css" href="design.css">
        <link rel="icon" type="imagem/png" href="imagens/icone.jpg">
        
    </head>

    <body>
        
        <!-- HEADER -->
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
                    
                    
                    <?php
                   //Modificado por Luana Rodrigues da Silva e Lima
                   //Modificado em:16/09/2020
                   //Códigos abaixo
                        session_start();
                        if(isset($_SESSION['usuario']))
                        {
                           echo "<a class=\"a_header\" href=\"perfil.php\">PERFIL</a>";
                        }
                        else
                        {
                           echo "<a class=\"a_header\" href=\"form_login.php\">LOGIN</a>";
                        }  
                    ?>
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
        
        <!-- DIV PRINCIPAL -->
        <center>
            <div class="div_principal"> <section>
               
                a<br><br><br><br><br><br>
                
                <!-- IMAGEM E TEXTO PRINCIPAIS -->
                <div id="img_principal">
                    <img src="imagens/imagem_principal.jpg" style="width: 400px">
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;
                
                <div id="txt_principal">
                    <br>
                    <h2>NOSSA EMPRESA</h2>
                    <br>
                    <b><i>Framefy</i></b> é uma empresa que produz quadros personalizados com músicas dos mais diversos gêneros e artistas, possibilitando que você decore sua sala, quarto, escritório ou qualquer outro lugar, mostrando seu gosto musical para todos!
                    <br><br><br>
                    <center>
                       <a class="prod_btn" href="index.html">
                            Saber mais
                        </a>
                    </center>
                    
                </div>
                
                <br><br><br><hr><br><br>
                
                <!-- IMAGENS SECUNDÁRIAS -->
                <div class="img_sec">
                    <img src="imagens/img_1.jpg";>
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                
                <div class="img_sec">
                    <img src="imagens/img_2.jpg";>
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                
                <div class="img_sec">
                    <img src="imagens/img_3.jpg";>
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                
                <div class="img_sec">
                    <img src="imagens/img_4.jpg";>
                </div>
                
                <br><br>
                
                <!-- TEXTOS SECUNDÁRIAS -->
                <div class="txt_sec">
                    <h4>PARA GOSTOS ECLÉTICOS!</h4>
                    Nossos produtos variam, desde músicas de rock, pop e até indie.
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                
                <div class="txt_sec">
                    <h4>FÁCIL DE DECORAR!</h4>
                    A aparência minimalista dos quadros permite que eles fiquem bonitos em qualquer canto.
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                
                <div class="txt_sec">
                    <h4>PEÇAS ACESSÍVEIS!</h4>
                    Sem deixar de ter uma mão de obra humanizada, os preços certamente caberão no seu bolso.
                </div>
                
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                
                <div class="txt_sec">
                    <h4>PRODUTOS DE QUALIDADE!</h4>
                    Uma peça de vidro resistente e um adesivo à prova de líquidos.
                </div>
                
                <br><br><br><br><hr><br>
                
                 <!-- VÍDEO E TEXTO -->
                 <div id="txt_video">
                    <br>
                    <h2>NOSSOS PRODUTOS</h2>
                    <br>
                     Os quadrinhos são feitos a partir de adesivos de alta qualidade, colados numa resistente - e fina - placa de vidro. Ao lado, você pode visualizar um exemplo de como eles são produzidos!
                    <br><br>
                    <center>
                       <a class="prod_btn" href="index.html">
                            Ver produtos
                        </a>
                    </center>
                </div>
                
                <div id="video">
                    <iframe width="450" height="250" src="https://www.youtube.com/embed/kPz010cp2kc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
                </div>
                
                <br><br><br><br>
                
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
                        26 - Luana Lima | 
                        30 - Sara Ceschin | 
                        33 - Sofia Conti
                        
                        <br><br><br>
                    </center>
                </div>
                
           </section> </div>
        </center>
        
    </body>

</html>


<!-- CHECKLIST - HOME

     * gradiente do fundo
    
     * imagem principal do produto
     * texto principal
     * imagem secundária 1
     * texto secundário 1
     * imagem secundária 2
     * texto secundário 2
     * imagem secundária 3
     * texto secundário 3 
     * vídeo ilustrativo
     * texto sobre o vídeo
     
-->


<!--  -->