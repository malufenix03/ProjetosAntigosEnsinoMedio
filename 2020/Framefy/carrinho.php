<?php
//Sara Burgo Ceschin - Última alteração: 16/09

      session_start();
    
    //Modificado por Luana Rodrigues da Silva e Lima
    //Modificado em:28/09/2020
    //Códigos para redirecionar de página se não estiver logado
      if(!isset($_SESSION['usuario']))
      {
          echo "<script type='text/javascript'> alert('Realize o login para continuar')</script>";
          echo "<meta HTTP-EQUIV='refresh' CONTENT='0;URL=form_login.php'>";
          exit;
      }
    /////////////////////////
      if(!isset($_SESSION['carrinho'])){
         $_SESSION['carrinho'] = array();
      }
       
      //adiciona produto
       
      if(isset($_GET['acao'])){
          
         //ADICIONAR CARRINHO
         if($_GET['acao'] == 'add'){
            $id_produto = intval($_GET['id_produto']); // Código do produto que vem da página index.php
            if(!isset($_SESSION['carrinho'][$id_produto])){
               $_SESSION['carrinho'][$id_produto] = 1;
            }else{
               $_SESSION['carrinho'][$id_produto] += 1;
            }
         }
          
         //REMOVER CARRINHO
         if($_GET['acao'] == 'del'){
            $id_produto = intval($_GET['id_produto']);
            if(isset($_SESSION['carrinho'][$id_produto])){
               unset($_SESSION['carrinho'][$id_produto]);
            }
         }
          
         //ALTERAR QUANTIDADE
         if($_GET['acao'] == 'up'){
            if(is_array($_POST['prod'])){
               foreach($_POST['prod'] as $id_produto => $qtd){
                  $id_produto = intval($id_produto);
				  //desprezar a parte decimal
                  $qtd = intval($qtd);
                  if(!empty($qtd) && $qtd > 0){
                     $_SESSION['carrinho'][$id_produto] = $qtd;
                  }else{
                     unset($_SESSION['carrinho'][$id_produto]);
                  }
               }
            }
         }
       
		 // Modifica a url para remover qualquer uma das ações: add, del ou up, evita que a ação seja
		 // processada novamente caso a página seja recarregada
		 header("location:./carrinho.php");

      }
       
       
?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Framefy - Carrinho</title>
</head>
 
<body>
	<h2>Carrinho de Compras</h2>
	<table>
        <form action="?acao=up" method="post">
		<table border="1">
		<thead>
			<tr>
				<th width="244">Música</th>
				<th width="244">Cantor</th>
				<th width="79">Quantidade</th>
				<th width="89">Pre&ccedil;o</th>
				<th width="100">SubTotal</th>
				<th width="64">Remover</th>
			</tr>
		</thead>
		
		
		  
		<tbody>
		   <?php
			if(count($_SESSION['carrinho']) == 0)
			{
				echo '<tr><td colspan="5">N&atilde;o h&aacute; produto no carrinho</td></tr>';
			}
			else
			{
				require("conexao1.php");
				$total = 0;
				
				foreach($_SESSION['carrinho'] as $id_produto => $qtd)
				{ // Início do FOREACH
					$sql = "SELECT * FROM produto WHERE id_produto=$id_produto AND excluido='n' ORDER BY musica";
					$res = pg_query($conecta, $sql);
					$regs = pg_num_rows($res);
					if($regs>0)
					{
						$linha = pg_fetch_array($res);
						$musica = $linha['musica'];
                        			$cantor = $linha['cantor'];
						$preco = $linha['preco'];
						$sub = $preco * $qtd;
						$total += $sub;
						$preco = number_format($preco, 2, ',', '.');
						$sub = number_format($sub, 2, ',', '.');//formata para padrão brasileiro.
					}

					echo '<tr>    
						 <td>'.$musica.'</td>
                         			 <td>'.$cantor.'</td>
						 <td><input type="text" size="3" name="prod['.$id_produto.']" value="'.$qtd.'" /></td>
						 <td> R$'.$preco.'</td>
						 <td> R$ '.$sub.'</td>
						 <td><a href="?acao=del&id_produto='.$id_produto.'">Remover</a></td>
					  	</tr>';
				}// Término do FOREACH
				 
				$total = number_format($total, 2, ',', '.');
				echo '<tr><td colspan="3">Total</td><td> R$ '.$total.'</td></tr>';
			 }//FECHA ELSE
		   ?>
		
		 </tbody>
		 </table>
		 	<br>		
			<input type="submit" value="Atualizar Carrinho"><br>
			<a href="index1.php">Voltar</a><br>		
			<a href="finalizacompra.php">Finalizar Compra</a><br>
		</form>
    </table>
 
</body>
</html>