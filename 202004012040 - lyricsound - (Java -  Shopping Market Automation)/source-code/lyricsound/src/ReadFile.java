
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class ReadFile {

    public String[] readFile(String path) {

        int i = 0;
        int lenght;
        try {
            lenght = Files.readAllLines(Paths.get(path)).size();

            String[] results = new String[lenght];
            for (String line : Files.readAllLines(Paths.get(path))) {
                results[i++] = line;
            }
            return results;
        } catch (IOException ex) {
            ex.printStackTrace();
            return null;
        }

    }
}
