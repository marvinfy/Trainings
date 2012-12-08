Create table contatos (
	con_id Number(24) NOT NULL ,
	name Varchar2(40) NOT NULL  UNIQUE ,
 Constraint pk_contatos primary key (con_id) 
) 
;

Create table cidades (
	cid_id Number(24) NOT NULL ,
	name Varchar2(40) NOT NULL ,
 Constraint pk_cidades primary key (cid_id) 
) 
;

Create table mov_tipo (
	mt_id Number(24) NOT NULL ,
	name Varchar2(40) NOT NULL  UNIQUE ,
 Constraint pk_mov_tipo primary key (mt_id) 
) 
;

Create table clientes (
	cli_id Number(24) NOT NULL ,
	name Varchar2(40) NOT NULL ,
	cidade_id Number(24) NOT NULL ,
	contato_id Number(24) NOT NULL ,
 Constraint pk_clientes primary key (cli_id) 
) 
;

Create table movimento (
	mov_id Number(24) NOT NULL ,
	cliente_id Number(24) NOT NULL ,
	tipo_id Number(24) NOT NULL ,
	mov_date Date NOT NULL ,
	description Varchar2(40) NOT NULL ,
 Constraint pk_movimento primary key (mov_id) 
) 
;



Create Index IX_Relation_cli_mov ON movimento (cliente_id)
;
Alter table movimento add Constraint Relation_cli_mov foreign key (cliente_id) references clientes (cli_id) 
;
Create Index IX_Relation_con_cli ON clientes (cli_id)
;
Alter table clientes add Constraint Relation_con_cli foreign key (contato_id) references contatos (con_id) 
;
Create Index IX_Relation_cid_cli ON clientes (cidade_id)
;
Alter table clientes add Constraint Relation_cid_cli foreign key (cidade_id) references cidades (cid_id) 
;
Create Index IX_Relation_movtipo_mov ON movimento (tipo_id)
;
Alter table movimento add Constraint Relation_movtipo_mov foreign key (tipo_id) references mov_tipo (mt_id) 
;

-- Create Object Tables section

CREATE SEQUENCE clientes_cli_id_seq 
increment by 1
start with 1
nocycle
nocache;
   

CREATE SEQUENCE movimento_mov_id_seq 
increment by 1
start with 1
nocycle
nocache;
   

CREATE SEQUENCE contatos_con_id_seq 
increment by 1
start with 1
nocycle
nocache;
   

CREATE SEQUENCE cidades_cid_id_seq 
increment by 1
start with 1
nocycle
nocache;
   

CREATE SEQUENCE mov_tipo_mt_id_seq 
increment by 1
start with 1
nocycle
nocache;
   

CREATE OR REPLACE TRIGGER inc_clientes_trig BEFORE INSERT ON clientes
FOR EACH ROW
BEGIN
SELECT clientes_cli_id_seq.NEXTVAL into :new.cli_id FROM dual;
END;
CREATE OR REPLACE TRIGGER inc_movimento_trig BEFORE INSERT ON movimento
FOR EACH ROW
BEGIN
SELECT movimento_mov_id_seq.NEXTVAL into :new.mov_id FROM dual;
END;
CREATE OR REPLACE TRIGGER inc_contatos_trig BEFORE INSERT ON contatos
FOR EACH ROW
BEGIN
SELECT contatos_con_id_seq.NEXTVAL into :new.con_id FROM dual;
END;
CREATE OR REPLACE TRIGGER inc_cidades_trig BEFORE INSERT ON cidades
FOR EACH ROW
BEGIN
SELECT cidades_cid_id_seq.NEXTVAL into :new.cid_id FROM dual;
END;
CREATE OR REPLACE TRIGGER inc_movtipo_trig BEFORE INSERT ON mov_tipo
FOR EACH ROW
BEGIN
SELECT mov_tipo_mt_id_seq.NEXTVAL into :new.mt_id FROM dual;
END;

