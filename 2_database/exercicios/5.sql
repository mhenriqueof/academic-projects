-- 1

create table if not exists clientes (
  id_cliente int auto_increment primary key,
  nome varchar(50),
  email varchar(50)
);

insert into
  clientes (nome, email)
values
  ('Maria Silva', 'maria@email.com'),
  ('João Souza', 'joao@email.com'),
  ('Ana Costa', 'ana@email.com'),
  ('Pedro Lima', 'pedro@email.com');
  
create table if not exists pedidos (
  id_pedido int,
  id_cliente int,
  data_pedido date,
  valor_total decimal(10,2),
  foreign key (id_cliente) references clientes(id_cliente)
);

insert into
  pedidos (id_pedido, id_cliente, data_pedido, valor_total)
values
  (101, 1, '2023-01-15', 500.00),
  (102, 2, '2023-02-20', 300.00),
  (103, 1, '2023-03-05', 200.00),
  (104, 4, '2023-03-15', 400.00);

select
  clientes.nome, pedidos.valor_total
from
  clientes
inner join
  pedidos on clientes.id_cliente = pedidos.id_cliente;



-- 2

create table if not exists produtos (
	id_produto int,
    nome_produto varchar(50),
    preco decimal(10,2)
);

create table if not exists categorias (
	id_categoria int auto_increment primary key,
    nome_categoria varchar(50)
);

create table if not exists produto_categoria(
	id_produto int,
    id_categoria int,
    foreign key (id_categoria) references categorias(id_categoria)
);

insert into
	produtos (id_produto, nome_produto, preco)
values
	(201, 'Notebook', 3000),
  (202, 'Teclado', 150),
  (203, 'Impressora', 500),
  (204, 'Monitor', 800);
	
insert into
	categorias (nome_categoria)
values
	('Eletrônicos'), ('Acessórios');

insert into
	produto_categoria (id_produto, id_categoria)
values
	(201, 1),
  (202, 2),
  (203, 1),
  (204, 1);
  
select
  produtos.nome_produto, categorias.nome_categoria
from
  produtos
inner join
  produto_categoria on produtos.id_produto = produto_categoria.id_produto
inner join
  categorias on produto_categoria.id_categoria = categorias.id_categoria;



-- 3

create table if not exists funcionarios (
  id_funcionario int auto_increment primary key,
  nome_funcionario varchar(50),
  id_departamento int
);

insert into
  funcionarios (nome_funcionario, id_departamento)
values
  ('João', 1),
  ('Maria', 2),
  ('Carlos', 1);

create table if not exists departamento (
  id_departamento int auto_increment primary key,
  nome_departamento varchar(50)
);

insert into
  departamento (nome_departamento)
values
  ('Recursos Humanos'),
  ('TI'),
  ('Vendas');
  
select * from departamento;


select
  funcionarios.nome_funcionario, departamento.nome_departamento
from
  funcionarios
inner join
  departamento on funcionarios.id_departamento = departamento.id_departamento;



-- 4

create table if not exists alunos (
  id_aluno int auto_increment primary key,
  nome_aluno varchar(50)
);

insert into
  alunos (nome_aluno)
values
  ('Lucas'), ('Ana'), ('Pedro');
  
create table if not exists cursos (
  id_curso int auto_increment primary key,
  nome_curso varchar(50)
);

insert into
  cursos (nome_curso)
values
  ('Matemática'), ('Física'), ('Química');

create table if not exists matriculas (
  id_aluno int,
  id_curso int,
  foreign key (id_aluno) references alunos(id_aluno),
  foreign key (id_curso) references cursos(id_curso)
);

insert into
  matriculas (id_aluno, id_curso)
values
  (1,1),
  (2,2),
  (3,1);
  
select
  alunos.nome_aluno, cursos.nome_curso
from
  alunos
inner join
  matriculas on alunos.id_aluno = matriculas.id_aluno
inner join
  cursos on matriculas.id_curso = cursos.id_curso;
  