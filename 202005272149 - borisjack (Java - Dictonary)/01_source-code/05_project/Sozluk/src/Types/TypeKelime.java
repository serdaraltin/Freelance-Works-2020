package Types;

public class TypeKelime {

    private int id;
    private String dil;
    private String kelime;
    private String ceviri;
    private String anlam;

    public TypeKelime(int id, String dil, String kelime, String ceviri, String anlam) {
        this.id = id;
        this.dil = dil;
        this.kelime = kelime;
        this.ceviri = ceviri;
        this.anlam = anlam;
    }

    public TypeKelime() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDil() {
        return dil;
    }

    public void setDil(String dil) {
        this.dil = dil;
    }

    public String getKelime() {
        return kelime;
    }

    public void setKelime(String kelime) {
        this.kelime = kelime;
    }

    public String getCeviri() {
        return ceviri;
    }

    public void setCeviri(String ceviri) {
        this.ceviri = ceviri;
    }

    public String getAnlam() {
        return anlam;
    }

    public void setAnlam(String anlam) {
        this.anlam = anlam;
    }

    @Override
    public String toString() {
        return "TypeKelime{" + "id=" + id + ", dil=" + dil + ", kelime=" + kelime + ", ceviri=" + ceviri + ", anlam=" + anlam + '}';
    }

 

}
