
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class WriteFile{

    private Output output;

    public WriteFile(Output output) {
       this.output = output;
    }
    public WriteFile() {
       
    }

    public void WritePersonnel(Output output){
        try {
            String outputName = output.getPersonnel().getRegisterNumber()+".txt";
            File file = new File(outputName);
            file.createNewFile();
            FileWriter fileWriter = new FileWriter(outputName);
            fileWriter.write(output.toString());
            fileWriter.close();
        } catch (IOException ex) {
            Logger.getLogger(WriteFile.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public Output getOutput() {
        return output;
    }

    public void setOutput(Output output) {
        this.output = output;
    }
}
