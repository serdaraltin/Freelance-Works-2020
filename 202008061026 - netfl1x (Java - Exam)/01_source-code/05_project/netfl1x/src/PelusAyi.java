public class PelusAyi extends Oyuncak{
    private String kumasTipi;
    
    public PelusAyi(String kumasTipi, int secim) {
        super(secim);
        this.kumasTipi = kumasTipi;
    }

    public String getKumasTipi() {
        return kumasTipi;
    }

    public void setKumasTipi(String kumasTipi) {
        this.kumasTipi = kumasTipi;
    }

    @Override
    public String toString() {
        return "PelusAyi{" + "kumasTipi=" + kumasTipi + '}';
    }
    
    
}
