--
-- PostgreSQL database dump
--

-- Dumped from database version 9.5.10
-- Dumped by pg_dump version 9.5.10

-- Started on 2017-12-16 16:22:30 -03

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 1 (class 3079 OID 12435)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner:
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2209 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner:
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 181 (class 1259 OID 28525)
-- Name: camino; Type: TABLE; Schema: public; Owner: fmedel
--

CREATE TABLE camino (
    id_camino bigint NOT NULL,
    inicio_fila integer NOT NULL,
    fin_fila integer NOT NULL,
    inicio_columna integer NOT NULL,
    fin_columna integer NOT NULL,
    solucion boolean DEFAULT false,
    camino text,
    seccion_fila integer,
    seccion_columna integer,
    columna_fila integer
);


ALTER TABLE camino OWNER TO fmedel;

--
-- TOC entry 182 (class 1259 OID 28532)
-- Name: camino_id_camino_seq; Type: SEQUENCE; Schema: public; Owner: fmedel
--

CREATE SEQUENCE camino_id_camino_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE camino_id_camino_seq OWNER TO fmedel;

--
-- TOC entry 2210 (class 0 OID 0)
-- Dependencies: 182
-- Name: camino_id_camino_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: fmedel
--

ALTER SEQUENCE camino_id_camino_seq OWNED BY camino.id_camino;


--
-- TOC entry 183 (class 1259 OID 28534)
-- Name: laberinto; Type: TABLE; Schema: public; Owner: fmedel
--

CREATE TABLE laberinto (
    id_laberinto bigint NOT NULL,
    fila integer NOT NULL,
    columna integer NOT NULL,
    valor boolean DEFAULT false,
    seccion_fila integer NOT NULL,
    seccion_columna integer NOT NULL
);


ALTER TABLE laberinto OWNER TO fmedel;

--
-- TOC entry 184 (class 1259 OID 28538)
-- Name: laberinto_id_laberinto_seq; Type: SEQUENCE; Schema: public; Owner: fmedel
--

CREATE SEQUENCE laberinto_id_laberinto_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE laberinto_id_laberinto_seq OWNER TO fmedel;

--
-- TOC entry 2211 (class 0 OID 0)
-- Dependencies: 184
-- Name: laberinto_id_laberinto_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: fmedel
--

ALTER SEQUENCE laberinto_id_laberinto_seq OWNED BY laberinto.id_laberinto;


--
-- TOC entry 186 (class 1259 OID 38380)
-- Name: user; Type: TABLE; Schema: public; Owner: fmedel
--

CREATE TABLE "user" (
    id_user bigint NOT NULL,
    user_t text,
    password_t text
);


ALTER TABLE "user" OWNER TO fmedel;

--
-- TOC entry 185 (class 1259 OID 38378)
-- Name: user_id_user_seq; Type: SEQUENCE; Schema: public; Owner: fmedel
--

CREATE SEQUENCE user_id_user_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE user_id_user_seq OWNER TO fmedel;

--
-- TOC entry 2212 (class 0 OID 0)
-- Dependencies: 185
-- Name: user_id_user_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: fmedel
--

ALTER SEQUENCE user_id_user_seq OWNED BY "user".id_user;


--
-- TOC entry 2074 (class 2604 OID 32957)
-- Name: id_camino; Type: DEFAULT; Schema: public; Owner: fmedel
--

ALTER TABLE ONLY camino ALTER COLUMN id_camino SET DEFAULT nextval('camino_id_camino_seq'::regclass);


--
-- TOC entry 2076 (class 2604 OID 28541)
-- Name: id_laberinto; Type: DEFAULT; Schema: public; Owner: fmedel
--

ALTER TABLE ONLY laberinto ALTER COLUMN id_laberinto SET DEFAULT nextval('laberinto_id_laberinto_seq'::regclass);


--
-- TOC entry 2077 (class 2604 OID 38383)
-- Name: id_user; Type: DEFAULT; Schema: public; Owner: fmedel
--

ALTER TABLE ONLY "user" ALTER COLUMN id_user SET DEFAULT nextval('user_id_user_seq'::regclass);


--
-- TOC entry 2196 (class 0 OID 28525)
-- Dependencies: 181
-- Data for Name: camino; Type: TABLE DATA; Schema: public; Owner: fmedel
--

COPY camino (id_camino, inicio_fila, fin_fila, inicio_columna, fin_columna, solucion, camino, seccion_fila, seccion_columna, columna_fila) FROM stdin;
\.


--
-- TOC entry 2213 (class 0 OID 0)
-- Dependencies: 182
-- Name: camino_id_camino_seq; Type: SEQUENCE SET; Schema: public; Owner: fmedel
--

SELECT pg_catalog.setval('camino_id_camino_seq', 1, true);


--
-- TOC entry 2198 (class 0 OID 28534)
-- Dependencies: 183
-- Data for Name: laberinto; Type: TABLE DATA; Schema: public; Owner: fmedel
--

COPY laberinto (id_laberinto, fila, columna, valor, seccion_fila, seccion_columna) FROM stdin;
\.


--
-- TOC entry 2214 (class 0 OID 0)
-- Dependencies: 184
-- Name: laberinto_id_laberinto_seq; Type: SEQUENCE SET; Schema: public; Owner: fmedel
--

SELECT pg_catalog.setval('laberinto_id_laberinto_seq', 1, true);


--
-- TOC entry 2201 (class 0 OID 38380)
-- Dependencies: 186
-- Data for Name: user; Type: TABLE DATA; Schema: public; Owner: fmedel
--

COPY "user" (id_user, user_t, password_t) FROM stdin;
1	valor3	26729bae1fc5b60a2973324ef387fe5f
2	4d186321c1a7f0f354b297e8914ab240	26729bae1fc5b60a2973324ef387fe5f
\.


--
-- TOC entry 2215 (class 0 OID 0)
-- Dependencies: 185
-- Name: user_id_user_seq; Type: SEQUENCE SET; Schema: public; Owner: fmedel
--

SELECT pg_catalog.setval('user_id_user_seq', 1, false);


--
-- TOC entry 2079 (class 2606 OID 29691)
-- Name: camino_pkey; Type: CONSTRAINT; Schema: public; Owner: fmedel
--

ALTER TABLE ONLY camino
    ADD CONSTRAINT camino_pkey PRIMARY KEY (id_camino);


--
-- TOC entry 2081 (class 2606 OID 29693)
-- Name: laberinto_pkey; Type: CONSTRAINT; Schema: public; Owner: fmedel
--

ALTER TABLE ONLY laberinto
    ADD CONSTRAINT laberinto_pkey PRIMARY KEY (id_laberinto);


--
-- TOC entry 2208 (class 0 OID 0)
-- Dependencies: 7
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2017-12-16 16:22:30 -03

--
-- PostgreSQL database dump complete
--
