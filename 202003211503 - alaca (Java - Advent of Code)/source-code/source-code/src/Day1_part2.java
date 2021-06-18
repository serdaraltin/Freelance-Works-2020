
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Day1_part2 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Which input file: ");
		String fileLoc = scn.nextLine();
		try {
			List<Integer> allResults = new ArrayList<Integer>();

			int total = 0;
			int lineNumber = 0;
			System.out.println("Processing");
			while (true) 
			{
				BufferedReader br = new BufferedReader(new FileReader(fileLoc));
				String line;

				while ((line = br.readLine()) != null) {

					total += Integer.parseInt(line);
					if (allResults.contains(total)) 
					{
						System.out.println();
						System.out.println("Result: " + total);
						System.exit(0);
					}
					allResults.add(total);
					System.out.println(lineNumber + ":\t" + line + "\t->\t" + total);
					lineNumber++;
				}
				br.close();
			}
		} 
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}

	}
}
