--
-- PostgreSQL database dump
--

-- Dumped from database version 10.13
-- Dumped by pg_dump version 10.13

-- Started on 2020-08-05 18:09:43

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 1 (class 3079 OID 12924)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 3059 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


--
-- TOC entry 246 (class 1255 OID 17388)
-- Name: GuncelleKullanici(integer, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."GuncelleKullanici"(_id integer, _kullanici_ad text, _parola text) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Update kullanici Set kullanici_ad=_kullanici_ad,parola=_parola Where kullanici_id=_id;
End$$;


ALTER FUNCTION public."GuncelleKullanici"(_id integer, _kullanici_ad text, _parola text) OWNER TO postgres;

--
-- TOC entry 241 (class 1255 OID 17383)
-- Name: KullaniciSil(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."KullaniciSil"(kid integer) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Delete From kullanici Where kullanici_id=kid;
End$$;


ALTER FUNCTION public."KullaniciSil"(kid integer) OWNER TO postgres;

--
-- TOC entry 240 (class 1255 OID 17382)
-- Name: OgrenciSil(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."OgrenciSil"(oid integer) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Delete From ogrenci Where ogrenci_id=oid;
End$$;


ALTER FUNCTION public."OgrenciSil"(oid integer) OWNER TO postgres;

--
-- TOC entry 242 (class 1255 OID 17384)
-- Name: OgretmenSil(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."OgretmenSil"(oid integer) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Delete From ogretmen Where ogretmen_id=oid;
End$$;


ALTER FUNCTION public."OgretmenSil"(oid integer) OWNER TO postgres;

--
-- TOC entry 245 (class 1255 OID 17387)
-- Name: PersonelSil(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."PersonelSil"(_id integer) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Delete From personel Where personel_id=_id;
End$$;


ALTER FUNCTION public."PersonelSil"(_id integer) OWNER TO postgres;

--
-- TOC entry 244 (class 1255 OID 17386)
-- Name: VeliSil(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."VeliSil"(_id integer) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Delete From veli Where veli_id=_id;
End$$;


ALTER FUNCTION public."VeliSil"(_id integer) OWNER TO postgres;

--
-- TOC entry 243 (class 1255 OID 17385)
-- Name: YonetimSil(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."YonetimSil"(_id integer) RETURNS void
    LANGUAGE plpgsql
    AS $$
Begin
Delete From yonetim Where yonetim_id=_id;
End$$;


ALTER FUNCTION public."YonetimSil"(_id integer) OWNER TO postgres;

--
-- TOC entry 239 (class 1255 OID 17463)
-- Name: kayit_egitmen_bolum_degistirme(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayit_egitmen_bolum_degistirme() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	IF NEW.bolum_id <> OLD.bolum_id THEN
		 INSERT INTO kayit_ogretmen (ogretmen_id,bolum_id,tarih)
		 VALUES(OLD.ogretmen_id,OLD.bolum_id,now());
	END IF;

	RETURN NEW;
END;
$$;


ALTER FUNCTION public.kayit_egitmen_bolum_degistirme() OWNER TO postgres;

--
-- TOC entry 259 (class 1255 OID 17402)
-- Name: kayit_kullanici_parola_degistirme(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayit_kullanici_parola_degistirme() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	IF NEW.parola <> OLD.parola THEN
		 INSERT INTO kayit_kullanici (kullanici_id,parola,tarih)
		 VALUES(OLD.kullanici_id,OLD.parola,now());
	END IF;

	RETURN NEW;
END;
$$;


ALTER FUNCTION public.kayit_kullanici_parola_degistirme() OWNER TO postgres;

--
-- TOC entry 260 (class 1255 OID 17430)
-- Name: kayit_ogrenci_bolum_degistirme(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayit_ogrenci_bolum_degistirme() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	IF NEW.bolum_id <> OLD.bolum_id THEN
		 INSERT INTO kayit_ogrenci (ogrenci_id,bolum_id,tarih)
		 VALUES(OLD.ogrenci_id,OLD.bolum_id,now());
	END IF;

	RETURN NEW;
END;
$$;


ALTER FUNCTION public.kayit_ogrenci_bolum_degistirme() OWNER TO postgres;

--
-- TOC entry 238 (class 1255 OID 17452)
-- Name: kayit_personel_alan_degistirme(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayit_personel_alan_degistirme() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	IF NEW.personel_alan_id <> OLD.personel_alan_id THEN
		 INSERT INTO kayit_personel (personel_id,personel_alan_id,tarih)
		 VALUES(OLD.personel_id,OLD.personel_alan_id,now());
	END IF;

	RETURN NEW;
END;
$$;


ALTER FUNCTION public.kayit_personel_alan_degistirme() OWNER TO postgres;

--
-- TOC entry 237 (class 1255 OID 17440)
-- Name: kayit_yonetim_tur_degistirme(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayit_yonetim_tur_degistirme() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	IF NEW.yonetim_tur_id <> OLD.yonetim_tur_id THEN
		 INSERT INTO kayit_yonetim (yonetim_id,yonetim_tur_id,tarih)
		 VALUES(OLD.yonetim_id,OLD.yonetim_tur_id,now());
	END IF;

	RETURN NEW;
END;
$$;


ALTER FUNCTION public.kayit_yonetim_tur_degistirme() OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 213 (class 1259 OID 17093)
-- Name: aile_birligi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.aile_birligi (
    aile_birligi_id integer NOT NULL,
    veli_id integer
);


ALTER TABLE public.aile_birligi OWNER TO postgres;

--
-- TOC entry 212 (class 1259 OID 17091)
-- Name: aile_birligi_aile_birligi_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.aile_birligi_aile_birligi_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.aile_birligi_aile_birligi_id_seq OWNER TO postgres;

--
-- TOC entry 3060 (class 0 OID 0)
-- Dependencies: 212
-- Name: aile_birligi_aile_birligi_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.aile_birligi_aile_birligi_id_seq OWNED BY public.aile_birligi.aile_birligi_id;


--
-- TOC entry 203 (class 1259 OID 16874)
-- Name: bolum; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.bolum (
    bolum_id integer NOT NULL,
    ad text
);


ALTER TABLE public.bolum OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 16872)
-- Name: bolum_bolum_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.bolum_bolum_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.bolum_bolum_id_seq OWNER TO postgres;

--
-- TOC entry 3061 (class 0 OID 0)
-- Dependencies: 202
-- Name: bolum_bolum_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.bolum_bolum_id_seq OWNED BY public.bolum.bolum_id;


--
-- TOC entry 215 (class 1259 OID 17171)
-- Name: ders; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ders (
    ders_id integer NOT NULL,
    ad text,
    ogretmen_id integer
);


ALTER TABLE public.ders OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 17169)
-- Name: ders_ders_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.ders_ders_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.ders_ders_id_seq OWNER TO postgres;

--
-- TOC entry 3062 (class 0 OID 0)
-- Dependencies: 214
-- Name: ders_ders_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.ders_ders_id_seq OWNED BY public.ders.ders_id;


--
-- TOC entry 205 (class 1259 OID 16885)
-- Name: egitmen_alan; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.egitmen_alan (
    egitmen_alan_id integer NOT NULL,
    ad text
);


ALTER TABLE public.egitmen_alan OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 16883)
-- Name: egitmen_alan_egitmen_alan_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.egitmen_alan_egitmen_alan_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.egitmen_alan_egitmen_alan_id_seq OWNER TO postgres;

--
-- TOC entry 3063 (class 0 OID 0)
-- Dependencies: 204
-- Name: egitmen_alan_egitmen_alan_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.egitmen_alan_egitmen_alan_id_seq OWNED BY public.egitmen_alan.egitmen_alan_id;


--
-- TOC entry 199 (class 1259 OID 16850)
-- Name: giris; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.giris (
    giris_id integer NOT NULL,
    kullanici_id integer,
    tarih date
);


ALTER TABLE public.giris OWNER TO postgres;

--
-- TOC entry 198 (class 1259 OID 16848)
-- Name: giris_giris_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.giris_giris_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.giris_giris_id_seq OWNER TO postgres;

--
-- TOC entry 3064 (class 0 OID 0)
-- Dependencies: 198
-- Name: giris_giris_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.giris_giris_id_seq OWNED BY public.giris.giris_id;


--
-- TOC entry 228 (class 1259 OID 17393)
-- Name: kayit_kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kayit_kullanici (
    kayit_id integer NOT NULL,
    kullanici_id integer,
    parola text,
    tarih timestamp(6) without time zone
);


ALTER TABLE public.kayit_kullanici OWNER TO postgres;

--
-- TOC entry 227 (class 1259 OID 17391)
-- Name: kayit_kullanici_kayit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.kayit_kullanici_kayit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.kayit_kullanici_kayit_id_seq OWNER TO postgres;

--
-- TOC entry 3065 (class 0 OID 0)
-- Dependencies: 227
-- Name: kayit_kullanici_kayit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.kayit_kullanici_kayit_id_seq OWNED BY public.kayit_kullanici.kayit_id;


--
-- TOC entry 230 (class 1259 OID 17424)
-- Name: kayit_ogrenci; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kayit_ogrenci (
    kayit_id integer NOT NULL,
    ogrenci_id integer,
    bolum_id integer,
    tarih timestamp(6) without time zone
);


ALTER TABLE public.kayit_ogrenci OWNER TO postgres;

--
-- TOC entry 229 (class 1259 OID 17422)
-- Name: kayit_ogrenci_kayit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.kayit_ogrenci_kayit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.kayit_ogrenci_kayit_id_seq OWNER TO postgres;

--
-- TOC entry 3066 (class 0 OID 0)
-- Dependencies: 229
-- Name: kayit_ogrenci_kayit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.kayit_ogrenci_kayit_id_seq OWNED BY public.kayit_ogrenci.kayit_id;


--
-- TOC entry 236 (class 1259 OID 17456)
-- Name: kayit_ogretmen; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kayit_ogretmen (
    kayit_id integer NOT NULL,
    ogretmen_id integer,
    bolum_id integer,
    tarih timestamp(6) without time zone
);


ALTER TABLE public.kayit_ogretmen OWNER TO postgres;

--
-- TOC entry 235 (class 1259 OID 17454)
-- Name: kayit_ogretmen_kayit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.kayit_ogretmen_kayit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.kayit_ogretmen_kayit_id_seq OWNER TO postgres;

--
-- TOC entry 3067 (class 0 OID 0)
-- Dependencies: 235
-- Name: kayit_ogretmen_kayit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.kayit_ogretmen_kayit_id_seq OWNED BY public.kayit_ogretmen.kayit_id;


--
-- TOC entry 234 (class 1259 OID 17444)
-- Name: kayit_personel; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kayit_personel (
    kayit_id integer NOT NULL,
    personel_id integer,
    personel_alan_id integer,
    tarih timestamp(6) without time zone
);


ALTER TABLE public.kayit_personel OWNER TO postgres;

--
-- TOC entry 233 (class 1259 OID 17442)
-- Name: kayit_personel_kayit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.kayit_personel_kayit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.kayit_personel_kayit_id_seq OWNER TO postgres;

--
-- TOC entry 3068 (class 0 OID 0)
-- Dependencies: 233
-- Name: kayit_personel_kayit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.kayit_personel_kayit_id_seq OWNED BY public.kayit_personel.kayit_id;


--
-- TOC entry 232 (class 1259 OID 17434)
-- Name: kayit_yonetim; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kayit_yonetim (
    kayit_id integer NOT NULL,
    yonetim_id integer,
    yonetim_tur_id integer,
    tarih timestamp(6) without time zone
);


ALTER TABLE public.kayit_yonetim OWNER TO postgres;

--
-- TOC entry 231 (class 1259 OID 17432)
-- Name: kayit_yonetim_kayit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.kayit_yonetim_kayit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.kayit_yonetim_kayit_id_seq OWNER TO postgres;

--
-- TOC entry 3069 (class 0 OID 0)
-- Dependencies: 231
-- Name: kayit_yonetim_kayit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.kayit_yonetim_kayit_id_seq OWNED BY public.kayit_yonetim.kayit_id;


--
-- TOC entry 216 (class 1259 OID 17243)
-- Name: kisi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kisi (
    tcno text,
    ad text,
    soyad text,
    telno text,
    eposta text,
    adres text
);


ALTER TABLE public.kisi OWNER TO postgres;

--
-- TOC entry 197 (class 1259 OID 16839)
-- Name: kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kullanici (
    kullanici_id integer NOT NULL,
    kullanici_ad text,
    parola text
);


ALTER TABLE public.kullanici OWNER TO postgres;

--
-- TOC entry 196 (class 1259 OID 16837)
-- Name: kullanici_kullanici_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.kullanici_kullanici_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.kullanici_kullanici_id_seq OWNER TO postgres;

--
-- TOC entry 3070 (class 0 OID 0)
-- Dependencies: 196
-- Name: kullanici_kullanici_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.kullanici_kullanici_id_seq OWNED BY public.kullanici.kullanici_id;


--
-- TOC entry 211 (class 1259 OID 17080)
-- Name: nobet; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.nobet (
    nobet_id integer NOT NULL,
    ogrenci_id integer,
    tarih text
);


ALTER TABLE public.nobet OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 17078)
-- Name: nobet_nobet_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.nobet_nobet_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.nobet_nobet_id_seq OWNER TO postgres;

--
-- TOC entry 3071 (class 0 OID 0)
-- Dependencies: 210
-- Name: nobet_nobet_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.nobet_nobet_id_seq OWNED BY public.nobet.nobet_id;


--
-- TOC entry 218 (class 1259 OID 17278)
-- Name: ogrenci; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ogrenci (
    ogrenci_id integer NOT NULL,
    bolum_id integer,
    sinif_id integer
)
INHERITS (public.kisi);


ALTER TABLE public.ogrenci OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 17276)
-- Name: ogrenci_ogrenci_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.ogrenci_ogrenci_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.ogrenci_ogrenci_id_seq OWNER TO postgres;

--
-- TOC entry 3072 (class 0 OID 0)
-- Dependencies: 217
-- Name: ogrenci_ogrenci_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.ogrenci_ogrenci_id_seq OWNED BY public.ogrenci.ogrenci_id;


--
-- TOC entry 220 (class 1259 OID 17299)
-- Name: ogretmen; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ogretmen (
    ogretmen_id integer NOT NULL,
    bolum_id integer,
    egitmen_alan_id integer
)
INHERITS (public.kisi);


ALTER TABLE public.ogretmen OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 17297)
-- Name: ogretmen_ogretmen_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.ogretmen_ogretmen_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.ogretmen_ogretmen_id_seq OWNER TO postgres;

--
-- TOC entry 3073 (class 0 OID 0)
-- Dependencies: 219
-- Name: ogretmen_ogretmen_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.ogretmen_ogretmen_id_seq OWNED BY public.ogretmen.ogretmen_id;


--
-- TOC entry 224 (class 1259 OID 17347)
-- Name: personel; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personel (
    personel_id integer NOT NULL,
    personel_alan_id integer
)
INHERITS (public.kisi);


ALTER TABLE public.personel OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 16907)
-- Name: personel_alan; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personel_alan (
    personel_alan_id integer NOT NULL,
    ad text
);


ALTER TABLE public.personel_alan OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 16905)
-- Name: personel_alan_personel_alan_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personel_alan_personel_alan_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personel_alan_personel_alan_id_seq OWNER TO postgres;

--
-- TOC entry 3074 (class 0 OID 0)
-- Dependencies: 208
-- Name: personel_alan_personel_alan_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personel_alan_personel_alan_id_seq OWNED BY public.personel_alan.personel_alan_id;


--
-- TOC entry 223 (class 1259 OID 17345)
-- Name: personel_personel_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personel_personel_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personel_personel_id_seq OWNER TO postgres;

--
-- TOC entry 3075 (class 0 OID 0)
-- Dependencies: 223
-- Name: personel_personel_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personel_personel_id_seq OWNED BY public.personel.personel_id;


--
-- TOC entry 201 (class 1259 OID 16863)
-- Name: sinif; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sinif (
    sinif_id integer NOT NULL,
    ad text
);


ALTER TABLE public.sinif OWNER TO postgres;

--
-- TOC entry 200 (class 1259 OID 16861)
-- Name: sinif_sinif_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.sinif_sinif_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.sinif_sinif_id_seq OWNER TO postgres;

--
-- TOC entry 3076 (class 0 OID 0)
-- Dependencies: 200
-- Name: sinif_sinif_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.sinif_sinif_id_seq OWNED BY public.sinif.sinif_id;


--
-- TOC entry 226 (class 1259 OID 17363)
-- Name: veli; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.veli (
    veli_id integer NOT NULL,
    ogrenci_id integer
)
INHERITS (public.kisi);


ALTER TABLE public.veli OWNER TO postgres;

--
-- TOC entry 225 (class 1259 OID 17361)
-- Name: veli_veli_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.veli_veli_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.veli_veli_id_seq OWNER TO postgres;

--
-- TOC entry 3077 (class 0 OID 0)
-- Dependencies: 225
-- Name: veli_veli_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.veli_veli_id_seq OWNED BY public.veli.veli_id;


--
-- TOC entry 222 (class 1259 OID 17320)
-- Name: yonetim; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.yonetim (
    yonetim_id integer NOT NULL,
    bolum_id integer,
    egitmen_alan_id integer,
    yonetim_tur_id integer
)
INHERITS (public.kisi);


ALTER TABLE public.yonetim OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 16896)
-- Name: yonetim_tur; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.yonetim_tur (
    yonetim_tur_id integer NOT NULL,
    ad text
);


ALTER TABLE public.yonetim_tur OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 16894)
-- Name: yonetim_tur_yonetim_tur_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.yonetim_tur_yonetim_tur_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.yonetim_tur_yonetim_tur_id_seq OWNER TO postgres;

--
-- TOC entry 3078 (class 0 OID 0)
-- Dependencies: 206
-- Name: yonetim_tur_yonetim_tur_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.yonetim_tur_yonetim_tur_id_seq OWNED BY public.yonetim_tur.yonetim_tur_id;


--
-- TOC entry 221 (class 1259 OID 17318)
-- Name: yonetim_yonetim_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.yonetim_yonetim_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.yonetim_yonetim_id_seq OWNER TO postgres;

--
-- TOC entry 3079 (class 0 OID 0)
-- Dependencies: 221
-- Name: yonetim_yonetim_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.yonetim_yonetim_id_seq OWNED BY public.yonetim.yonetim_id;


--
-- TOC entry 2823 (class 2604 OID 17096)
-- Name: aile_birligi aile_birligi_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.aile_birligi ALTER COLUMN aile_birligi_id SET DEFAULT nextval('public.aile_birligi_aile_birligi_id_seq'::regclass);


--
-- TOC entry 2818 (class 2604 OID 16877)
-- Name: bolum bolum_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum ALTER COLUMN bolum_id SET DEFAULT nextval('public.bolum_bolum_id_seq'::regclass);


--
-- TOC entry 2824 (class 2604 OID 17174)
-- Name: ders ders_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ders ALTER COLUMN ders_id SET DEFAULT nextval('public.ders_ders_id_seq'::regclass);


--
-- TOC entry 2819 (class 2604 OID 16888)
-- Name: egitmen_alan egitmen_alan_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.egitmen_alan ALTER COLUMN egitmen_alan_id SET DEFAULT nextval('public.egitmen_alan_egitmen_alan_id_seq'::regclass);


--
-- TOC entry 2816 (class 2604 OID 16853)
-- Name: giris giris_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.giris ALTER COLUMN giris_id SET DEFAULT nextval('public.giris_giris_id_seq'::regclass);


--
-- TOC entry 2830 (class 2604 OID 17396)
-- Name: kayit_kullanici kayit_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_kullanici ALTER COLUMN kayit_id SET DEFAULT nextval('public.kayit_kullanici_kayit_id_seq'::regclass);


--
-- TOC entry 2831 (class 2604 OID 17427)
-- Name: kayit_ogrenci kayit_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_ogrenci ALTER COLUMN kayit_id SET DEFAULT nextval('public.kayit_ogrenci_kayit_id_seq'::regclass);


--
-- TOC entry 2834 (class 2604 OID 17459)
-- Name: kayit_ogretmen kayit_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_ogretmen ALTER COLUMN kayit_id SET DEFAULT nextval('public.kayit_ogretmen_kayit_id_seq'::regclass);


--
-- TOC entry 2833 (class 2604 OID 17447)
-- Name: kayit_personel kayit_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_personel ALTER COLUMN kayit_id SET DEFAULT nextval('public.kayit_personel_kayit_id_seq'::regclass);


--
-- TOC entry 2832 (class 2604 OID 17437)
-- Name: kayit_yonetim kayit_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_yonetim ALTER COLUMN kayit_id SET DEFAULT nextval('public.kayit_yonetim_kayit_id_seq'::regclass);


--
-- TOC entry 2815 (class 2604 OID 16842)
-- Name: kullanici kullanici_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kullanici ALTER COLUMN kullanici_id SET DEFAULT nextval('public.kullanici_kullanici_id_seq'::regclass);


--
-- TOC entry 2822 (class 2604 OID 17083)
-- Name: nobet nobet_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.nobet ALTER COLUMN nobet_id SET DEFAULT nextval('public.nobet_nobet_id_seq'::regclass);


--
-- TOC entry 2825 (class 2604 OID 17281)
-- Name: ogrenci ogrenci_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci ALTER COLUMN ogrenci_id SET DEFAULT nextval('public.ogrenci_ogrenci_id_seq'::regclass);


--
-- TOC entry 2826 (class 2604 OID 17302)
-- Name: ogretmen ogretmen_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen ALTER COLUMN ogretmen_id SET DEFAULT nextval('public.ogretmen_ogretmen_id_seq'::regclass);


--
-- TOC entry 2828 (class 2604 OID 17350)
-- Name: personel personel_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personel ALTER COLUMN personel_id SET DEFAULT nextval('public.personel_personel_id_seq'::regclass);


--
-- TOC entry 2821 (class 2604 OID 16910)
-- Name: personel_alan personel_alan_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personel_alan ALTER COLUMN personel_alan_id SET DEFAULT nextval('public.personel_alan_personel_alan_id_seq'::regclass);


--
-- TOC entry 2817 (class 2604 OID 16866)
-- Name: sinif sinif_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sinif ALTER COLUMN sinif_id SET DEFAULT nextval('public.sinif_sinif_id_seq'::regclass);


--
-- TOC entry 2829 (class 2604 OID 17366)
-- Name: veli veli_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.veli ALTER COLUMN veli_id SET DEFAULT nextval('public.veli_veli_id_seq'::regclass);


--
-- TOC entry 2827 (class 2604 OID 17323)
-- Name: yonetim yonetim_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim ALTER COLUMN yonetim_id SET DEFAULT nextval('public.yonetim_yonetim_id_seq'::regclass);


--
-- TOC entry 2820 (class 2604 OID 16899)
-- Name: yonetim_tur yonetim_tur_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim_tur ALTER COLUMN yonetim_tur_id SET DEFAULT nextval('public.yonetim_tur_yonetim_tur_id_seq'::regclass);


--
-- TOC entry 3028 (class 0 OID 17093)
-- Dependencies: 213
-- Data for Name: aile_birligi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.aile_birligi (aile_birligi_id, veli_id) FROM stdin;
1	1
\.


--
-- TOC entry 3018 (class 0 OID 16874)
-- Dependencies: 203
-- Data for Name: bolum; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.bolum (bolum_id, ad) FROM stdin;
5	bilgisayar
6	eşit ağırlık
\.


--
-- TOC entry 3030 (class 0 OID 17171)
-- Dependencies: 215
-- Data for Name: ders; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ders (ders_id, ad, ogretmen_id) FROM stdin;
3	denemeders	2
4	asdasd	1
5	abc	1
6	dfg	1
7	ljk	1
\.


--
-- TOC entry 3020 (class 0 OID 16885)
-- Dependencies: 205
-- Data for Name: egitmen_alan; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.egitmen_alan (egitmen_alan_id, ad) FROM stdin;
1	Fizik
2	Biyoloji
3	Matematik
\.


--
-- TOC entry 3014 (class 0 OID 16850)
-- Dependencies: 199
-- Data for Name: giris; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.giris (giris_id, kullanici_id, tarih) FROM stdin;
1	1	2020-08-05
2	1	2020-08-05
3	1	2020-08-05
4	1	2020-08-05
5	1	2020-08-05
\.


--
-- TOC entry 3043 (class 0 OID 17393)
-- Dependencies: 228
-- Data for Name: kayit_kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kayit_kullanici (kayit_id, kullanici_id, parola, tarih) FROM stdin;
1	1	123456	2020-08-05 17:31:13.2861
\.


--
-- TOC entry 3045 (class 0 OID 17424)
-- Dependencies: 230
-- Data for Name: kayit_ogrenci; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kayit_ogrenci (kayit_id, ogrenci_id, bolum_id, tarih) FROM stdin;
1	1	5	2020-08-05 17:55:29.79867
\.


--
-- TOC entry 3051 (class 0 OID 17456)
-- Dependencies: 236
-- Data for Name: kayit_ogretmen; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kayit_ogretmen (kayit_id, ogretmen_id, bolum_id, tarih) FROM stdin;
1	3	5	2020-08-05 18:05:26.841961
\.


--
-- TOC entry 3049 (class 0 OID 17444)
-- Dependencies: 234
-- Data for Name: kayit_personel; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kayit_personel (kayit_id, personel_id, personel_alan_id, tarih) FROM stdin;
1	1	1	2020-08-05 18:01:44.272324
\.


--
-- TOC entry 3047 (class 0 OID 17434)
-- Dependencies: 232
-- Data for Name: kayit_yonetim; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kayit_yonetim (kayit_id, yonetim_id, yonetim_tur_id, tarih) FROM stdin;
1	1	2	2020-08-05 17:59:10.026295
\.


--
-- TOC entry 3031 (class 0 OID 17243)
-- Dependencies: 216
-- Data for Name: kisi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kisi (tcno, ad, soyad, telno, eposta, adres) FROM stdin;
\.


--
-- TOC entry 3012 (class 0 OID 16839)
-- Dependencies: 197
-- Data for Name: kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kullanici (kullanici_id, kullanici_ad, parola) FROM stdin;
1	admin	012345
\.


--
-- TOC entry 3026 (class 0 OID 17080)
-- Dependencies: 211
-- Data for Name: nobet; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.nobet (nobet_id, ogrenci_id, tarih) FROM stdin;
1	1	05.08.2020
\.


--
-- TOC entry 3033 (class 0 OID 17278)
-- Dependencies: 218
-- Data for Name: ogrenci; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ogrenci (tcno, ad, soyad, telno, eposta, adres, ogrenci_id, bolum_id, sinif_id) FROM stdin;
32423423423	ayhan	pek	(555) 555-5555	mail	adres	1	6	1
\.


--
-- TOC entry 3035 (class 0 OID 17299)
-- Dependencies: 220
-- Data for Name: ogretmen; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ogretmen (tcno, ad, soyad, telno, eposta, adres, ogretmen_id, bolum_id, egitmen_alan_id) FROM stdin;
34444444442	Şafak	Sezer	(555) 555-5555	mail@mail.com	Adres	3	6	2
\.


--
-- TOC entry 3039 (class 0 OID 17347)
-- Dependencies: 224
-- Data for Name: personel; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personel (tcno, ad, soyad, telno, eposta, adres, personel_id, personel_alan_id) FROM stdin;
44444444444	Şevket	Yerimdar	(453) 453-4534	mail@mail	mahalle	1	2
\.


--
-- TOC entry 3024 (class 0 OID 16907)
-- Dependencies: 209
-- Data for Name: personel_alan; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personel_alan (personel_alan_id, ad) FROM stdin;
1	Temizlik Görevlisi
2	Bekçi
3	Güvenlik
\.


--
-- TOC entry 3016 (class 0 OID 16863)
-- Dependencies: 201
-- Data for Name: sinif; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.sinif (sinif_id, ad) FROM stdin;
1	5A
2	6E
3	1B
4	4J
\.


--
-- TOC entry 3041 (class 0 OID 17363)
-- Dependencies: 226
-- Data for Name: veli; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.veli (tcno, ad, soyad, telno, eposta, adres, veli_id, ogrenci_id) FROM stdin;
41654654654	Seda	Pek	(555) 555-5555	mail@mail.com	adres	1	1
\.


--
-- TOC entry 3037 (class 0 OID 17320)
-- Dependencies: 222
-- Data for Name: yonetim; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.yonetim (tcno, ad, soyad, telno, eposta, adres, yonetim_id, bolum_id, egitmen_alan_id, yonetim_tur_id) FROM stdin;
32424234234	Halit	Akça	(555) 555-5555	mail@mail	maasdasd	1	5	3	1
\.


--
-- TOC entry 3022 (class 0 OID 16896)
-- Dependencies: 207
-- Data for Name: yonetim_tur; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.yonetim_tur (yonetim_tur_id, ad) FROM stdin;
1	Müdür
2	Müdür Yardımcısı
\.


--
-- TOC entry 3080 (class 0 OID 0)
-- Dependencies: 212
-- Name: aile_birligi_aile_birligi_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.aile_birligi_aile_birligi_id_seq', 1, true);


--
-- TOC entry 3081 (class 0 OID 0)
-- Dependencies: 202
-- Name: bolum_bolum_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.bolum_bolum_id_seq', 6, true);


--
-- TOC entry 3082 (class 0 OID 0)
-- Dependencies: 214
-- Name: ders_ders_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.ders_ders_id_seq', 7, true);


--
-- TOC entry 3083 (class 0 OID 0)
-- Dependencies: 204
-- Name: egitmen_alan_egitmen_alan_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.egitmen_alan_egitmen_alan_id_seq', 3, true);


--
-- TOC entry 3084 (class 0 OID 0)
-- Dependencies: 198
-- Name: giris_giris_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.giris_giris_id_seq', 5, true);


--
-- TOC entry 3085 (class 0 OID 0)
-- Dependencies: 227
-- Name: kayit_kullanici_kayit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.kayit_kullanici_kayit_id_seq', 1, true);


--
-- TOC entry 3086 (class 0 OID 0)
-- Dependencies: 229
-- Name: kayit_ogrenci_kayit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.kayit_ogrenci_kayit_id_seq', 1, true);


--
-- TOC entry 3087 (class 0 OID 0)
-- Dependencies: 235
-- Name: kayit_ogretmen_kayit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.kayit_ogretmen_kayit_id_seq', 1, true);


--
-- TOC entry 3088 (class 0 OID 0)
-- Dependencies: 233
-- Name: kayit_personel_kayit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.kayit_personel_kayit_id_seq', 1, true);


--
-- TOC entry 3089 (class 0 OID 0)
-- Dependencies: 231
-- Name: kayit_yonetim_kayit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.kayit_yonetim_kayit_id_seq', 1, true);


--
-- TOC entry 3090 (class 0 OID 0)
-- Dependencies: 196
-- Name: kullanici_kullanici_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.kullanici_kullanici_id_seq', 3, true);


--
-- TOC entry 3091 (class 0 OID 0)
-- Dependencies: 210
-- Name: nobet_nobet_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.nobet_nobet_id_seq', 1, true);


--
-- TOC entry 3092 (class 0 OID 0)
-- Dependencies: 217
-- Name: ogrenci_ogrenci_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.ogrenci_ogrenci_id_seq', 1, true);


--
-- TOC entry 3093 (class 0 OID 0)
-- Dependencies: 219
-- Name: ogretmen_ogretmen_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.ogretmen_ogretmen_id_seq', 3, true);


--
-- TOC entry 3094 (class 0 OID 0)
-- Dependencies: 208
-- Name: personel_alan_personel_alan_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personel_alan_personel_alan_id_seq', 3, true);


--
-- TOC entry 3095 (class 0 OID 0)
-- Dependencies: 223
-- Name: personel_personel_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personel_personel_id_seq', 1, true);


--
-- TOC entry 3096 (class 0 OID 0)
-- Dependencies: 200
-- Name: sinif_sinif_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.sinif_sinif_id_seq', 6, true);


--
-- TOC entry 3097 (class 0 OID 0)
-- Dependencies: 225
-- Name: veli_veli_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.veli_veli_id_seq', 1, true);


--
-- TOC entry 3098 (class 0 OID 0)
-- Dependencies: 206
-- Name: yonetim_tur_yonetim_tur_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.yonetim_tur_yonetim_tur_id_seq', 2, true);


--
-- TOC entry 3099 (class 0 OID 0)
-- Dependencies: 221
-- Name: yonetim_yonetim_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.yonetim_yonetim_id_seq', 1, true);


--
-- TOC entry 2852 (class 2606 OID 17098)
-- Name: aile_birligi aile_birligi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.aile_birligi
    ADD CONSTRAINT aile_birligi_pkey PRIMARY KEY (aile_birligi_id);


--
-- TOC entry 2842 (class 2606 OID 16882)
-- Name: bolum bolum_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum
    ADD CONSTRAINT bolum_pkey PRIMARY KEY (bolum_id);


--
-- TOC entry 2854 (class 2606 OID 17179)
-- Name: ders ders_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ders
    ADD CONSTRAINT ders_pkey PRIMARY KEY (ders_id);


--
-- TOC entry 2844 (class 2606 OID 16893)
-- Name: egitmen_alan egitmen_alan_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.egitmen_alan
    ADD CONSTRAINT egitmen_alan_pkey PRIMARY KEY (egitmen_alan_id);


--
-- TOC entry 2838 (class 2606 OID 16855)
-- Name: giris giris_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.giris
    ADD CONSTRAINT giris_pkey PRIMARY KEY (giris_id);


--
-- TOC entry 2866 (class 2606 OID 17401)
-- Name: kayit_kullanici kayit_kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_kullanici
    ADD CONSTRAINT kayit_kullanici_pkey PRIMARY KEY (kayit_id);


--
-- TOC entry 2868 (class 2606 OID 17429)
-- Name: kayit_ogrenci kayit_ogrenci_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_ogrenci
    ADD CONSTRAINT kayit_ogrenci_pkey PRIMARY KEY (kayit_id);


--
-- TOC entry 2874 (class 2606 OID 17461)
-- Name: kayit_ogretmen kayit_ogretmen_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_ogretmen
    ADD CONSTRAINT kayit_ogretmen_pkey PRIMARY KEY (kayit_id);


--
-- TOC entry 2872 (class 2606 OID 17449)
-- Name: kayit_personel kayit_personel_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_personel
    ADD CONSTRAINT kayit_personel_pkey PRIMARY KEY (kayit_id);


--
-- TOC entry 2870 (class 2606 OID 17439)
-- Name: kayit_yonetim kayit_yonetim_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kayit_yonetim
    ADD CONSTRAINT kayit_yonetim_pkey PRIMARY KEY (kayit_id);


--
-- TOC entry 2836 (class 2606 OID 16847)
-- Name: kullanici kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kullanici
    ADD CONSTRAINT kullanici_pkey PRIMARY KEY (kullanici_id);


--
-- TOC entry 2850 (class 2606 OID 17085)
-- Name: nobet nobet_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.nobet
    ADD CONSTRAINT nobet_pkey PRIMARY KEY (nobet_id);


--
-- TOC entry 2856 (class 2606 OID 17286)
-- Name: ogrenci ogrenci_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT ogrenci_pkey PRIMARY KEY (ogrenci_id);


--
-- TOC entry 2858 (class 2606 OID 17307)
-- Name: ogretmen ogretmen_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT ogretmen_pkey PRIMARY KEY (ogretmen_id);


--
-- TOC entry 2848 (class 2606 OID 16915)
-- Name: personel_alan personel_alan_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personel_alan
    ADD CONSTRAINT personel_alan_pkey PRIMARY KEY (personel_alan_id);


--
-- TOC entry 2862 (class 2606 OID 17355)
-- Name: personel personel_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personel
    ADD CONSTRAINT personel_pkey PRIMARY KEY (personel_id);


--
-- TOC entry 2840 (class 2606 OID 16871)
-- Name: sinif sinif_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sinif
    ADD CONSTRAINT sinif_pkey PRIMARY KEY (sinif_id);


--
-- TOC entry 2864 (class 2606 OID 17371)
-- Name: veli veli_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.veli
    ADD CONSTRAINT veli_pkey PRIMARY KEY (veli_id);


--
-- TOC entry 2860 (class 2606 OID 17328)
-- Name: yonetim yonetim_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim
    ADD CONSTRAINT yonetim_pkey PRIMARY KEY (yonetim_id);


--
-- TOC entry 2846 (class 2606 OID 16904)
-- Name: yonetim_tur yonetim_tur_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim_tur
    ADD CONSTRAINT yonetim_tur_pkey PRIMARY KEY (yonetim_tur_id);


--
-- TOC entry 2887 (class 2620 OID 17464)
-- Name: ogretmen egitmen_bolum_degistirme; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER egitmen_bolum_degistirme BEFORE UPDATE ON public.ogretmen FOR EACH ROW EXECUTE PROCEDURE public.kayit_egitmen_bolum_degistirme();


--
-- TOC entry 2885 (class 2620 OID 17403)
-- Name: kullanici kullanici_parola_degistirme; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER kullanici_parola_degistirme BEFORE UPDATE ON public.kullanici FOR EACH ROW EXECUTE PROCEDURE public.kayit_kullanici_parola_degistirme();


--
-- TOC entry 2886 (class 2620 OID 17431)
-- Name: ogrenci ogrenci_bolum_degistirme; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER ogrenci_bolum_degistirme BEFORE UPDATE ON public.ogrenci FOR EACH ROW EXECUTE PROCEDURE public.kayit_ogrenci_bolum_degistirme();


--
-- TOC entry 2889 (class 2620 OID 17453)
-- Name: personel personel_alan_degistirme; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER personel_alan_degistirme BEFORE UPDATE ON public.personel FOR EACH ROW EXECUTE PROCEDURE public.kayit_personel_alan_degistirme();


--
-- TOC entry 2888 (class 2620 OID 17441)
-- Name: yonetim yonetim_tur_degistirme; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER yonetim_tur_degistirme BEFORE UPDATE ON public.yonetim FOR EACH ROW EXECUTE PROCEDURE public.kayit_yonetim_tur_degistirme();


--
-- TOC entry 2876 (class 2606 OID 17287)
-- Name: ogrenci fk_bolum; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT fk_bolum FOREIGN KEY (bolum_id) REFERENCES public.bolum(bolum_id);


--
-- TOC entry 2878 (class 2606 OID 17308)
-- Name: ogretmen fk_bolum; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT fk_bolum FOREIGN KEY (bolum_id) REFERENCES public.bolum(bolum_id);


--
-- TOC entry 2880 (class 2606 OID 17329)
-- Name: yonetim fk_bolum; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim
    ADD CONSTRAINT fk_bolum FOREIGN KEY (bolum_id) REFERENCES public.bolum(bolum_id);


--
-- TOC entry 2879 (class 2606 OID 17313)
-- Name: ogretmen fk_egitmen_alan; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT fk_egitmen_alan FOREIGN KEY (egitmen_alan_id) REFERENCES public.egitmen_alan(egitmen_alan_id);


--
-- TOC entry 2881 (class 2606 OID 17334)
-- Name: yonetim fk_egitmen_alan; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim
    ADD CONSTRAINT fk_egitmen_alan FOREIGN KEY (egitmen_alan_id) REFERENCES public.egitmen_alan(egitmen_alan_id);


--
-- TOC entry 2875 (class 2606 OID 16856)
-- Name: giris fk_kullanici; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.giris
    ADD CONSTRAINT fk_kullanici FOREIGN KEY (kullanici_id) REFERENCES public.kullanici(kullanici_id);


--
-- TOC entry 2884 (class 2606 OID 17372)
-- Name: veli fk_ogrenci; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.veli
    ADD CONSTRAINT fk_ogrenci FOREIGN KEY (ogrenci_id) REFERENCES public.ogrenci(ogrenci_id);


--
-- TOC entry 2883 (class 2606 OID 17356)
-- Name: personel fk_personel_alan; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personel
    ADD CONSTRAINT fk_personel_alan FOREIGN KEY (personel_alan_id) REFERENCES public.personel_alan(personel_alan_id);


--
-- TOC entry 2877 (class 2606 OID 17292)
-- Name: ogrenci fk_sinif; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT fk_sinif FOREIGN KEY (sinif_id) REFERENCES public.sinif(sinif_id);


--
-- TOC entry 2882 (class 2606 OID 17339)
-- Name: yonetim fk_yonetim_tur; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.yonetim
    ADD CONSTRAINT fk_yonetim_tur FOREIGN KEY (yonetim_tur_id) REFERENCES public.yonetim_tur(yonetim_tur_id);


-- Completed on 2020-08-05 18:09:43

--
-- PostgreSQL database dump complete
--

