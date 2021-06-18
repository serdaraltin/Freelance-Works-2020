import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {
	/**
	 * in this function i read file and split line by line
	 * @param path 
	 * @return results
	 */
	
	public static String[] readFileMedicaments(String path){
		try {
		int i=0;
		int lenght= Files.readAllLines(Paths.get(path)).size();
		
		String[] results = new String[lenght];		
			for (String line : Files.readAllLines(Paths.get(path))) {
				
				results[i++]= line;			
			}
			
		return results;
		} catch(IOException e){
			e.printStackTrace();
			return null;	
		}
	
	}
	
	/**
	 * in this function i read the file and split line by line.
	 * @param path
	 * @return results
	 */
	public static String[] readFilePrescription(String path){
		try {
		int i=0;
		int lenght= Files.readAllLines(Paths.get(path)).size();
		
		String[] results = new String[lenght];		
			for (String line : Files.readAllLines(Paths.get(path))) {		
				results[i++]= line;				
			}
			
		return results;
		} catch(IOException e){
			e.printStackTrace();
			return null;
		}
	} 
	
	/**
	 * this is main function
	 * @param args
	 * @throws ParseException
	 */
	public static void main(String[] args) throws ParseException {
		/**
		 * i open 2 two dimensional array and split the lines of arguments according to tab.
		 * i add the splited strings to arrays
		 */
		String[] medicaments= readFileMedicaments(args[1]);
		String[] prescription=readFilePrescription(args[0]);
		
		String[][] medArray = new String [500][5];
		String[][] preArray = new String [500][3];
		for ( int i=0; i< medicaments.length; i++){
			String[] medSplited = medicaments[i].split("\\t+");
			medArray[i][0] = medSplited[0];
			medArray[i][1] = medSplited[1];
			medArray[i][2] = medSplited[2];
			medArray[i][3] = medSplited[3];
			medArray[i][4] = medSplited[4];
		
		}
		for (int k=0; k< prescription.length ; k++){
			
		String[] preSplited = prescription[k].split("\\t+");
		if (preSplited.length==3){
			preArray[k][0] = preSplited[0];
			preArray[k][1] = preSplited[1];
			preArray[k][2] = preSplited[2];
		}
		else{
			preArray[k][0] = preSplited[0];
			preArray[k][1] = preSplited[1];
		}
			
		}
		String sgk=preArray[0][1];
		/**
		 * in this part i parse the date and compare the what is given us
		 */
		ArrayList<Float> Costs = new ArrayList<Float>();
		
		for (int x=1;x<prescription.length; x++){
			
			ArrayList<Float> CostArray=new ArrayList<Float>();
			
			for (int y=0;y<medicaments.length; y++){
				
				SimpleDateFormat df = new SimpleDateFormat("dd.MM.yyyy");
				
				Date preDate = new Date();
				Date medFirstDate = new Date();
				Date medLastDate = new Date();
				preDate = df.parse(preArray[0][2]);
				medFirstDate = df.parse(medArray[y][2]);
				medLastDate = df.parse(medArray[y][3]);
				
				if (preArray[x][0].equals(medArray[y][0]) && sgk.equals(medArray[y][1]) && preDate.after(medFirstDate) && preDate.before(medLastDate) ){
					
					float aFloat = Float.parseFloat(medArray[y][4]);
					
					CostArray.add(aFloat);
										
					}
			}
			
			Float min = CostArray.get(0);
	        for (float i : CostArray){
	            min = min < i ? min : i;
	            
	            
	        }
	        Costs.add(min);
		}
		
		/**
		 * in this part i found the total cost and print it to console.
		 */
		float Total=0;
		
		for(int g=0; g<Costs.size(); g++){
			System.out.println(preArray[g+1][0] + "\t" + Costs.get(g) + "\t" 
		+ preArray[g+1][1] + "\t" + Float.parseFloat(preArray[g+1][1])*Costs.get(g));
			
			Total+=Float.parseFloat(preArray[g+1][1])*Costs.get(g);
			
		}
		String totalPoint = String.format("%.2f", Total);
		String comaToPoint = totalPoint.replace(",", ".");
		
		System.out.println("Total" + "\t" + comaToPoint );
	}
}