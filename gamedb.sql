DROP DATABASE IF EXISTS gamedb;
CREATE DATABASE gamedb;

USE gamedb;

CREATE TABLE players (
	id INT NOT NULL,
	user VARCHAR(20) NOT NULL,
	password VARCHAR(20) NOT NULL,
	email VARCHAR(40) NOT NULL,
	PRIMARY KEY (id)
)ENGINE=InnoDB;

INSERT INTO players VALUES (0, 'Javier', 'admin', 'javier@hotmail.com');
INSERT INTO players VALUES (1, 'Pedro', '1234', 'pedro@hotmail.com');
INSERT INTO players VALUES (2, 'Andrea', '56789', 'andrea@hotmail.com');

CREATE TABLE games (
	id INT NOT NULL,
	end VARCHAR(20),
	duration INT(20),
	winner VARCHAR(20),
	PRIMARY KEY (id)
)ENGINE=InnoDB;

INSERT INTO games VALUES (0, '18/02/2020 19:30', '50', 'Javier');
INSERT INTO games VALUES (1, '20/02/2020 21:30', '60', 'Pedro');
INSERT INTO games VALUES (2, '22/02/2020 23:30', '70', 'Andrea');

CREATE TABLE gamerecord (
	id INT NOT NULL,
	p_id INT,
	g_id INT,
	FOREIGN KEY (p_id) REFERENCES players(id),
	FOREIGN KEY (g_id) REFERENCES games(id)
)ENGINE=InnoDB;



