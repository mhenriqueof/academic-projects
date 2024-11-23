create table if not exists livros (
  livro_id int,
  titulo varchar(200),
  autor varchar(150),
  ano_publicacao year
);

create table if not exists clientes (
  cliente_id int,
  nome varchar(100),
  email varchar(100),
  telefone varchar(15)
);

create table if not exists pedidos (
  pedido_id int,
  cliente_id int,
  data_pedido date,
  valor_total decimal(10,2)
);

create table if not exists funcionarios (
  funcionario_id int,
  nome varchar(100),
  cargo varchar(50),
  salario decimal(12,2)
);

create table if not exists cursos (
  curso_id int,
  nome_curso varchar(100),
  duracao int, -- horas
  descricao text
);

create table if not exists produtos (
  produto_id varchar(150),
  categoria varchar(50),
  preco decimal(8,2)
);

create table if not exists eventos (
  evento_id int,
  nome_evento varchar(100),
  data_evento date,
  localizacao varchar(255)
);

create table if not exists fornecedores (
  fornecedor_id int,
  nome_fornecedor varchar(150),
  endereco varchar(255),
  telefone varchar(15)
);

create table if not exists alunos (
  aluno_id int,
  nome varchar(100),
  data_nascimento date,
  curso varchar(100)
);

create table if not exists transacoes (
  transacao_id int,
  cliente_id int,
  data_transacao datetime,
  valor decimal(10,2)
);



alter table livros add editora varchar(100);

alter table clientes modify telefone varchar(20);
alter table clientes add endereco varchar(255);

alter table pedidos modify valor_total decimal(12,2);
alter table pedidos add status varchar(20);

alter table funcionarios rename column cargo to departamento;
alter table funcionarios add data_contratacao date;

alter table cursos add nivel varchar(50);
alter table cursos modify descricao text;

alter table produtos drop categoria;
alter table produtos add estoque int;

alter table eventos modify localizacao text;
alter table eventos add capacidade int;

alter table fornecedores rename column endereco to endereco_fornecedor;
alter table fornecedores add email varchar(100);

alter table alunos add endereco varchar(255);
alter table alunos modify curso varchar(150);

alter table transacoes add metodo_pagamento varchar(50);
alter table transacoes modify data_transacao timestamp;



drop table funcionarios;
drop table pedidos;

show tables;