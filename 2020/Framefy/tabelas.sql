CREATE TABLE cadastro
(
    id_cliente SERIAL,
    nome VARCHAR(50),
    endereco VARCHAR(70),
    cep INTEGER,
    cpf INTEGER,
    data_nasc DATE,
    sexo character,
    email VARCHAR(50),
    senha VARCHAR,
    tipo VARCHAR(13) CHECK (tipo in ('Administrador','Usuário')),
    excluido character CHECK (excluido in ('s','n')),
    data_exclusao DATE,
    constraint pkcadastro primary key(id_cliente)
);

CREATE TABLE produto
(
    id_produto SERIAL,
    imagem VARCHAR(50),
    cantor VARCHAR(50),
    musica VARCHAR(50),
    genero VARCHAR(50),
    estoque INTEGER,
    preco FLOAT,
    excluido character CHECK (excluido in ('s','n')),
    data_excluido DATE,
    constraint pkproduto primary key (id_produto)
);

CREATE TABLE compra
(
    id_compra SERIAL,
    id_cliente SERIAL,
    id_produto SERIAL,
    quantidade INTEGER,
    preco FLOAT,
    total FLOAT,
    excluido character CHECK (excluido in ('s','n')),
    data_excluido DATE,
    constraint fkcliente foreign key(id_cliente) references cadastro(id_cliente),
    constraint fkproduto foreign key(id_produto) references produto(id_produto),
    constraint pkcompra primary key (id_compra,id_produto)
);

CREATE TABLE redefinir
(
    email VARCHAR(50),
    confirmar VARCHAR
);

INSERT INTO produto values
    (DEFAULT,'adoreyou.jpg','Harry Styles', 'Adore you','Pop',3,39.90,'n',NULL),
    (DEFAULT,'youbelong.jpg','Taylor Swift', 'You Belong With Me','Pop',3,39.90,'n',NULL);
