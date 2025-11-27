create schema Cidade_Educacao;

create table Cidade_Educacao.instituicao (
	cod_instituicao int primary key,
	nome varchar(30) NOT NULL,
	email varchar(30),
	numero int, 
	cep int NOT NULL,
	bairro varchar(50),
	cidade varchar(30),
	estado varchar(30)
);

create table Cidade_Educacao.curso (
	cod_curso int primary key, 
	carga_horaria FLOAT, 
	nome varchar(30) NOT NULL
);

create table Cidade_Educacao.disciplina (
	cod_disciplina int primary key, 
	nome varchar(30) NOT NULL
);

create table Cidade_Educacao.turma (
	cod_turma int primary key, 
	capacidade int NOT NULL, 
	nome varchar(30) NOT NULL, 
	data date, 
	horário int
);

create table Cidade_Educacao.tipo (
	cod_tipo int primary key, 
	nome varchar(30) NOT NULL
);

create table Cidade_Educacao.sala (
	cod_sala int primary key, 
	cod_tipo int references Cidade_Educacao.tipo(cod_tipo), 
	localizacao varchar(50), 
	capacidade int NOT NULL, 
	tamanho int NOT NULL, 
	nome varchar(30) NOT NULL
);

create table Cidade_Educacao.cargo (
	cod_cargo int primary key, 
	nome varchar(30) NOT NULL, 
	salario FLOAT
);

create table Cidade_Educacao.pessoa (
	cod_pessoa int primary key, 
	cod_instituicao int references Cidade_Educacao.instituicao(cod_instituicao), 
	nome varchar(30) NOT NULL,
	data_nascimento date NOT NULL,
	CPF int NOT NULL,
	email varchar(30),
	numero int NOT NULL, 
	cep int NOT NULL,
	bairro varchar(50),
	cidade varchar(30),
	estado varchar(30)
);

create table Cidade_Educacao.professor (
	cod_pessoa int references Cidade_Educacao.pessoa(cod_pessoa), 
	departamento varchar(50) NOT NULL, 
	titulação varchar(50) NOT NULL
);

create table Cidade_Educacao.funcionario (
	cod_pessoa int references Cidade_Educacao.pessoa(cod_pessoa), 
	cod_cargo int references Cidade_Educacao.cargo(cod_cargo)
);

create table Cidade_Educacao.aluno (
	cod_pessoa int references Cidade_Educacao.pessoa(cod_pessoa), 
	cod_turma int references Cidade_Educacao.turma(cod_turma)
);

create table Cidade_Educacao.historico_escolar (
	cod_pessoa int references Cidade_Educacao.pessoa(cod_pessoa), 
	ano_semestre varchar(10),
	nota FLOAT,
	frequencia FLOAT,
	situacao varchar(20)	
);

create table Cidade_Educacao.telefone (
	cod_pessoa int references Cidade_Educacao.pessoa(cod_pessoa), 
	DDD int NOT NULL,
	numero int NOT NULL
);

create table Cidade_Educacao.int_cur (
	cod_curso int references Cidade_Educacao.curso(cod_curso), 
	cod_instituicao int references Cidade_Educacao.instituicao(cod_instituicao)
);

create table Cidade_Educacao.dis_cur (
	cod_curso int references Cidade_Educacao.curso(cod_curso), 
	cod_disciplina int references Cidade_Educacao.disciplina(cod_disciplina)
);

create table Cidade_Educacao.dis_sal (
	cod_sala int references Cidade_Educacao.sala(cod_sala), 
	cod_disciplina int references Cidade_Educacao.disciplina(cod_disciplina)
);

create table Cidade_Educacao.dis_tur (
	cod_turma int references Cidade_Educacao.turma(cod_turma), 
	cod_disciplina int references Cidade_Educacao.disciplina(cod_disciplina)
);

create table Cidade_Educacao.sal_tur (
	cod_turma int references Cidade_Educacao.turma(cod_turma), 
	cod_sala int references Cidade_Educacao.sala(cod_sala)
);

create table Cidade_Educacao.tur_prof  (
	cod_turma int references Cidade_Educacao.turma(cod_turma), 
	cod_pessoa int references Cidade_Educacao.pessoa(cod_pessoa)
);

insert into Cidade_Educacao.instituicao(cod_instituicao, nome, email, numero, cep, bairro, cidade, estado)
values(20, 'Universidade Five', 'UniversidadeFive@gmail.com', 57363478, 85739586, 'Farias', 'São Paulo', 'São Paulo');

insert into Cidade_Educacao.pessoa(cod_pessoa, cod_instituicao, nome, data_nascimento, CPF, email, numero, cep, bairro, cidade, estado)
values(10, 20, 'Clara', '2005-08-11', 76654819, 'ClarinhaSilva@gmail.com', 55119456, 85798451, 'Lima', 'Cachinhos', 'São Paulo');

insert into Cidade_Educacao.pessoa(cod_pessoa, cod_instituicao, nome, data_nascimento, CPF, email, numero, cep, bairro, cidade, estado)
values(11, 20, 'Marcos', '2003-09-12', 76654876, 'Marquinhos12@gmail.com', 55118732, 85799643, 'Lima', 'Cachinhos', 'São Paulo');

insert into Cidade_Educacao.pessoa(cod_pessoa, cod_instituicao, nome, data_nascimento, CPF, email, numero, cep, bairro, cidade, estado)
values(12, 20, 'Maria', '1975-11-24', 76656543, 'DonaMariaSouza@gmail.com', 55116123, 85790912, 'Minas', 'Lima', 'São Paulo');

insert into Cidade_Educacao.pessoa(cod_pessoa, cod_instituicao, nome, data_nascimento, CPF, email, numero, cep, bairro, cidade, estado)
values(13, 20, 'Mario', '1982-05-05', 76651390, 'Mario512@gmail.com', 55110712, 85797124, 'Inca', 'Lima', 'São Paulo');

insert into Cidade_Educacao.pessoa(cod_pessoa, cod_instituicao, nome, data_nascimento, CPF, email, numero, cep, bairro, cidade, estado)
values(14, 20, 'Amanda', '1993-12-28', 76658103, 'Amandinhaaa@gmail.com', 55111643, 85790916, 'Laranja', 'Laranjeiras', 'São Paulo');

insert into Cidade_Educacao.pessoa(cod_pessoa, cod_instituicao, nome, data_nascimento, CPF, email, numero, cep, bairro, cidade, estado)
values(15, 20, 'Tulio', '1989-02-11', 76656432, 'TulioSilveira654@gmail.com', 55110845, 85790712, 'Limoeiro', 'Cachinhos', 'São Paulo');

insert into Cidade_Educacao.curso(cod_curso, carga_horaria, nome)
values(21, 7200, 'Medicina');

insert into Cidade_Educacao.curso(cod_curso, carga_horaria, nome)
values(22, 2000, 'ADS');

insert into Cidade_Educacao.disciplina(cod_disciplina, nome)
values(23, 'Anatomia');

insert into Cidade_Educacao.disciplina(cod_disciplina, nome)
values(24, 'Modelagem de Banco de Dados');

insert into Cidade_Educacao.turma(cod_turma, capacidade, nome, data, horário)
values(25, 40, 'MED-1', '2025-09-12', 830 );

insert into Cidade_Educacao.turma(cod_turma, capacidade, nome, data, horário)
values(26, 40, 'ADS-2', '2025-09-13', 830);

insert into Cidade_Educacao.tipo(cod_tipo, nome)
values(27, 'Laboratório de Saúde');

insert into Cidade_Educacao.tipo(cod_tipo, nome)
values(28, 'Laboratório de Informática');

insert into Cidade_Educacao.sala(cod_sala, cod_tipo, localizacao, capacidade, tamanho, nome)
values(29, 27, 'Setor Sul', 40, 60, 'LAB-1');

insert into Cidade_Educacao.sala(cod_sala, cod_tipo, localizacao, capacidade, tamanho, nome)
values(30, 28, 'Setor Norte', 40, 60, 'LAB-2');

insert into Cidade_Educacao.cargo(cod_cargo, nome, salario)
values(31, 'Secretario', 3600);

insert into Cidade_Educacao.cargo(cod_cargo, nome, salario)
values(32, 'Segurança', 2166);

insert into Cidade_Educacao.professor(cod_pessoa, departamento, titulação)
values(12, 'T.I', 'Ciência da Computação');

insert into Cidade_Educacao.professor(cod_pessoa, departamento, titulação)
values(13, 'Saúde', 'Medicina');

insert into Cidade_Educacao.funcionario(cod_pessoa, cod_cargo)
values(14, 31);

insert into Cidade_Educacao.funcionario(cod_pessoa, cod_cargo)
values(15, 32);

insert into Cidade_Educacao.aluno(cod_pessoa, cod_turma)
values(10, 25);

insert into Cidade_Educacao.aluno(cod_pessoa, cod_turma)
values(11, 26);

insert into Cidade_Educacao.historico_escolar(cod_pessoa, ano_semestre, nota, frequencia, situacao)
values(10, '2025-1', 5, 60.50, 'Em Curso');

insert into Cidade_Educacao.historico_escolar(cod_pessoa, ano_semestre, nota, frequencia, situacao)
values(11, '2025-1', 7, 75.12, 'Em Curso');

insert into Cidade_Educacao.telefone(cod_pessoa, DDD, numero)
values(10, 11, 55119456);

insert into Cidade_Educacao.telefone(cod_pessoa, DDD, numero)
values(11, 11, 55118732);

insert into Cidade_Educacao.telefone(cod_pessoa, DDD, numero)
values(12, 11, 55116123);

insert into Cidade_Educacao.telefone(cod_pessoa, DDD, numero)
values(13, 11, 55110712);

insert into Cidade_Educacao.telefone(cod_pessoa, DDD, numero)
values(14, 11, 55111643);

insert into Cidade_Educacao.telefone(cod_pessoa, DDD, numero)
values(15, 11, 55110845);

insert into Cidade_Educacao.int_cur(cod_curso, cod_instituicao)
values(21, 20);

insert into Cidade_Educacao.int_cur(cod_curso, cod_instituicao)
values(22, 20);

insert into Cidade_Educacao.dis_cur(cod_disciplina, cod_curso)
values(23, 21);

insert into Cidade_Educacao.dis_cur(cod_disciplina, cod_curso)
values(24, 22);

insert into Cidade_Educacao.dis_sal(cod_disciplina, cod_sala)
values(24, 30);

insert into Cidade_Educacao.dis_sal(cod_disciplina, cod_sala)
values(23, 29);

insert into Cidade_Educacao.dis_tur(cod_disciplina, cod_turma)
values(23, 25);

insert into Cidade_Educacao.dis_tur(cod_disciplina, cod_turma)
values(24, 26);

insert into Cidade_Educacao.sal_tur(cod_sala, cod_turma)
values(30, 26);

insert into Cidade_Educacao.sal_tur(cod_sala, cod_turma)
values(29, 25);

insert into Cidade_Educacao.tur_prof(cod_pessoa, cod_turma)
values(13, 25);

insert into Cidade_Educacao.tur_prof(cod_pessoa, cod_turma)
values(12, 26);

update Cidade_Educacao.sala
set cod_sala=29
where cod_sala=28 and cod_tipo=27

update Cidade_Educacao.turma
set nome= 'MED-1'
where nome='Laborátorio de Anatomia' and data= '2025-09-12'
