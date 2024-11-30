create database if not exists trabalho_a1;
use trabalho_a1;

-- Parte 1: Modelagem do Banco de Dados

create table if not exists categorias (
  categoria_id int auto_increment primary key,
  nome varchar(50) not null,
  descricao text
);

create table if not exists fornecedores (
  fornecedor_id int auto_increment primary key,
  nome varchar(100) not null,
  contato varchar(50),
  endereco varchar(150),
  cidade varchar(50)
);

create table if not exists produtos (
  produto_id int auto_increment primary key,
  nome varchar(100) not null,
  descricao text,
  preco decimal(10,2) not null,
  estoque int not null,
  categoria_id int,
  fornecedor_id int,
  foreign key (categoria_id) references categorias(categoria_id),
  foreign key (fornecedor_id) references fornecedores(fornecedor_id)
);

create table if not exists clientes (
  cliente_id int auto_increment primary key,
  nome varchar(100) not null,
  email varchar(100),
  telefone varchar(20),
  cpf varchar(14) not null,
  endereco varchar(150),
  cidade varchar(50)
);

create table if not exists funcionarios (
  funcionario_id int auto_increment primary key,
  nome varchar(100) not null,
  cargo varchar(50) not null,
  salario decimal(10,2) not null,
  data_contratacao date,
  email varchar(100),
  telefone varchar(20)
);

create table if not exists pedidos (
  pedido_id int auto_increment primary key,
  data_pedido date not null,
  cliente_id int,
  funcionario_id int,
  status varchar(20),
  foreign key (cliente_id) references clientes(cliente_id),
  foreign key (funcionario_id) references funcionarios(funcionario_id)
);

create table if not exists itens_pedido (
  item_pedido_id int auto_increment primary key,
  pedido_id int,
  produto_id int,
  quantidade int not null,
  preco_unitario decimal(10,2) not null,
  foreign key (pedido_id) references pedidos(pedido_id),
  foreign key (produto_id) references produtos(produto_id)
);

create table if not exists pagamentos (
  pagamento_id int auto_increment primary key,
  pedido_id int,
  valor decimal(10,2) not null,
  metodo_pagamento varchar(50),
  data_pagamento date,
  foreign key (pedido_id) references pedidos(pedido_id)
);



-- Parte 2: Operações de Manipulação de Dados

-- Inserts
insert into
  categorias (nome, descricao)
values
  ('Alimentos Básicos', 'Produtos essenciais para o dia a dia'),
  ('Bebidas', 'Variedades de bebidas para consumo'),
  ('Laticínios', 'Produtos derivados do leite'),
  ('Padaria', 'Itens de panificação frescos'),
  ('Limpeza e Higiene', 'Produtos para manutenção da limpeza e higiene');
  
insert into
  fornecedores (nome, contato, endereco, cidade)
values
  ('Fornecedor de Alimentos Básicos', '41987654321', 'Rua A, 123', 'Curitiba'),
  ('Fornecedor de Bebidas', '41987654322', 'Avenida B, 456', 'Londrina'),
  ('Fornecedor de Laticínios', '41987654323', 'Praça C, 789', 'São Paulo'),
  ('Fornecedor de Padaria', '41987654324', 'Rua D, 101', 'Curitiba'),
  ('Fornecedor de Limpeza e Higiene', '41987654325', 'Avenida E, 202', 'Florianópolis');

insert into
  produtos (nome, descricao, preco, estoque, categoria_id, fornecedor_id)
values
  ('Arroz', 'Arroz branco 1kg', 4.50, 25, 1, 1),
  ('Feijão', 'Feijão carioca 1kg', 6.80, 30, 1, 1),
  ('Macarrão', 'Macarrão espaguete 500g', 3.20, 15, 1, 1),
  ('Suco', 'Suco de uva 500ml', 8.50, 50, 2, 2),
  ('Refrigerante', 'Refrigerante 1L', 9.90, 10, 2, 2),
  ('Leite', 'Leite integral 1L', 3.80, 5, 3, 2),
  ('Manteiga', 'Manteiga com sal 200g', 7.50, 3, 3, 3),
  ('Queijo', 'Queijo mussarela 1kg', 30.00, 12, 3, 3),
  ('Pão', 'Pão de forma 500g', 5.50, 25, 4, 4),
  ('Bolo', 'Bolo de chocolate 1kg', 4.00, 20, 4, 4),
  ('Detergente', 'Detergente líquido 500ml', 2.50, 60, 5, 5),
  ('Sabão', 'Sabão em pó 1kg', 7.20, 40, 5, 5),
  ('Shampoo', 'Shampoo 350ml', 12.00, 7, 5, 5),
  ('Condicionador', 'Condicionador 350ml', 12.00, 2, 5, 5),
  ('Papel Higiênico', 'Papel higiênico 12 rolos', 15.00, 35, 5, 5);
  
insert into 
  clientes (nome, email, telefone, cpf, endereco, cidade)
values
  ('Ana Silva', 'ana.silva@email.com', '41981234567', '123.456.789-00', 'Rua A, 100', 'Curitiba'),
  ('Bruno Souza', 'bruno.souza@email.com', '41981234568', '234.567.890-11', 'Avenida B, 200', 'São Paulo'),
  ('Carlos Lima', 'carlos.lima@email.com', '41981234569', '345.678.901-22', 'Praça C, 300', 'Rio de Janeiro'),
  ('Daniela Ferreira', 'daniela.ferreira@email.com', '41981234570', '456.789.012-33', 'Rua D, 400', 'Belo Horizonte'),
  ('Eduardo Costa', 'eduardo.costa@email.com', '41981234571', '567.890.123-44', 'Avenida E, 500', 'Porto Alegre'),
  ('Fernanda Almeida', 'fernanda.almeida@email.com', '41981234572', '678.901.234-55', 'Praça F, 600', 'Recife'),
  ('Gustavo Pereira', 'gustavo.pereira@email.com', '41981234573', '789.012.345-66', 'Rua G, 700', 'Salvador'),
  ('Helena Martins', 'helena.martins@email.com', '41981234574', '890.123.456-77', 'Avenida H, 800', 'Fortaleza'),
  ('Isabela Santos', 'isabela.santos@email.com', '41981234575', '901.234.567-88', 'Praça I, 900', 'Manaus'),
  ('João Oliveira', 'joao.oliveira@email.com', '41981234576', '012.345.678-99', 'Rua J, 1000', 'Curitiba');

insert into
  funcionarios (nome, cargo, salario, data_contratacao, email, telefone)
values
  ('Mariana Oliveira', 'Gerente', 5000.00, '2022-01-15', 'mariana.oliveira@email.com', '41981234577'),
  ('Carlos Almeida', 'Vendedor', 2500.00, '2023-02-10', 'carlos.almeida@email.com', '41981234578'),
  ('Fernanda Sousa', 'Caixa', 2200.00, '2021-03-20', 'fernanda.sousa@email.com', '41981234579'),
  ('Rodrigo Pereira', 'Estoque', 2000.00, '2020-04-25', 'rodrigo.pereira@email.com', '41981234580'),
  ('Ana Martins', 'Responsável por Pedidos', 2700.00, '2023-05-30', 'ana.martins@email.com', '41981234581'),
  ('João Silva', 'Responsável por Pedidos', 2700.00, '2022-06-12', 'joao.silva@email.com', '41981234582'),
  ('Maria Jose', 'Responsável por Pedidos', 2700.00, '2020-02-21', 'maria.jose@email.com', '41989237522');

insert into
  pedidos (data_pedido, cliente_id, funcionario_id, status)
values
  ('2024-01-01', 1, 2, 'Concluído'),
  ('2024-10-02', 2, 4, 'Em andamento'),
  ('2024-07-03', 3, 6, 'Concluído'),
  ('2024-09-04', 4, 6, 'Em andamento'),
  ('2024-05-05', 5, 5, 'Concluído'),
  ('2024-02-06', 6, 6, 'Em andamento'),
  ('2024-06-07', 7, 5, 'Concluído'),
  ('2024-11-08', 8, 6, 'Em andamento'),
  ('2024-05-05', 5, 5, 'Concluído'),
  ('2024-01-09', 9, 5, 'Concluído'),
  ('2024-05-05', 5, 5, 'Concluído'),
  ('2024-05-05', 5, 5, 'Concluído'),
  ('2024-11-10', 10, 6, 'Em andamento');

insert into
  itens_pedido (pedido_id, produto_id, quantidade, preco_unitario)
values
  (1, 1, 100, 4.00),
  (1, 4, 20, 8.00),
  (2, 2, 3, 6.80),
  (2, 5, 1, 4.00),
  (3, 3, 5, 3.20),
  (3, 7, 1, 3.80),
  (4, 6, 2, 9.90),
  (4, 8, 1, 7.50),
  (5, 9, 2, 30.00),
  (5, 10, 4, 5.50),
  (6, 11, 3, 2.50),
  (6, 12, 2, 7.20),
  (7, 13, 100, 12.00),
  (7, 14, 100, 12.00),
  (8, 15, 2, 15.00),
  (8, 1, 3, 4.50),
  (9, 2, 1, 6.80),
  (9, 3, 2, 3.20),
  (10, 4, 4, 8.50),
  (10, 5, 3, 4.00);
  
insert into
  pagamentos (pedido_id, valor, metodo_pagamento, data_pagamento)
values
  (1, 560.00, 'Cartão de Crédito', '2024-07-22'),
  (2, 40.00, 'Boleto', '2024-11-02'),
  (3, 20.00, 'Transferência Bancária', '2024-03-05'),
  (4, 35.00, 'Cartão de Crédito', null),
  (5, 30.00, 'Boleto', '2024-11-05'),
  (6, 45.00, 'Transferência Bancária', null),
  (7, 2400.00, 'Cartão de Crédito', '2024-11-05'),
  (8, 50.00, 'Boleto', '2024-10-08'),
  (9, 12.00, 'Transferência Bancária', '2024-09-05'),
  (10, 36.00, 'Cartão de Crédito', null);


-- Updates
create table if not exists produtos_preco_original (
  produto_id int,
  preco decimal(10,2),
  foreign key (produto_id) references produtos(produto_id)
);

insert into
  produtos_preco_original (produto_id, preco)
select
  produto_id, preco
from
  produtos
where 
  categoria_id = 5;
  
update
  produtos
set 
  preco = preco * 1.10
where 
  produtos.categoria_id = 5;


insert into
  produtos_preco_original (produto_id, preco)
select
  produto_id, preco
from
  produtos
where 
  estoque > 20
and
  produto_id not in (select produto_id from produtos_preco_original);

update
  produtos
set
  preco = preco * 0.95
where
  produtos.estoque > 20;
  
  
insert into
  produtos_preco_original (produto_id, preco)
select
  produto_id, preco
from
  produtos
where 
  fornecedor_id = 2
and
  produto_id not in (select produto_id from produtos_preco_original);

update
  produtos
set
  preco = preco * 0.85
where
  produtos.fornecedor_id = 2;


update
  clientes
set
  clientes.endereco = 'Rua Isadora Pinto, 230', 
  clientes.telefone = '41988997070'
where
  cliente_id = 5;
  
  
update
  funcionarios
set
  cargo = 'Gerente',
  salario = salario * 1.20
where
  funcionario_id = 3;
  
  
update
  pedidos
join
  pagamentos on pedidos.pedido_id = pagamentos.pedido_id
set 
  status = 'Concluído'
where
  pagamentos.data_pagamento is not null;

  
update
  produtos
join
  produtos_preco_original on produtos.produto_id = produtos_preco_original.produto_id
set
  produtos.preco = produtos_preco_original.preco;
  

update
  produtos
join
  itens_pedido on produtos.produto_id = itens_pedido.produto_id
set
  produtos.estoque = produtos.estoque - itens_pedido.quantidade;
  

  
-- Parte 3: Consultas SQL Avançadas

select 
  produtos.nome, categorias.nome, fornecedores.nome
from
  produtos
inner join
  categorias on categorias.categoria_id = produtos.categoria_id
inner join
  fornecedores on fornecedores.fornecedor_id = produtos.fornecedor_id
where
  produtos.estoque > 10;
  

select
  clientes.nome, pedidos.data_pedido, funcionarios.nome, pedidos.status
from
  pedidos
inner join
  clientes on clientes.cliente_id = pedidos.cliente_id
inner join
  funcionarios on funcionarios.funcionario_id = pedidos.funcionario_id
where
  clientes.cliente_id = 8 and
  pedidos.data_pedido >= curdate() - interval 30 day;


select 
  produtos.nome, sum(itens_pedido.quantidade)
from
  produtos
inner join
  itens_pedido on produtos.produto_id = itens_pedido.produto_id
group by
  produtos.nome
having
  sum(itens_pedido.quantidade) > 5;

  
select 
  pagamentos.pedido_id,
  sum(pagamentos.valor),
  group_concat(pagamentos.metodo_pagamento SEPARATOR ', ')
from 
  pagamentos
where 
  pagamentos.data_pagamento >= curdate() - interval 60 day
group by 
  pagamentos.pedido_id;

  
select 
  pedidos.pedido_id,
  pedidos.data_pedido,
  pedidos.status,
  sum(pagamentos.valor)
from
  pedidos
inner join 
  pagamentos on pedidos.pedido_id = pagamentos.pedido_id
where 
  pagamentos.data_pagamento is null
  or pedidos.status = 'Em andamento'
group by
  pedidos.pedido_id
having
  sum(pagamentos.valor) > 100;


select
  produtos.nome,
  produtos.estoque,
  produtos.preco,
  fornecedores.nome
from
  produtos
inner join
  fornecedores on produtos.fornecedor_id = fornecedores.fornecedor_id
where
  produtos.estoque < 5
order by
  produtos.nome;
     
 

select 
  clientes.nome,
  sum(pagamentos.valor)
from  
  clientes
inner join 
  pedidos on clientes.cliente_id = pedidos.cliente_id
inner join
  pagamentos on pedidos.pedido_id = pagamentos.pedido_id
group by
  clientes.nome
having
  sum(pagamentos.valor) > 500;


with total_vendas_por_funcionario as (
  select 
    funcionarios.nome as nome_funcionario,
    sum(itens_pedido.quantidade * itens_pedido.preco_unitario) as total_vendas
  from 
    funcionarios
  join 
    pedidos on funcionarios.funcionario_id = pedidos.funcionario_id
  join 
    itens_pedido on pedidos.pedido_id = itens_pedido.pedido_id
  group by
    funcionarios.nome
),
media_total_vendas as (
  select 
    avg(total_vendas) as media_vendas
  from 
    total_vendas_por_funcionario
)
select 
  tvpf.nome_funcionario,
  tvpf.total_vendas
from 
  total_vendas_por_funcionario tvpf
join 
  media_total_vendas mtv on tvpf.total_vendas > mtv.media_vendas;


select 
  date_format(pedidos.data_pedido, '%Y-%m') as mes,
  sum(itens_pedido.quantidade * itens_pedido.preco_unitario) as valor_total
from 
  pedidos
join 
  itens_pedido on pedidos.pedido_id = itens_pedido.pedido_id
group by
  date_format(pedidos.data_pedido, '%Y-%m')
having
  valor_total > 1000;


select 
  produtos.nome,
  categorias.nome
from 
  produtos
inner join
  categorias on produtos.categoria_id = categorias.categoria_id
left join
  itens_pedido on produtos.produto_id = itens_pedido.produto_id and itens_pedido.pedido_id IN (
    select pedido_id 
    from pedidos 
    where data_pedido >= curdate() - interval 90 day
  )
where 
  itens_pedido.produto_id is null;


select 
  cargo,
  count(*) AS quantidade_funcionarios
from 
  funcionarios
group by 
  cargo
having
  count(*) > 2;


with pedidos_por_cliente as (
  select 
    cliente_id,
    count(*) as total_pedidos
  from 
    pedidos
  group by 
    cliente_id
  having 
    count(*) > 3
),
pedidos_detalhados as (
  select 
    p.cliente_id,
    p.funcionario_id,
    count(*) as pedidos_por_funcionario
  from 
    pedidos p
  group by 
    p.cliente_id, p.funcionario_id
)
select 
  c.nome as nome_cliente,
  f.nome as nome_funcionario,
  pd.pedidos_por_funcionario,
  ppc.total_pedidos
from 
  pedidos_detalhados pd
inner join 
  pedidos_por_cliente ppc on pd.cliente_id = ppc.cliente_id
inner join 
  clientes c on pd.cliente_id = c.cliente_id
inner join
  funcionarios f on pd.funcionario_id = f.funcionario_id;


select 
  clientes.nome as nome_cliente,
  produtos.nome as nome_produto,
  itens_pedido.quantidade,
  itens_pedido.preco_unitario,
  pedidos.data_pedido
from 
  clientes
inner join
  pedidos on clientes.cliente_id = pedidos.cliente_id
inner join
  itens_pedido on pedidos.pedido_id = itens_pedido.pedido_id
inner join 
  produtos on itens_pedido.produto_id = produtos.produto_id
where 
  clientes.cliente_id = 5
  and pedidos.data_pedido >= curdate() - interval 1 year
order by
  pedidos.data_pedido;


select 
  produtos.nome,
  sum(itens_pedido.preco_unitario * itens_pedido.quantidade) AS receita_total
from
  itens_pedido
inner join 
  produtos on itens_pedido.produto_id = produtos.produto_id
group by 
  produtos.nome
order by
  receita_total desc
limit 1;



-- Parte 4: Alterações e Manutenções no Banco de Dados

alter table
  produtos
add
  desconto decimal(10,2);
  
  
alter table
  funcionarios
add
  cpf int;
