create table if not exists produtos (
  id int auto_increment primary key,
  nome varchar(100) not null,
  preco decimal(10,2) not null
);

insert into
  produtos (nome, preco)
values
  ('bitoneira', 10),
  ('pao', 500),
  ('alicate', 1.5),
  ('rtx', 2000);



select * from produtos;

select *
from produtos
where preco > 100;

select *
from produtos
order by preco;

select *
from produtos
limit 3;



create table if not exists novos_produtos (
  id int auto_increment primary key,
  nome varchar(100) not null,
  preco decimal(10,2) not null
);



insert into novos_produtos (nome, preco)
select nome, preco from produtos
where preco > 50;

select * from novos_produtos;

select count(*) from produtos;

select avg(preco) from produtos;

select nome, preco
from produtos
where preco = (select max(preco) from produtos);

select nome, preco
from produtos
where preco = (select min(preco) from produtos);
