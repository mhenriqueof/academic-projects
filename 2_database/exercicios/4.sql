-- 1
create table if not exists estudantes (
  id int auto_increment primary key,
  nome varchar(100) not null,
  nota decimal(5,2) not null
);

insert into 
  estudantes (nome, nota)
values
  ('tancredo', 7),
  ('carla', 5),
  ('pao', 9);
  
update
  estudantes
set
  nota = 9.50
where
  id = 3;
  
-- select * from estudantes;



-- 2
create table if not exists produtos (
  id int auto_increment primary key,
  nome varchar(100) not null,
  preco decimal(10,2) not null
);

insert into
  produtos (nome, preco)
values
  ('Produto A', 19.99),
  ('Produto B', 29.49),
  ('Produto C', 15.75),
  ('Produto D', 145.00),
  ('Produto E', 22.30);
  
update
  produtos
set 
  preco = preco * 1.15
where
  preco < 100;
  
-- select * from produtos;



-- 3
create table if not exists clientes (
  id int auto_increment primary key,
  nome varchar(100) not null,
  email varchar(100),
  telefone varchar(15)
);

insert into
  clientes (nome, email, telefone)
values
  ('João Silva', 'joao.silva@example.com', '1234-5678'),
  ('Maria Oliveira', 'maria.oliveira@example.com', '2345-6789'),
  ('Carlos Souza', 'carlos.souza@example.com', '3456-7890'),
  ('Ana Pereira', 'ana.pereira@example.com', '4567-8901'),
  ('Lucas Costa', 'lucas.costa@example.com', '5678-9012');
  
update
  clientes
set
  nome = "Ana Costa",
  telefone = '99999-9999'
where
  id = 4;

-- select * from clientes;



-- 4
create table if not exists vendas (
  id int auto_increment primary key,
  produto_id int not null,
  valor decimal(10,2) not null
);

create table if not exists ajustes_valores (
  produto_id int not null,
  ajuste decimal(10,2) not null
);


insert into 
  vendas (produto_id, valor)
values
  (1, 100.50),
  (2, 200.75),
  (3, 150.00),
  (4, 300.20),
  (5, 250.40);

insert into
  ajustes_valores (produto_id, ajuste)
values
  (1, 10.00),
  (4, -5.50),
  (2, 7.25);


update 
  vendas
set 
  vendas.valor = vendas.valor + (select ajustes_valores.ajuste from ajustes_valores where ajustes_valores.produto_id = vendas.produto_id)
where 
  exists (select 1 from ajustes_valores where ajustes_valores.produto_id = vendas.produto_id);

-- select * from vendas;



-- 5
create table if not exists funcionarios (
  id int auto_increment primary key,
  nome varchar(100) not null,
  salario decimal(10,2) not null,
  data_admissao date not null
);

insert into
  funcionarios (nome, salario, data_admissao)
values
  ('Ana Silva', 3500.00, '2023-01-15'),
  ('Carlos Souza', 4200.00, '2022-05-20'),
  ('Mariana Lima', 3800.00, '2021-11-30'),
  ('Pedro Santos', 4500.00, '2020-07-10'),
  ('Fernanda Costa', 4000.00, '2019-03-25');

update
  funcionarios
set 
  salario = salario * 1.10
where
  data_admissao < '2020-01-01';

-- select * from funcionarios;



-- 6
create table if not exists pedidos (
  id int auto_increment primary key,
  cliente_id int not null,
  status varchar(20) not null,
  valor_total decimal(10,2) not null
);

insert into
  pedidos (cliente_id, status, valor_total)
values
  (1, 'Pendente', 550.75),
  (2, 'Aprovado', 320.50),
  (3, 'Cancelado', 0.00),
  (2, 'Pendente', 210.30),
  (5, 'Aprovado', 450.00);

update
  pedidos
set
  status = 'Aprovado'
where
  valor_total > 500 or cliente_id = 2;

select * from pedidos;



-- 7
create table if not exists estoque (
  id int auto_increment primary key,
  produto varchar(100) not null,
  quantidade int not null
);

insert into
  estoque (produto, quantidade)
values
  ('Produto A', 50),
  ('Produto B', 30),
  ('Produto C', 20),
  ('Produto D', 40),
  ('Produto E', 10);

select 
  quantidade
from
  estoque
where
  id = 3;
  


-- 8
create table if not exists eventos (
  id int auto_increment primary key,
  data_evento date,
  local varchar(100)
);

create table if not exists novos_eventos (
  id int auto_increment primary key,
  data_evento date,
  local varchar(100)
);

insert into 
  eventos (data_evento, local)
values
  ('2024-10-15', 'Curitiba'),
  ('2024-11-20', 'São Paulo'),
  ('2024-12-05', 'Rio de Janeiro');

insert into 
  novos_eventos (data_evento, local)
values
  ('2024-11-01', 'Porto Alegre'),
  ('2024-12-10', 'Belo Horizonte'),
  ('2025-01-20', 'Salvador');
  
update 
  eventos
set 
  eventos.data_evento = (select novos_eventos.data_evento from novos_eventos where novos_eventos.id = eventos.id)
where 
  exists (select 1 from novos_eventos where novos_eventos.id = eventos.id);

select * from eventos;