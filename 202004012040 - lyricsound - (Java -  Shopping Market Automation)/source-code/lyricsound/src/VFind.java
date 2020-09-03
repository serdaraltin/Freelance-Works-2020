
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class VFind {

    static SimpleDateFormat dateFormat = new SimpleDateFormat("dd.MM.yyyy");

    public static String[] valueFind(String[] input, String value, Date date) throws ParseException {

        for (String line : input) {
            String[] values = line.split("	");
            Date priceDate = dateFormat.parse(values[3]);
            if (line.contains(value) && date.compareTo(priceDate) < 0) {
                return values;
            }
        }
        return null;
    }
}
