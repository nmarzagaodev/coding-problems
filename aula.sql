-- CREATE STUFF
create database aula;
use aula;

create table clientes (
	id_cliente int auto_increment primary key,
    nome_cliente varchar(255)
);

insert into clientes (nome_cliente) values ('joão'), ('julia'), ('flavio'), ('sérgio'), ('aníbal'), ('doris');

-- PROCEDURE WITH CURSOR

delimiter //
create procedure ExibirNomesClientes()
begin
	declare fim int default false; -- variavel para sinalizar o termino do cursor
    declare cliente_nome varchar(255); -- variavel para armazenar o nome do cliente
    -- declaração do cursor para selecionar todos os nomes de clientes
    declare cursor_clientes cursor for
    select nome_cliente from clientes;
    -- manipulador para percorrer o cursor
    declare continue handler for not found set fim = true;
	
    open cursor_clientes;
    
    read_loop: LOOP
		fetch cursor_clientes into cliente_nome;
		
		if fim then
			leave read_loop;
		end if;
		
		select cliente_nome as 'Nome do Cliente';
	end loop;
    
	close cursor_clientes;
    
end//
delimiter ;
    
call ExibirNomesClientes();
