create table if not exists autores (
  id int auto_increment primary key,
  nome varchar(100) not null,
  nacionalidade varchar(50) not null
);



create table if not exists livros (
  id int auto_increment primary key,
  titulo varchar(150) not null,
  autor_id int,
  foreign key (autor_id) references autores(id)
);



create table if not exists usuarios (
  id int auto_increment primary key
);

alter table usuarios
add email varchar(100);

alter table usuarios
add constraint email_unico unique(email);



create table if not exists empregados (
  id int auto_increment primary key,
  nome varchar(100) not null,
  salario decimal(10,2) not null,
  check (salario > 0),
  data_admissao date not null
);



create table if not exists produtos (
  preco decimal(10,2)
);

alter table produtos
add constraint check_preco check (preco > 0);



alter table livros
drop foreign key livros_ibfk_1;



create table if not exists clientes (
  id int auto_increment primary key
);

create table if not exists pedidos (
  id int auto_increment primary key,
  cliente_id int,
  foreign key (cliente_id) references clientes(id),
  data_pedido date not null
);

alter table pedidos
drop foreign key pedidos_ibfk_1;

-- Remover a chave estrangeira faz com que se perca a integridade de referência da tabela pedido com a tabela cliente, pois as duas tabelas não possuem mais uma relação direta.



create table if not exists vendas (
  produto_id int,
  vendedor_id int,
  primary key (produto_id, vendedor_id)
);



create table if not exists categorias (
  id int auto_increment primary key
);

drop table produtos;

create table if not exists produtos (
  id int auto_increment primary key,
  categoria_id int,
  foreign key (categoria_id) references categorias(id)
);



alter table categorias
add column tipo varchar(50);

insert into categorias (tipo)
values ("Tipo A"), ("Tipo B"), ("Tipo C");

-- insert into produtos (categoria_id)
-- values (1), (2), (5), (6);

insert into produtos (categoria_id)
values (1), (2), (3), (1);



insert into autores (nome, nacionalidade)
values ('jão', 'br'), ('predo', 'us'), ('florentina', 'jp');

insert into
  livros (titulo, autor_id)
values 
  ('a volta dos que não foram', 1),
  ('um livro', 3),
  ('leia um livro', 3),
  ('nao sei', 2);
  
delete from autores where id = 3;

select * from autores;