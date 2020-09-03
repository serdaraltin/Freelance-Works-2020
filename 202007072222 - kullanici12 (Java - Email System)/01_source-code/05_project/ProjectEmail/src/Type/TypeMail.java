package Type;

public class TypeMail {
    private TypeBasicUser gonderen;
    private TypeBasicUser alan;
    private String konu;
    private String govde;

    public TypeBasicUser getGonderen() {
        return gonderen;
    }

    public void setGonderen(TypeBasicUser gonderen) {
        this.gonderen = gonderen;
    }

    public TypeBasicUser getAlan() {
        return alan;
    }

    public void setAlan(TypeBasicUser alan) {
        this.alan = alan;
    }

    public String getKonu() {
        return konu;
    }

    public void setKonu(String konu) {
        this.konu = konu;
    }

    public String getGovde() {
        return govde;
    }

    public void setGovde(String govde) {
        this.govde = govde;
    }

    public TypeMail(TypeBasicUser gonderen, TypeBasicUser alan, String konu, String govde) {
        this.gonderen = gonderen;
        this.alan = alan;
        this.konu = konu;
        this.govde = govde;
    }

    public TypeMail() {
    }

    @Override
    public String toString() {
        return "TypeMail{" + "gonderen=" + gonderen + ", alan=" + alan + ", konu=" + konu + ", govde=" + govde + '}';
    }

}
